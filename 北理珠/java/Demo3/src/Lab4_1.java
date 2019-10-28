public class Lab4_1 {
	public static void main (String[] args) {
		float[] a=new float[5];
		float sum=0;
		for(int i=0;i<a.length;i++){
			try{
				a[i]=Float.parseFloat(args[i]);
			} catch (ArrayIndexOutOfBoundsException ex)
			{
				System.out.println("数组下标越界异常：请输入5个数");
				return;
			} catch (NumberFormatException ex)
			{
				System.out.println("数字格式转换异常：请输入浮点数");
				return;
			} catch (Exception ex)
			{
				ex.printStackTrace();
			}
			System.out.println ("第"+(i+1)+"门课程的成绩是:"+a[i]);
			sum=sum+a[i];
		}
		System.out.println("总成绩是："+sum);
		float avg=sum/a.length;
		System.out.println ("平均成绩是:"+avg);
    }
}
