package com.lyz.hadoop.weather;

import java.io.IOException;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class TemperatureMapper extends
		Mapper<LongWritable, Text, Text, IntWritable> {
	private static final int MISSING = -9999;

	@Override
	protected void map(LongWritable key, Text value, Context context)
			throws IOException, InterruptedException {
		//读取源文件，line得到的是源文件中一行数据
		String line = value.toString();
		//年份
		String Year = line.substring(0,4);
		//月份
		String month = line.substring(5,7);
		//年月
		String yearmonth = Year+month;
		//所观测到的气温
		String strAirTemperature = line.substring(13,19).trim();
		
		int airTemperature = Integer.parseInt(strAirTemperature);
		if (airTemperature != MISSING){
			//将年份及当次观测的气温输出
			context.write(new Text(yearmonth), new IntWritable(airTemperature));
		}
	}
}
