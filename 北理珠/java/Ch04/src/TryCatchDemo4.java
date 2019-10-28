
public class TryCatchDemo4 {

	public static void main(String[] args) {
		try{
			String s="abc";
			int n=Integer.parseInt(s);
			System.out.println(n);
		}catch(NumberFormatException ex){
			//ex.printStackTrace();
			System.out.println(ex.getMessage());
			System.out.println("数字转换格式异常");
		}
		
	}

}
