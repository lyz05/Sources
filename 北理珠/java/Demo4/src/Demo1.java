import java.util.*;
public class Demo1 {
	public static void main(String[] args) {
		Random r = new Random();				//�������������
		int[] count = new int [13];					//��Ž������
		int tot = 5000;
		for (int i=1;i<=tot;i ++)
		{
			int n1 = r.nextInt(6)+1,n2 = r.nextInt(6)+1;	//���ҡ��������
			count[n1+n2] ++;											//ͳ�Ƹ���������ִ���
		}
		//���Ͷ5000��������Ϣ
		for (int i=2;i<=6+6;i ++)
		{
			System.out.print(i+":"+count[i]+"��\t");
			if (i==7) System.out.println();
		}
	}
}
