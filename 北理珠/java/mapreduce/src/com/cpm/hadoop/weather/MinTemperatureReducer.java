package com.cpm.hadoop.weather;

import java.io.IOException;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

public class MinTemperatureReducer extends Reducer<Text, IntWritable, Text, IntWritable> {

	@Override
	protected void reduce(Text key, Iterable<IntWritable> values, Context context)
			throws IOException, InterruptedException {
		int minValue = Integer.MAX_VALUE;
		//values��ĳ��ݣ�Ҳ����key�����������������б�
		for (IntWritable value: values){
			minValue = Math.min(minValue, value.get());
		}
		//���ĳ��ݣ�Ҳ����key�����������
		context.write(key, new IntWritable(minValue));
	}
}
