class ExceptionClass{
	void caculate(int n1,int n2){
		try{
			int result=n1/n2;//���ܳ����쳣
			System.out.println(result);
		}finally{
			System.out.println("finally����Ĵ���ض�ִ��");
		}
		
	}
}
public class TryCatchDemo1 {

	public static void main(String[] args) {
//		try{
			ExceptionClass ec=new ExceptionClass();
			ec.caculate(10, 2);
//		}catch(ArithmeticException ex){
//			ex.printStackTrace();
//		}
		

	}

}
