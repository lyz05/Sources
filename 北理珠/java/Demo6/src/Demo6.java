
import java.io.*;

public class Demo6 {
	//初始化标准输入流
	static InputStreamReader isr=new InputStreamReader(System.in);
	static BufferedReader br=new BufferedReader(isr);
	
	public static void outputToFile()
	{
		try {
			//打开文件并初始化输出流
			File f=new File("myfile.txt");
			FileWriter fw=new FileWriter(f);
			BufferedWriter bw=new BufferedWriter(fw);
			
			System.out.println("Please enter the sentence what you want to write:");
			String line = br.readLine();
			while (!line.equals("bye"))			//判断是否结束程序
			{
				bw.write(line+"\n");					//写到文件
				System.out.println("Please enter the sentence what you want to write:");
				line = br.readLine();
				//System.out.println(line);
			}
			
			//关闭文件流
			bw.close();
			fw.close();
		}catch (IOException e) {			//IO异常捕获
			System.out.println(e.toString());
		}
	}
	public static void searchFromFile()
	{
		try {
			System.out.println("Please enter the character what you want to search:");
			String strSearch = br.readLine(),str = "";
			
			//打开文件并初始化输入流
			File f=new File("myfile.txt");
			FileReader fr=new FileReader(f);
			BufferedReader br=new BufferedReader(fr);
			
			System.out.println("The result is:");
			while((str = br.readLine())!=null){
				  if(str.indexOf(strSearch)!=-1){
					  System.out.println(str);
				  }
				  //str = br.readLine();
			    }
			
			//关闭文件流
			br.close();
			fr.close();
		}catch (IOException e) {			//IO异常捕获
			System.out.println(e.toString());
		}
	}
	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		outputToFile();
		searchFromFile();
		
		//关闭标准输入输出流
		try {
		br.close();
		isr.close();
		} catch (IOException e) {			//IO异常捕获
			System.out.println(e.toString());
		}
	}

}
