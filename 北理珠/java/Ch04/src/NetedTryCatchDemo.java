
public class NetedTryCatchDemo {

	public static void main(String[] args) {
		try{
			try{
				try{
					int n1=Integer.parseInt(args[0]);
					int n2=Integer.parseInt(args[1]);
					int n=n1/n2;
					System.out.println("结果是："+n);
				}catch(NumberFormatException ex){
					System.out.println("数字格式转换异常：请输入整数");
				}
			}catch(ArithmeticException ex){
				System.out.println("算术异常：除数不能为零");
			}
		}catch(ArrayIndexOutOfBoundsException ex){
			ex.printStackTrace();
			System.out.println("数组下标越界异常：请输入两个数");
		}
	}
}
