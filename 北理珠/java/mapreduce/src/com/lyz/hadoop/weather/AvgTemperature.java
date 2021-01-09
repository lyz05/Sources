package com.lyz.hadoop.weather;

import java.io.IOException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

import javafx.util.Pair;

public class AvgTemperature {

	public static void main(String[] args) throws IOException, ClassNotFoundException, InterruptedException {
		if (args.length != 2){
			System.err.println("Usage: AvgTemperature <input path> <output path>");
			System.exit(-1);
		}
		
		Job job = new Job();
		//��ҵ��
		job.setJobName("FindAvgTemperature");
		//ָ��MapReduceDriver��class
		job.setJarByClass(AvgTemperature.class);
		//��������·��
		FileInputFormat.addInputPath(job, new Path(args[0]));
		//������·��
		FileOutputFormat.setOutputPath(job, new Path(args[1]));
		//Mapper��
		job.setMapperClass(AvgTemperatureMapper.class);
		//�ϲ���
		//job.setCombinerClass(AvgTemperatureCombiner.class);
		//Reducer��
		job.setReducerClass(AvgTemperatureReducer.class);
		//ָ�����Key��ʽ
		job.setOutputKeyClass(Text.class);
		//ָ�����Value��ʽ
		job.setOutputValueClass(DoubleWritable.class);
		job.setMapOutputValueClass(Text.class);
		//����reduce��������
		//job.setNumReduceTasks(2);
		
		//��¼��ʼʱ��
		DateFormat formatter = new SimpleDateFormat( "yyyy-MM-dd HH:mm:ss" );
		Date startTime = new Date();
		
		job.waitForCompletion(true);
		
		Date endTime = new Date();
		double duration  = (endTime.getTime() - startTime.getTime())/60000.0; 
		
		System.out.println( "����ʼ��" + formatter.format(startTime) );
		System.out.println( "���������" + formatter.format(endTime) );
		System.out.println( "�����ʱ��" + String.valueOf(duration) + " ����" );
		
		System.exit(job.isSuccessful()?0:-1);
	}

}
