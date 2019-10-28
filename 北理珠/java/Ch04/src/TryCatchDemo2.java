class MyArray{
	void processArray(){
		int[] ary={10,20,30,40,50};
		try{
			for (int i = 0; i < 6; i++) {
				System.out.println(ary[i]);
			}
		}catch(ArrayIndexOutOfBoundsException ex){
			//ex.printStackTrace();
			//System.out.println(ex.getMessage());
			System.out.println("数组下标越界");
		}
		
	}
}
public class TryCatchDemo2 {

	public static void main(String[] args) {
		MyArray ma=new MyArray();
		ma.processArray();

	}

}
