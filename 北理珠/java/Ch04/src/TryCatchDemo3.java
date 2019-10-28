class Student{
	String name="Jack";
	
}
public class TryCatchDemo3 {

	public static void main(String[] args) {
		try{
			String  s=null;
			System.out.println(s.length());
			
			Student stu=null;
			System.out.println(stu.name);
		}catch(NullPointerException ex){
			ex.printStackTrace();
			System.out.println("ø’“˝”√“Ï≥£");
		}
		
	}

}
