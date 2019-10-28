//用户自定义异常，处理年龄异常
class MyException extends Exception{
	MyException(){
		
	}
	MyException(String message){
		super(message);//调用Exception的带参数的构造方法
	}
}

class Bank{
	void proveLoan(int age) throws MyException{ //回避异常
		if(age>=65){
			throw new MyException("年龄超过65岁，不允许贷款");
		}else{
			System.out.println("年龄65岁以下，允许贷款");
		}
	}
	
}

public class UserdefinedExceptionDemo {

	public static void main(String[] args) {
		try{
			Bank bank=new Bank();
			bank.proveLoan(67);
		}catch(MyException ex){
			System.out.println(ex.getMessage());
		}
	}
}
