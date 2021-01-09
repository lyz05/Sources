package wordcount1;

import java.io.IOException;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

public class MyReducer extends Reducer<Text, IntWritable, Text, IntWritable> {
	IntWritable counts = new IntWritable();

	@Override
	protected void reduce(Text word, Iterable<IntWritable> ones,
			Reducer<Text, IntWritable, Text, IntWritable>.Context context) throws IOException, InterruptedException {
		int sum = 0;
		for (IntWritable one : ones) {
			sum += one.get();
		}
		counts.set(sum);
		context.write(word, counts);
	}

}
