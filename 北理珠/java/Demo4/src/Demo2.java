import java.util.*;
public class Demo2 {
	public static void main(String[] args) {
		HashSet<Integer> A = new HashSet<Integer>(),B = new HashSet<Integer>(),C = new HashSet<Integer>();
		int a1[] = {1,2,3,4}, a2[] = {1,3,7,9,11};
		for (int i = 0;i < a1.length;i ++) A.add(a1[i]);
		for (int i = 0;i < a2.length;i ++) B.add(a2[i]);
		C = (HashSet)A.clone();
		
		//�󲢼�
		A.addAll(B);
		System.out.println("A��B�Ĳ�����"+A);
		
		//�󽻼�
		A= (HashSet)C.clone();
		A.retainAll(B);
		System.out.println("A��B�Ľ�����"+A);
		
		//��
		A = (HashSet)C.clone();
		Iterator<Integer> it = B.iterator();
		while (it.hasNext())
		{
			A.remove( it.next());
		}
		//A.removeAll(B);
		System.out.println("A��B�Ĳ��"+A);
	}
}
