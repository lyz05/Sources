package com.lyz.hadoop.weather;

import java.io.IOException;

import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import javafx.util.Pair;

public class AvgTemperatureMapper extends
		Mapper<LongWritable, Text, Text, Text> {
	private static final int MISSING = -9999;

	@Override
	protected void map(LongWritable key, Text value, Context context)
			throws IOException, InterruptedException {
		//��ȡԴ�ļ���line�õ�����Դ�ļ���һ������
		String line = value.toString();
		//���
		String Year = line.substring(0,4);
		//�·�
		String month = line.substring(5,7);
		//����
		String yearmonth = Year+month;
		//���۲⵽������
		String strAirTemperature = line.substring(13,19).trim();
		String pair = strAirTemperature+"_1";
		int airTemperature = Integer.parseInt(strAirTemperature);
		if (airTemperature != MISSING){
			//����ݼ����ι۲���������
			context.write(new Text(yearmonth),new Text(pair));
		}
	}
}
