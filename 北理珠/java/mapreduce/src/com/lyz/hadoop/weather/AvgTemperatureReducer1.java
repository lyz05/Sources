package com.lyz.hadoop.weather;

import java.io.IOException;

import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

public class AvgTemperatureReducer1 extends Reducer<Text, IntWritable, Text, DoubleWritable>{
	
	@Override
	protected void reduce(Text key, Iterable<IntWritable> values, Context context)
			throws IOException, InterruptedException {
		int sum = 0,cnt = 0;
		for (IntWritable value: values) {
			sum += value.get();
			cnt ++;
		}
		context.write(key, new DoubleWritable(1.0*Math.round(100*sum/cnt)/100));
	}
}
