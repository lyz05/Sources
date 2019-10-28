import java.io.IOException;

class MyMaths{
	void calc(int n1,int n2) throws ArithmeticException{//回避异常
		if(n2!=0){
			int n=n1/n2;
			System.out.println("结果："+n);
		}else{
			//手动的引发异常，产生一个异常对象,new必不可少
			throw new ArithmeticException("算术异常：除数不能为零");
		}
	}
	
	void m1() throws IOException {//回避异常
		//手动引发一个输入输出异常
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
