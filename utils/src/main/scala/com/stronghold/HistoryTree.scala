package com.stronghold


trait HistoryTree {
  val time: Option[Time]
  val value: Option[Any]
  def addValue(elem: HTree): HTree
  def valueAtTime(t: Time): Option[Any]
}

class EmptyHTree extends HistoryTree {
  val time: Option[Time] = None
  val value: Option[Any] = None
  def addValue(elem: HTree): HTree = elem
  def valueAtTime(t: Time): Option[Any] = None

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
  def addValue(elem: HTree): HTree = elem match {
    case lt if elem.time < this.time => new HTree(this.time, this.value, this.left.addValue(elem), new EmptyHTree)
    case gt if elem.time > this.time => new HTree(this.time, this.value, new EmptyHTree, this.right.addValue(elem))
    case sameElem if (elem.time == this.time) && (elem.value == this.value) => this
    case newValueOldTime if (elem.time == this.time) && (elem.value != this.value) => throw new IllegalArgumentException
  }

  def valueAtTime(t: Time): Option[Any] = t match {
    // If the right child is nonempty, then we want to return this.value when right's time is after the query time.
    // However, if it empty, and None is always less than Some(val), it's the same as saying there were no attribute
    // state changes until now, and we still want to return this.value (hence the ugly getOrElse)
    case foundTimeRange if (this.time <= Option(t)) && (this.right.time.getOrElse(Time(999999)) > t) => this.value
    case earlierTimeRange if this.time > Option(t) => this.left.valueAtTime(t)
    // Since we took care of the right child empty case in `foundTimeRange`, this should resolve correctly (w/o Nones)
    case laterTimeRange if this.right.time <= Option(t) => this.right.valueAtTime(t)
  }

  override def toString: String = s"[l: ${this.left}, e: (${this.time}, ${this.value}), r: ${this.right}]"


}


