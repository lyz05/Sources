import java.util.Calendar;

class ILLegalYearException extends Exception {
	ILLegalYearException() {
		
	}
	ILLegalYearException(String message) {
		super("无效入职年份："+message);
	}
}

class ILLegalSalaryException extends Exception {
	ILLegalSalaryException() {
	
	}
	ILLegalSalaryException(String message) {
		super("无效月工资："+message);
	}
}

public class Demo3 {
	public static int getSysYear() {
		Calendar date = Calendar.getInstance();
		String year = String.valueOf(date.get(Calendar.YEAR));
		return Integer.parseInt(year);
	}
	
	 public static void main(String[] args) {
		 final int nowYear = getSysYear();
		 if (args.length!=2) {
			 System.out.println("传入参数数目错误：请传入入职年份和月工资两个参数");
			 return;
		 }
		 int year;
		 double salary;
		 try {
			 //格式检查
			 try {
				 year = Integer.parseInt(args[0]);
			 }  catch (NumberFormatException ex) {
				 throw new ILLegalYearException("数字格式转换异常");
			 }
			 try {
				 salary = Integer.parseInt(args[1]);
			 } catch (NumberFormatException ex) {
				 throw new ILLegalSalaryException("数字格式转换异常");
			 }
			 if (salary<500) throw new ILLegalSalaryException("工资低于500元");
			 //年份
			 int resultYear = nowYear - year;
			 if (resultYear<0) {
				 throw new ILLegalYearException("入职年份大于今年");
			 } else if (year<0) {
				 throw new ILLegalYearException("入职年份为负数");
			 }
			 //奖金计算
			 if (resultYear<1) {
				 salary = salary;
			 } else if (resultYear<3)
			 {
				 salary *= 1.3;
			 } else if (resultYear<5) {
				 salary *= 1.5;
			 } else salary *= 2;
			 System.out.println("该员工奖金："+salary);
		 } catch (ILLegalYearException ex) {
			 System.out.println(ex.getMessage());
			 return;
		 } catch (ILLegalSalaryException ex) {
			 System.out.println(ex.getMessage());
			 return;
		 }

	}
}
