//�û��Զ����쳣�����������쳣
class MyException extends Exception{
	MyException(){
		
	}
	MyException(String message){
		super(message);//����Exception�Ĵ������Ĺ��췽��
	}
}

class Bank{
	void proveLoan(int age) throws MyException{ //�ر��쳣
		if(age>=65){
			throw new MyException("���䳬��65�꣬���������");
		}else{
			System.out.println("����65�����£��������");
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
