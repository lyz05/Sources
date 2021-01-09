package com.lyz.hadoop.weather;

import java.io.IOException;

import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import javafx.util.Pair;

public class AvgTemperatureReducer extends Reducer<Text, Text, Text, DoubleWritable>{
	
	@Override
	protected void reduce(Text key, Iterable<Text> values, Context context)
			throws IOException, InterruptedException {
		double sum = 0;
		int cnt = 0;
		for (Text value: values) {
			String delimeter = "_";  // Ö¸¶¨·Ö¸î×Ö·û
			String[] temp = value.toString().split(delimeter); // ·Ö¸î×Ö·û´®
			sum += Double.valueOf(temp[0]);
			cnt  += Integer.valueOf(temp[1]);
		}
//		Pair<Double, Integer>pair = new Pair<>(sum, cnt);
		context.write(key, new DoubleWritable(1.0*Math.round(100*sum/cnt)/100));
	}
}
