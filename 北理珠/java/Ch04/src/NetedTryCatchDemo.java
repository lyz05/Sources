
public class NetedTryCatchDemo {

	public static void main(String[] args) {
		try{
			try{
				try{
					int n1=Integer.parseInt(args[0]);
					int n2=Integer.parseInt(args[1]);
					int n=n1/n2;
					System.out.println("����ǣ�"+n);
				}catch(NumberFormatException ex){
					System.out.println("���ָ�ʽת���쳣������������");
				}
			}catch(ArithmeticException ex){
				System.out.println("�����쳣����������Ϊ��");
			}
		}catch(ArrayIndexOutOfBoundsException ex){
			ex.printStackTrace();
			System.out.println("�����±�Խ���쳣��������������");
		}
	}
}
