import java.util.Calendar;

class ILLegalYearException extends Exception {
	ILLegalYearException() {
		
	}
	ILLegalYearException(String message) {
		super("��Ч��ְ��ݣ�"+message);
	}
}

class ILLegalSalaryException extends Exception {
	ILLegalSalaryException() {
	
	}
	ILLegalSalaryException(String message) {
		super("��Ч�¹��ʣ�"+message);
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
			 System.out.println("���������Ŀ�����봫����ְ��ݺ��¹�����������");
			 return;
		 }
		 int year;
		 double salary;
		 try {
			 //��ʽ���
			 try {
				 year = Integer.parseInt(args[0]);
			 }  catch (NumberFormatException ex) {
				 throw new ILLegalYearException("���ָ�ʽת���쳣");
			 }
			 try {
				 salary = Integer.parseInt(args[1]);
			 } catch (NumberFormatException ex) {
				 throw new ILLegalSalaryException("���ָ�ʽת���쳣");
			 }
			 if (salary<500) throw new ILLegalSalaryException("���ʵ���500Ԫ");
			 //���
			 int resultYear = nowYear - year;
			 if (resultYear<0) {
				 throw new ILLegalYearException("��ְ��ݴ��ڽ���");
			 } else if (year<0) {
				 throw new ILLegalYearException("��ְ���Ϊ����");
			 }
			 //�������
			 if (resultYear<1) {
				 salary = salary;
			 } else if (resultYear<3)
			 {
				 salary *= 1.3;
			 } else if (resultYear<5) {
				 salary *= 1.5;
			 } else salary *= 2;
			 System.out.println("��Ա������"+salary);
		 } catch (ILLegalYearException ex) {
			 System.out.println(ex.getMessage());
			 return;
		 } catch (ILLegalSalaryException ex) {
			 System.out.println(ex.getMessage());
			 return;
		 }

	}
}
