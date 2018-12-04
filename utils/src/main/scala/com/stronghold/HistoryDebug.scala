package com.stronghold

object HistoryDebug {
  def main(args: Array[String]): Unit = {

    val newHistory: HTree = new HTree(_time = Some(Time(201501)), _value = Some("a"))
    val newElem1: HTree = new HTree(_time = Some(Time(201504)), _value = Some("b"))
    println(s"Inserting element (t: ${newElem1.time}, v: ${newElem1.value} an existing history object(t: ${newHistory.time}, v: ${newHistory.value})")
    val newElem2: HTree = new HTree(_time = Some(Time(201507)), _value = Some("a"))
    println(s"Inserting element (t: ${newElem2.time}, v: ${newElem2.value} an existing history object(t: ${newHistory.time}, v: ${newHistory.value})")
    val updatedHistory: HTree = newHistory.addValue(newElem1).addValue(newElem2)
    println(updatedHistory)
  }

}
