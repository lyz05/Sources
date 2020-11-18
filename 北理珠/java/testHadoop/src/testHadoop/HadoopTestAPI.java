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
		//��������
		Configuration conf = new Configuration();
		conf.set("fs.defaultFS", "hdfs://liuyz0:8020");
		//��ȡ�ļ�ϵͳʵ��
		FileSystem fs = FileSystem.get(conf);
		//����Ŀ¼
		Path newPath = new Path("/user/liuyz/testapi");
		fs.mkdirs(newPath);
		//�ϴ������ļ�
		Path fromPath = new Path("D:\\Download\\ʹ��˵��.txt");
		Path toPath = new Path("/user/liuyz/test.txt");
		fs.copyFromLocalFile(fromPath, toPath);
		//���HDFS�ϵ��ļ�����
		Path path = toPath;
		FSDataInputStream fin = fs.open(path);
		BufferedReader br = new BufferedReader(new InputStreamReader(fin));
		for (String line="";(line=br.readLine()) != null;System.out.println(line));
		br.close();
		fin.close();
		//׷���ı�
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
