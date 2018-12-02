package com.stronghold


trait HistoryTree {
  def addValue(elem: HistoryTree): HistoryTree
  def valueAtTime(t: Time): Option[Any]
}

class EmptyHTree extends HistoryTree {
  val time: Option[Time] = new Nothing
  val value: Option[Any] = new Nothing
  def addValue(elem: HistoryTree): HistoryTree = elem
  def valueAtTime(t: Time): Option[Any] = new Nothing
}

class HTree(time: Option[Time], value: Option[Any],
            left: HistoryTree = new EmptyHTree, right: HistoryTree = new EmptyHTree) extends HistoryTree with Ordered[HTree] {
  def compare(thatTree: HTree): Int = ???
  def addValue(elem: HistoryTree): HTree = ???
  def valueAtTime(t: Time): Option[Any] = ???


}


