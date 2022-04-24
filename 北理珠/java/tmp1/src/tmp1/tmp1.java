package tmp1;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class tmp1 {

	public static int length(int x) {
		int ret = 1;
		while (x!=0) {
			ret *= 10;
			x /= 10;
		}
		return ret/10;
	}
	
	public static ArrayList func(int l,int r) {
		if (l==r) {
			return new ArrayList(Arrays.asList(l)){
				@Override
				public String toString() {
					//重写toString()
					return ""+this.get(0);
				}
			};
		}
		
		ArrayList ret = new ArrayList();
		for (int i=1;i<=10;i ++) {
			int len=length(r-l+1);
			if (len==r-l+1) len /= 10;
			int L = l+len*(i-1),R = l+len*i-1;
			if (R>r) R = r;
			if (L>R) break;
			ret.add(func(L,R));
		}
		return ret;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); 
		int n = sc.nextInt(); 
		ArrayList ans = func(1,n);
		System.out.println(ans);
	}

}
