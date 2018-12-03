import com.stronghold.{EmptyHTree, HTree, Time}


val w: Option[Time] = Some(Time(201200))
val x: Option[Time] = Some(Time(201201))
val y: Option[Time] = Some(Time(201202))
val z: Option[Time] = None

for {x1 <- x; w1 <- w} yield x1.compare(w1)
for {x1 <- x; y1 <- y} yield x1.compare(y1)
for {x1 <- x; y1 <- y} yield y1.compare(x1)

for {x1 <- x; z1 <- z} yield x1.compare(z1)
for {x1 <- x; z1 <- z} yield z1.compare(x1)

val atree: HTree = new HTree(Some(Time(201201)), Some("a"))
val btree: HTree = new HTree(Some(Time(201202)), Some("b"))
val ctree: EmptyHTree = new EmptyHTree

atree.valueAtTime(Time(201202))

true && (z > w)
(z > w)
(w > z)
