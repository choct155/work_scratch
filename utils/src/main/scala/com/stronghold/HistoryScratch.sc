import com.stronghold.{HTree, Time}

val x: Int = 1
val y: Option[Int] = Some(1)
val z: Option[Int] = None

x == x
x == y.get
y == y
y == z

val newHistory: HTree = new HTree(_time = Some(Time(201501)), _value = Some("a"))
val newElem: HTree = new HTree(_time = Some(Time(201504)), _value = Some("b"))
val updatedHistory: HTree = newHistory.addValue(newElem)
