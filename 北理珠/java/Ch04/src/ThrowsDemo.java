import java.io.IOException;

class MyMaths{
	void calc(int n1,int n2) throws ArithmeticException{//�ر��쳣
		if(n2!=0){
			int n=n1/n2;
			System.out.println("�����"+n);
		}else{
			//�ֶ��������쳣������һ���쳣����,new�ز�����
			throw new ArithmeticException("�����쳣����������Ϊ��");
		}
	}
	
	void m1() throws IOException {//�ر��쳣
		//�ֶ�����һ����������쳣
		throw new IOException();
	}
}
public class ThrowsDemo {

	public static void main(String[] args) {
		try{
			MyMaths mm=new MyMaths();
			mm.calc(10, 0);	
			mm.m1();
		}catch(ArithmeticException ex){
			//ex.printStackTrace();
			System.out.println(ex.getMessage());
		}catch(IOException ex){
			ex.printStackTrace();
		}
	}
}
