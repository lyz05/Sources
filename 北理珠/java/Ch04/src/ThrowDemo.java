class MyMath{
	void calc(int n1,int n2) throws RuntimeException{
		if(n2!=0){
			int n=n1/n2;
			System.out.println("结果："+n);
		}else{
			//手动的引发异常，产生一个异常对象,new必不可少
			throw new ArithmeticException("算术异常：除数不能为零");
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
