package com.lyz.hadoop.weather;

import java.io.IOException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class MaxTemperature {

	public static void main(String[] args) throws IOException, ClassNotFoundException, InterruptedException {
		if (args.length != 2){
			System.err.println("Usage: MaxTemperature <input path> <output path>");
			System.exit(-1);
		}
		
		Job job = new Job();
		//作业名
		job.setJobName("FindMaxTemperature");
		//指定MapReduceDriver的class
		job.setJarByClass(MaxTemperature.class);
		//数据输入路径
		FileInputFormat.addInputPath(job, new Path(args[0]));
		//结果输出路径
		FileOutputFormat.setOutputPath(job, new Path(args[1]));
		//Mapper类
		job.setMapperClass(TemperatureMapper.class);
		//合并器
		job.setCombinerClass(MaxTemperatureCombiner.class);
		//Reducer类
		job.setReducerClass(MaxTemperatureReducer.class);
		//指定输出Key格式
		job.setOutputKeyClass(Text.class);
		//指定输出Value格式
		job.setOutputValueClass(IntWritable.class);
		//设置reduce任务数量
		//job.setNumReduceTasks(2);
		
		//记录开始时间
		DateFormat formatter = new SimpleDateFormat( "yyyy-MM-dd HH:mm:ss" );
		Date startTime = new Date();
		
		job.waitForCompletion(true);
		
		Date endTime = new Date();
		double duration  = (endTime.getTime() - startTime.getTime())/60000.0; 
		
		System.out.println( "任务开始：" + formatter.format(startTime) );
		System.out.println( "任务结束：" + formatter.format(endTime) );
		System.out.println( "任务耗时：" + String.valueOf(duration) + " 分钟" );
		
		System.exit(job.isSuccessful()?0:-1);
	}

}
