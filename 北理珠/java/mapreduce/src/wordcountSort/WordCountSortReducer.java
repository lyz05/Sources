package wordcountSort;

import java.io.IOException;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

public class WordCountSortReducer extends Reducer<IntWritable, Text, Text, IntWritable> {
	@Override
	protected void reduce(IntWritable counts, Iterable<Text> words,
			Reducer<IntWritable, Text, Text, IntWritable>.Context context) throws IOException, InterruptedException {
		for (Text word : words) {
			context.write(word, counts);
		}
	}
}
