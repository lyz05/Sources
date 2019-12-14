
import java.io.*;

public class Demo6 {
	//��ʼ����׼������
	static InputStreamReader isr=new InputStreamReader(System.in);
	static BufferedReader br=new BufferedReader(isr);
	
	public static void outputToFile()
	{
		try {
			//���ļ�����ʼ�������
			File f=new File("myfile.txt");
			FileWriter fw=new FileWriter(f);
			BufferedWriter bw=new BufferedWriter(fw);
			
			System.out.println("Please enter the sentence what you want to write:");
			String line = br.readLine();
			while (!line.equals("bye"))			//�ж��Ƿ��������
			{
				bw.write(line+"\n");					//д���ļ�
				System.out.println("Please enter the sentence what you want to write:");
				line = br.readLine();
				//System.out.println(line);
			}
			
			//�ر��ļ���
			bw.close();
			fw.close();
		}catch (IOException e) {			//IO�쳣����
			System.out.println(e.toString());
		}
	}
	public static void searchFromFile()
	{
		try {
			System.out.println("Please enter the character what you want to search:");
			String strSearch = br.readLine(),str = "";
			
			//���ļ�����ʼ��������
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
			
			//�ر��ļ���
			br.close();
			fr.close();
		}catch (IOException e) {			//IO�쳣����
			System.out.println(e.toString());
		}
	}
	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		outputToFile();
		searchFromFile();
		
		//�رձ�׼���������
		try {
		br.close();
		isr.close();
		} catch (IOException e) {			//IO�쳣����
			System.out.println(e.toString());
		}
	}

}
