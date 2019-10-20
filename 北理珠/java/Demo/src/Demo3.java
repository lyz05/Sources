
public class Demo3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		if (args.length!=10) {
			System.out.println("Invaild Input!");
			return;
		}
		int sum = 0,max = 0,min = (int)1e9+7;
		double avg = 0;
		for (int i=0;i<args.length;i ++) {
			int t = Integer.parseInt(args[i]);
			sum += t;
			max = Math.max(max, t);
			min = Math.min(min, t);
		}
		avg = 1.0*sum/args.length;
		System.out.println("Sum:"+sum+"\tAvg:"+avg+"\nMax:"+max+"\tMin:"+min);
	}
}
