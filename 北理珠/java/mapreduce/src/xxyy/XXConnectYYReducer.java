package xxyy;

import java.io.IOException;

import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

public class XXConnectYYReducer extends Reducer<Text, NullWritable, Text, NullWritable>{
	@Override
	protected void reduce(Text date, Iterable<NullWritable> arg1,
			Reducer<Text, NullWritable, Text, NullWritable>.Context context) throws IOException, InterruptedException {
		context.write(date, NullWritable.get());
	}

}
