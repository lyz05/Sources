
public class Demo1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		for (int i=1;i<10;i ++) {
			for (int j=1;j<=9-i;j ++) System.out.print(" ");
			for (int j=1;j<=2*i-1;j ++) System.out.print(i);
			System.out.println();
		}
		for (int i=7;i>=0;i --) {
			for (int j=8-i;j>=1;j --) System.out.print(" ");
			for (int j=2*(i+1)-1;j>=1;j --) System.out.print((char)(i+'A'));
			System.out.println();
		}
	}

}
