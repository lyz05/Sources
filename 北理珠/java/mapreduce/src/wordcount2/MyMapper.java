package wordcount2;

import java.io.IOException;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class MyMapper extends Mapper<LongWritable, Text, Text, IntWritable> {
	Text w = new Text();
	IntWritable one = new IntWritable(1);
	String word;

	@Override
	protected void setup(Mapper<LongWritable, Text, Text, IntWritable>.Context context)
			throws IOException, InterruptedException {
		word = context.getConfiguration().get("word");
	}

	@Override
	protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Text, IntWritable>.Context context)
			throws IOException, InterruptedException {
		String[] vals = value.toString().split(" ");
		for (String val : vals) {
			if (val.equals(word)) {
				w.set(val);
				context.write(w, one);
			}
		}
	}
}
