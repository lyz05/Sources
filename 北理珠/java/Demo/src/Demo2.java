
public class Demo2 {
	
	public static void main(String[] args) {
		//输入合法性判断
		if (args.length!=2) {
			System.out.println("Invaild Input!");
			return;
		}
		int year = Integer.parseInt(args[0]),month = Integer.parseInt(args[1]),days=0;
		if (year/1000==0 || month<1 || month>12) 
		{
			System.out.println("Invaild Input!");
			return;	
		}
		//闰年判断
		boolean flag = false;
		if ((year%400==0) || (year%100!=0 && year%4==0)) 
			flag = true;
		else
			flag = false;
		switch (month) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				days = 31;
				break;
			case 2:
				if (flag) days = 29; else days = 28;
				break;
			default:
				days = 30;
				break;
		}
		System.out.println(days+" days");
	}
}
