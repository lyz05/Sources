public class Lab4_1 {
	public static void main (String[] args) {
		float[] a=new float[5];
		float sum=0;
		for(int i=0;i<a.length;i++){
			try{
				a[i]=Float.parseFloat(args[i]);
			} catch (ArrayIndexOutOfBoundsException ex)
			{
				System.out.println("�����±�Խ���쳣��������5����");
				return;
			} catch (NumberFormatException ex)
			{
				System.out.println("���ָ�ʽת���쳣�������븡����");
				return;
			} catch (Exception ex)
			{
				ex.printStackTrace();
			}
			System.out.println ("��"+(i+1)+"�ſγ̵ĳɼ���:"+a[i]);
			sum=sum+a[i];
		}
		System.out.println("�ܳɼ��ǣ�"+sum);
		float avg=sum/a.length;
		System.out.println ("ƽ���ɼ���:"+avg);
    }
}
