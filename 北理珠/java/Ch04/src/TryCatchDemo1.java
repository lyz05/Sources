class ExceptionClass{
	void caculate(int n1,int n2){
		try{
			int result=n1/n2;//可能出现异常
			System.out.println(result);
		}finally{
			System.out.println("finally块里的代码必定执行");
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
