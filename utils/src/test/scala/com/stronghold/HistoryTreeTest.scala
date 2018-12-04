package com.stronghold

import org.scalatest.FunSuite
import scala.util.Random.nextInt
import org.apache.logging.log4j.{LogManager, Logger}

class HistoryTreeTest extends FunSuite {

  val log: Logger = LogManager.getLogger(classOf[HistoryTreeTest])

  val times: Seq[Time] = Seq(201310, 201407, 201501).map( p => Time(p) )
  val currTime: Time = Time(201811)

  test(s"After including an (time, value) element, the object should return the correct value at" +
    s"when the associated time is queried") {
    val newHistory: HistoryTree = new EmptyHTree
    val newElem: HTree = new HTree(_time = Some(Time(201501)), _value = Some("a"))
    println(s"Inserting element (t: ${newElem.time}, v: ${newElem.value} an empty history object")
    val updatedHistory: HTree = newHistory.addValue(newElem)
    println(updatedHistory)
    println(s"The value at time ${updatedHistory.time.get} is ${updatedHistory.value.get}")
    updatedHistory.value == newElem.value
  }

  test(s"After including an (time, value) element, the object should contain added element") {
    val newHistory: HistoryTree = new EmptyHTree
    val newElem: HTree = new HTree(_time = Some(Time(201501)), _value = Some("a"))
    println(s"Inserting element (t: ${newElem.time}, v: ${newElem.value} an empty history object")
    val updatedHistory: HTree = newHistory.addValue(newElem)
    println(updatedHistory)
    println(s"The tree ($updatedHistory) contains $newElem: ${updatedHistory.contains(newElem)}")
    updatedHistory.contains(newElem)
  }

  test(s"A time (201411) that is earlier than the earliest time in the history object (201501) should" +
    s"return None when queried"){
    val newHistory: HistoryTree = new EmptyHTree
    val newElem: HTree = new HTree(_time = Some(Time(201501)), _value = Some("a"))
    println(s"Inserting element (t: ${newElem.time}, v: ${newElem.value} an empty history object")
    val updatedHistory: HTree = newHistory.addValue(newElem)
    println(updatedHistory)
    println(s"Value returned when 201411 is queried: ${updatedHistory.valueAtTime(Time(201411))}")
    updatedHistory.valueAtTime(Time(201411)) == None
  }

  test(s"The current time (201812) should return the state of the last known change (201501)"){
    val newHistory: HistoryTree = new EmptyHTree
    val newElem: HTree = new HTree(_time = Some(Time(201501)), _value = Some("a"))
    println(s"Inserting element (t: ${newElem.time}, v: ${newElem.value} an empty history object")
    val updatedHistory: HTree = newHistory.addValue(newElem)
    println(updatedHistory)
    println(s"Value returned when 201812 is queried: ${updatedHistory.valueAtTime(Time(201812)).get}")
    updatedHistory.valueAtTime(Time(201812)).get == "a"
  }

  test(s"The state returned for a given time should be the same for every time in the interval") {
    val newHistory: HTree = new HTree(_time = Some(Time(201501)), _value = Some("a"))
    val newElem: HTree = new HTree(_time = Some(Time(201504)), _value = Some("b"))
    println(s"Inserting element (t: ${newElem.time}, v: ${newElem.value} an existing history object(t: ${newHistory.time}, v: ${newHistory.value})")
    val updatedHistory: HTree = newHistory.addValue(newElem)
    println(updatedHistory)
    val intervalTimes: Seq[Int] = Seq(201501, 201502, 201503)
    intervalTimes.foreach {
      t =>
        println(s"Value returned when $t is queried: ${updatedHistory.valueAtTime(Time(t)).get}")
    }
    intervalTimes.forall( t => updatedHistory.valueAtTime(Time(t)).get == "a")
  }

  test(s"The object should return the correct state for a valid time in the relevant interval") {
    val newHistory: HTree = new HTree(_time = Some(Time(201501)), _value = Some("a"))
    val newElem1: HTree = new HTree(_time = Some(Time(201504)), _value = Some("b"))
    println(s"Inserting element (t: ${newElem1.time}, v: ${newElem1.value} an existing history object(t: ${newHistory.time}, v: ${newHistory.value})")
    val newElem2: HTree = new HTree(_time = Some(Time(201507)), _value = Some("c"))
    println(s"Inserting element (t: ${newElem2.time}, v: ${newElem2.value} an existing history object(t: ${newHistory.time}, v: ${newHistory.value})")
    val updatedHistory: HTree = newHistory.addValue(newElem1).addValue(newElem2)
    println(updatedHistory)
    val validValues: Map[Int, String] = Map(
      201502 -> "a",
      201505 -> "b",
      201508 -> "c"
    )
    validValues.keys.foreach {
      t =>
        println(s"Value returned when $t is queried: ${updatedHistory.valueAtTime(Time(t)).get}")
    }
    validValues.keys.forall( t => updatedHistory.valueAtTime(Time(t)).get == validValues(t))
  }

  test(s"The same state should be returnable in two or more discontinuous intervals"){
    val newHistory: HTree = new HTree(_time = Some(Time(201501)), _value = Some("a"))
    val newElem1: HTree = new HTree(_time = Some(Time(201504)), _value = Some("b"))
    println(s"Inserting element (t: ${newElem1.time}, v: ${newElem1.value} an existing history object(t: ${newHistory.time}, v: ${newHistory.value})")
    val newElem2: HTree = new HTree(_time = Some(Time(201507)), _value = Some("a"))
    println(s"Inserting element (t: ${newElem2.time}, v: ${newElem2.value} an existing history object(t: ${newHistory.time}, v: ${newHistory.value})")
    val updatedHistory: HTree = newHistory.addValue(newElem1).addValue(newElem2)
    println(updatedHistory)
    val validValues: Map[Int, String] = Map(
      201502 -> "a",
      201505 -> "b",
      201508 -> "a"
    )
    validValues.keys.foreach {
      t =>
        println(s"Value returned when $t is queried: ${updatedHistory.valueAtTime(Time(t)).get}")
    }
    validValues.keys.forall( t => updatedHistory.valueAtTime(Time(t)).get == validValues(t))

  }

}
