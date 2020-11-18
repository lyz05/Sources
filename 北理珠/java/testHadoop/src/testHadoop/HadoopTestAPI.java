package testHadoop;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FSDataInputStream;
import org.apache.hadoop.fs.FSDataOutputStream;
import org.apache.hadoop.fs.FileStatus;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;

public class HadoopTestAPI {
	
	public static void main(String[] args) throws IOException{
		//创建配置
		Configuration conf = new Configuration();
		conf.set("fs.defaultFS", "hdfs://liuyz0:8020");
		//获取文件系统实例
		FileSystem fs = FileSystem.get(conf);
		//创建目录
		Path newPath = new Path("/user/liuyz/testapi");
		fs.mkdirs(newPath);
		//上传本地文件
		Path fromPath = new Path("D:\\Download\\使用说明.txt");
		Path toPath = new Path("/user/liuyz/test.txt");
		fs.copyFromLocalFile(fromPath, toPath);
		//输出HDFS上的文件内容
		Path path = toPath;
		FSDataInputStream fin = fs.open(path);
		BufferedReader br = new BufferedReader(new InputStreamReader(fin));
		for (String line="";(line=br.readLine()) != null;System.out.println(line));
		br.close();
		fin.close();
		//追加文本
		FSDataOutputStream fout = fs.append(path);
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(fout));
		bw.newLine();
		bw.write("Hello world!");
		bw.newLine();
		bw.close();
		fout.close();
		fs.close();
	}
}
