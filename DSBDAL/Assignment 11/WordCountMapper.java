import java.io.IOException;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapreduce.*;

public class WordCountMapper extends Mapper<LongWritable, Text, Text, IntWritable> {
    private final static IntWritable one = new IntWritable(1);
    private Text word = new Text();

    @Override
    public void map(LongWritable key, Text value, Context context) throws IOException,
            InterruptedException {
        String line = value.toString();
        String[] words = line.split("\\s+"); // Splitting by whitespace
        for (String word : words) {
            this.word.set(word);
            context.write(this.word, one);
        }
    }
}