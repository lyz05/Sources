class MyMath{
	void calc(int n1,int n2) throws RuntimeException{
		if(n2!=0){
			int n=n1/n2;
			System.out.println("�����"+n);
		}else{
			//�ֶ��������쳣������һ���쳣����,new�ز�����
			throw new ArithmeticException("�����쳣����������Ϊ��");
		}
	}
}
public class ThrowDemo {

	public static void main(String[] args)/*throws RuntimeException*/ {
		try{
			MyMath mm=new MyMath();
			mm.calc(10, 0);	
		}catch(ArithmeticException ex){
			//ex.printStackTrace();
			System.out.println(ex.getMessage());
		}
		

	}

}
