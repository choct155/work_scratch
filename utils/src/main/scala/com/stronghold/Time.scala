package com.stronghold

// TODO: This is just a stand in to build the history objects
case class Time(period: Int) extends Ordered[Time] {
  override def compare(that: Time): Int = this match {
    case earlierThan if this.period < that.period => -1
    case laterThan if this.period > that.period => 1
    case sameTime if this.period == that.period => 0
  }

}
