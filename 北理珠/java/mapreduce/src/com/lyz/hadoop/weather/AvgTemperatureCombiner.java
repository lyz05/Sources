package com.lyz.hadoop.weather;

import static org.mockito.Matchers.intThat;

import java.io.IOException;

import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import javafx.util.Pair;

public class AvgTemperatureCombiner extends Reducer<Text, Text, Text, Text> {

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
		//test
		context.write(key, new Text(sum+"_"+cnt));
	}
}
