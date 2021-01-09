package com.cpm.hadoop.weather;

import java.io.IOException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.conf.Configured;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;
import org.apache.hadoop.util.Tool;
import org.apache.hadoop.util.ToolRunner;

public class ExtractAirTemperature  extends Configured implements Tool{
	public static class ExtractAirTemperatureMapper extends Mapper<LongWritable, Text, Text, IntWritable>{
		private static final int MISSING = -9999;
		@Override
		protected void map(LongWritable key, Text value, Context context)
				throws IOException, InterruptedException {
			//1974 01 08 18    10   -10  9931   170    51     6 -9999 -9999			
			String line = value.toString();
			String year = line.substring(0,4);
			String month = line.substring(5,7);
			String day = line.substring(8,10);
			String hour = line.substring(11,13).trim();
			String strAirTemperature = line.substring(14,19).trim();
			int airTemperature = Integer.parseInt(strAirTemperature);
			
			if (airTemperature != MISSING){
				context.write(new Text(year+"/"+month+"/"+day+": " + hour), new IntWritable(airTemperature));
			}
		}
	}

	@Override
	public int run(String[] args) throws Exception {
		// �жϲ��������Ƿ���ȷ
		// ����޲�����������ʾ���г���˵��
		if (args.length != 2) {
			System.err.println("");
			System.err.printf("Usage: %s < input path > < output path > \n", this.getClass().getSimpleName());
			System.err.printf("Example: hadoop jar %s hdfs://localhost:9000/user/grid/in hdfs://localhost:9000/user/grid/output\n", this.getClass().getSimpleName());
			System.exit(-1);
		}

		Configuration conf = getConf();
		Job job = new Job(conf, "ExtractAirTemperature");  // ������
		job.setJarByClass(ExtractAirTemperature.class);	    // ָ��Class

		FileInputFormat.addInputPath(job, new Path(args[0]));   // ����·��
		FileOutputFormat.setOutputPath(job, new Path(args[1])); // ���·��
		//ֻ��Mapper
		job.setMapperClass(ExtractAirTemperatureMapper.class);    
		
		job.setInputFormatClass(TextInputFormat.class);
		job.setOutputFormatClass(TextOutputFormat.class);
		job.setOutputKeyClass(Text.class); 			// ָ�������KEY�ĸ�ʽ
		job.setOutputValueClass(IntWritable.class); // ָ�������VALUE�ĸ�ʽ

		job.waitForCompletion(true);

		return job.isSuccessful() ? 0 : 1;
	}

	public static void main(String[] args) throws Exception {
		// ��¼��ʼʱ��
		DateFormat formatter = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		Date startTime = new Date();

		// ��������
		int res = ToolRunner.run(new ExtractAirTemperature(), args);
		if (res==-1)
			System.exit(-1);

		// ��������ʱ
		Date endTime = new Date();
		double duration  = (endTime.getTime() - startTime.getTime())/60000.0; 
		
		System.out.println( "����ʼ��" + formatter.format(startTime) );
		System.out.println( "���������" + formatter.format(endTime) );
		System.out.println( "�����ʱ��" + String.valueOf(duration) + " ����" );
		System.exit(res);
	}
	

}
