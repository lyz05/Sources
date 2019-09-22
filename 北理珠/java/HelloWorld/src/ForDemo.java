import java.util.*;

public class ForDemo {

	public static void main(String[] args) {
		//99乘法表
		System.out.println("打印的99乘法表：");
		for (int i = 1 ; i < 10;i ++) {
			for (int j = 1; j <= i ; j ++) {
				System.out.print(j+"*"+i+"="+(i*j)+"\t");
			}
			System.out.println();
		}
		//打印菱形
		Scanner sc = new Scanner(System.in);
		System.out.println("请输入打印的菱形大小：");
		int n;
		n = sc.nextInt();
		System.out.println(n);
		for (int i=1;i<=n;i ++) {
			for (int j=1;j<=n-i;j ++) System.out.print(" ");
			for (int j=1;j<=2*i-1;j ++) System.out.print("*");
			System.out.println();
		}
		for (int i=n;i>0;i --) {
			for (int j=1;j<=n-i;j ++) System.out.print(" ");
			for (int j=1;j<=2*i-1;j ++) System.out.print("*");
			System.out.println();
		}
		sc.close();
	}

}
