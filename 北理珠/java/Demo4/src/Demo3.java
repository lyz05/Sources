import java.util.*;
class University implements Comparable{
	String uniName;
	int population;
	
	University(String uniName,int population)
	{
		//���캯��
		this.uniName = uniName;
		this.population = population;
	}
	public int compareTo(Object obj){
		//�ȽϺ���
		University now=(University)obj;
		return now.population - this.population;
	}
	public String toString() {
		//��дtoString
		return uniName+"\t"+population;
	}
}
public class Demo3 {
	static void printTitle()
	{
		//��ӡ̧ͷ
		System.out.println("ѧУ����\t\t\t\tѧ������");
		System.out.println("**************************************");
	}
	public static void main(String[] args) {
		ArrayList<University> tm = new ArrayList();
		//���������ѧ��Ϣ
		tm.add(new University("��������ѧ�麣ѧԺ",21000));
		tm.add(new University("����ʦ����ѧ�麣ѧԺ",25000));
		tm.add(new University("��ɽ��ѧ�麣��У",18000));
		tm.add(new University("���ִ�ѧ�麣ѧԺ",20000));
		tm.add(new University("���ϴ�ѧ�麣��У",7000));
		//����
		Collections.sort(tm);
		//��ӡ���
		printTitle();
		for (University obj : tm)
		{
			System.out.println(obj);
		}
	}
}
