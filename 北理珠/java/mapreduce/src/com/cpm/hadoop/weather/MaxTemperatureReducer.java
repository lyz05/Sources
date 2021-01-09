package com.cpm.hadoop.weather;

import java.io.IOException;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

public class MaxTemperatureReducer extends Reducer<Text, IntWritable, Text, IntWritable> {

	@Override
	protected void reduce(Text key, Iterable<IntWritable> values, Context context)
			throws IOException, InterruptedException {
		int maxValue = Integer.MIN_VALUE;
		//values��ĳ��ݣ�Ҳ����key�����������������б�
		for (IntWritable value: values){
			maxValue = Math.max(maxValue, value.get());
		}
		//���ĳ��ݣ�Ҳ����key�����������
		context.write(key, new IntWritable(maxValue));
	}
}
