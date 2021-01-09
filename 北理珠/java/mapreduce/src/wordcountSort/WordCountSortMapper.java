package wordcountSort;

import java.io.IOException;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class WordCountSortMapper extends Mapper<LongWritable, Text, IntWritable, Text> {
	Text word = new Text();
	IntWritable counts = new IntWritable();

	@Override
	protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, IntWritable, Text>.Context context)
			throws IOException, InterruptedException {
		String[] val = value.toString().split("\t");
		word.set(val[0]);
		counts.set(Integer.valueOf(val[1]));
		context.write(counts, word);
	}
}
