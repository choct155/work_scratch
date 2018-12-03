package com.stronghold

object HistoryScratch {
  def main(args: Array[String]): Unit = {

    val w: Option[Time] = Some(Time(201200))
    val x: Option[Time] = Some(Time(201201))
    val y: Option[Time] = Some(Time(201202))
    val z: Option[Time] = Some(Time(201204))

    val atree: HTree = new HTree(Some(Time(201201)), Some("a"))
    val btree: HTree = new HTree(Some(Time(201202)), Some("b"))
    val ctree: HTree = new HTree(Some(Time(201203)), Some("a"))
    val empty: EmptyHTree = new EmptyHTree
    val dtree: HTree = empty.addValue(atree).addValue(btree).addValue(ctree)

    println(atree.valueAtTime(Time(201202)))
    println(btree.valueAtTime(Time(201202)))
    println(btree.valueAtTime(Time(201201)))
    Seq(w,x,y,z).foreach( t => println((t, dtree.valueAtTime(t.get))))
  }

}
