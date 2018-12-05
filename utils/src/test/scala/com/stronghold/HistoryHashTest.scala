package com.stronghold

import org.scalatest.FunSuite
import scala.util.Random.nextInt

class HistoryHashTest extends FunSuite {

  val times: Seq[Time] = Seq(201310, 201407, 201501).map( p => Time(p) )
  val currTime: Time = Time(201811)
/*
  test(s"An time (201201) that is earlier than the earliest time in the history object (${times(0)})")

  test(s"The current time ($currTime) should return the state of the last known change (${times.last}")

  test(s"The state returned for a given time should be the same for every time in the interval")

  test(s"The object should return the correct state for a valid time in the relevant interval")

  test(s"The same state should be returnable in two or more discontinuous intervals")
*/
}
