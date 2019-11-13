import java.util.*;
public class Demo1 {
	public static void main(String[] args) {
		Random r = new Random();				//生成随机数函数
		int[] count = new int [13];					//存放结果数组
		int tot = 5000;
		for (int i=1;i<=tot;i ++)
		{
			int n1 = r.nextInt(6)+1,n2 = r.nextInt(6)+1;	//随机摇骰子两次
			count[n1+n2] ++;											//统计各个结果出现次数
		}
		//输出投5000次骰子信息
		for (int i=2;i<=6+6;i ++)
		{
			System.out.print(i+":"+count[i]+"次\t");
			if (i==7) System.out.println();
		}
	}
}
