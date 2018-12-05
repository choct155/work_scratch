package com.stronghold


trait HistoryTree {
  val time: Option[Time]
  val value: Option[Any]
  def addValue(elem: HTree): HTree
  def nodeAtTime(t: Time): HistoryTree
  def containsTimeAtChange(t: Time): Boolean
  def filter(p: HistoryTree => Boolean): HistoryTree
  def filterAcc(p: HistoryTree => Boolean, oldTree: HistoryTree): HistoryTree
  def foreach(f: Time => Unit): Unit
}

class EmptyHTree extends HistoryTree {
  val time: Option[Time] = None
  val value: Option[Any] = None
  def addValue(elem: HTree): HTree = elem
  def nodeAtTime(t: Time): EmptyHTree = this
  def containsTimeAtChange(t: Time): Boolean = false
  def filter(p: HistoryTree => Boolean): HistoryTree = new EmptyHTree
  def filterAcc(p: HistoryTree => Boolean, oldTree: HistoryTree): HistoryTree = new EmptyHTree
  def foreach(f: Time => Unit): Unit = {}
  override def toString: String = "."
}

class HTree(_time: Option[Time], _value: Option[Any],
            left: HistoryTree = new EmptyHTree, right: HistoryTree = new EmptyHTree) extends HistoryTree {
  val time: Option[Time] = _time
  val value: Option[Any] = _value

  /* Getting weird NoSuchMethod exceptions
  def compare(thatTree: HistoryTree): Int = this match {
    case lt if this.time < thatTree.time => -1
    case gt if this.time > thatTree.time => 1
    case _ => 0
  }
  */

  /**
    * Inclusion is driven by the time period for a given value. Earlier times proceed in the
    * left child of a given tree node, while later times proceed in the right child. Note that
    * because we are talking about the changing state of a single attribute, each time period
    * can only be represented once. Trying to include the same elem (defined isomorphically as
    * having the same time and value) twice results in simply returning the node itself. Trying
    * to add a different value at the same time causes an IllegalArgumentException.
    * @param elem
    * @return
    */
  def addValue(elem: HTree): HTree = {
    // The interaction of time and value relationships drives the content of the added node
    val sameValEarlierTime: Boolean = (elem.value == this.value) && (elem.time < this.time)
    val sameValLaterTime: Boolean = (elem.value == this.value) && (elem.time > this.time)
    val sameValSameTime: Boolean = (elem.value == this.value) && (elem.time == this.time)
    val diffValEarlierTime: Boolean = (elem.value != this.value) && (elem.time < this.time)
    val diffValLaterTime: Boolean = (elem.value != this.value) && (elem.time > this.time)
    val diffValSameTime: Boolean = (elem.value != this.value) && (elem.time == this.time)

    elem match {
      case se if sameValEarlierTime => new HTree(elem.time, this.value, new EmptyHTree, new EmptyHTree)
      case sl if sameValLaterTime => this
      case ss if sameValSameTime => this
      case de if diffValEarlierTime => new HTree(this.time, this.value, this.left.addValue(elem), new EmptyHTree)
      case dl if diffValLaterTime => new HTree(this.time, this.value, new EmptyHTree, this.right.addValue(elem))
      case ds if diffValSameTime => throw new IllegalArgumentException
    }
  }

  def nodeAtTime(t: Time): HistoryTree = t match {
    // If the right child is nonempty, then we want to return this.value when right's time is after the query time.
    // However, if it empty, and None is always less than Some(val), it's the same as saying there were no attribute
    // state changes until now, and we still want to return this.value (hence the ugly getOrElse)
    case foundTimeRange if (this.time <= Option(t)) && (this.right.time.getOrElse(Time(999999)) > t) => this
    case earlierTimeRange if this.time > Option(t) => this.left.nodeAtTime(t)
    // Since we took care of the right child empty case in `foundTimeRange`, this should resolve correctly (w/o Nones)
    case laterTimeRange if this.right.time <= Option(t) => this.right.nodeAtTime(t)
  }

  def valueAtTime(t: Time): Option[Any] = nodeAtTime(t).value

  // filter out next elem that has the same value and a later time
  // rebuild the tree, sticking the updated node in when it's time is earlier than the child to be added
  /*
    1. Extend start time for earliest range for a value
    2. Extend start time for last range for a value
    3. Extend range between spells, knowing that start times of intervening states must be present

  In general, only start times are adjusted
   */
  def containsTimeAtChange(t: Time): Boolean = t match {
    case foundTime if t == this.time.get => true
    case timeInRange if (t > this.time.get) && (t < this.right.time.get) => false
    case lessThan if t < this.time.get => this.left.containsTimeAtChange(t)
    case greaterThan if t > this.time.get => this.right.containsTimeAtChange(t)
  }
  def contains(elem: HTree): Boolean = {
    nodeAtTime(elem.time.get).value == elem.value
  }
  def nextTimeNodeForValue(t: Time, v: Any): HTree = ???

  def foreach(f: Time => Unit): Unit = {
    f(this.time.get)
    this.left.foreach(f)
    this.right.foreach(f)
  }

  // What happens when it returns empty?
  def filter(p: HistoryTree => Boolean): HistoryTree = {
    filterAcc(p)
  }
  def filterAcc(p: HistoryTree => Boolean, oldTree: HistoryTree = new EmptyHTree): HistoryTree = {
    val newTree: HistoryTree = this match {
      case include if p(this) => oldTree.addValue(this)
      case _ => oldTree
    }
    new HTree(newTree.time, newTree.value, this.left.filterAcc(p, newTree), this.right.filterAcc(p, newTree))
  }




  override def toString: String = s"[l: ${this.left}, e: (${this.time}, ${this.value}), r: ${this.right}]"


}
