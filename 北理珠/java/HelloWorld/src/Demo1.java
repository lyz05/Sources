public class Demo1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n = 9;
			for(int i = 1; i <= n; i++) {
				for (int k = 1; k <= n - i; k++) {
					System.out.print(' ');
				}
				for (int j = 1; j <= 2 * i - 1; j++) {
						System.out.print(i);		
				}
				System.out.println();
			}
			
			
			for(int i = n - 1; i >= 1; i--) {
				for (int k = 1; k <= n - i; k++) {
					System.out.print(' ');
				}
				for (int j = 1; j <= 2 * i - 1; j++) {
						System.out.print((char)(i + 64));
				}
				System.out.println();
			}
	}

}