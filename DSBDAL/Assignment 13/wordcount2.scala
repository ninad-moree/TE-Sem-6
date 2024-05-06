val data = sc.textFile("wordcount2.txt");
data.collect();

val splitData = data.flatMap(line => line.split(""));
splitData.collect();

val mapData = splitData.map(word => (word, 1));
mapData.collect();

val reducData = mapData.reduceByKey(_+_);
reducData.collect();


/*
    In TERMINAL:

    spark-shell
    :load wordcount2.scala
*/