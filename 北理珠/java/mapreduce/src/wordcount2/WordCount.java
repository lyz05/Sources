package wordcount2;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.conf.Configured;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.util.Tool;
import org.apache.hadoop.util.ToolRunner;

public class WordCount extends Configured implements Tool {

	public static void main(String[] args) throws Exception {
		String[] myArgs = new String[] { "Horatio", "hdfs://master:8020/user/caipm/in/hamlet.txt",
				"hdfs://master:8020/user/caipm/out2" };
		ToolRunner.run(getConfiguration(), new WordCount(), myArgs);
	}

	public static Configuration getConfiguration() {
		Configuration conf = new Configuration();
		conf.setBoolean("mapreduce.app-submission.cross-platform", true);// 指定是否允许客户端提交
		conf.set("fs.defaultFS", "hdfs://master:8020");// 指定namenode
		conf.set("mapreduce.framework.name", "yarn"); // 指定使用yarn框架
		conf.set("yarn.resourcemanager.address", "master:8032"); // 指定resourcemanager
		conf.set("yarn.resourcemanager.scheduler.address", "master:8030");// 指定资源分配器
		conf.set("mapreduce.jobhistory.address", "master:10020");
		conf.set("mapreduce.job.jar", "D:\\temp\\wordcount2.jar");
		return conf;

	}

	@Override
	public int run(String[] args) throws Exception {
		Configuration conf = getConf();
		conf.set("word", args[0]);
		Job job = Job.getInstance(conf);
		job.setJarByClass(WordCount.class);
		job.setMapperClass(MyMapper.class);
		job.setReducerClass(MyReducer.class);

		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(IntWritable.class);

		FileInputFormat.addInputPath(job, new Path(args[1]));
		FileOutputFormat.setOutputPath(job, new Path(args[2]));
		return job.waitForCompletion(true) ? 0 : 1;
	}
}
