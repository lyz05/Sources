import java.util.*;
class University implements Comparable{
	String uniName;
	int population;
	
	University(String uniName,int population)
	{
		//构造函数
		this.uniName = uniName;
		this.population = population;
	}
	public int compareTo(Object obj){
		//比较函数
		University now=(University)obj;
		return now.population - this.population;
	}
	public String toString() {
		//重写toString
		return uniName+"\t"+population;
	}
}
public class Demo3 {
	static void printTitle()
	{
		//打印抬头
		System.out.println("学校名称\t\t\t\t学生人数");
		System.out.println("**************************************");
	}
	public static void main(String[] args) {
		ArrayList<University> tm = new ArrayList();
		//插入各所大学信息
		tm.add(new University("北京理工大学珠海学院",21000));
		tm.add(new University("北京师范大学珠海学院",25000));
		tm.add(new University("中山大学珠海分校",18000));
		tm.add(new University("吉林大学珠海学院",20000));
		tm.add(new University("暨南大学珠海分校",7000));
		//排序
		Collections.sort(tm);
		//打印输出
		printTitle();
		for (University obj : tm)
		{
			System.out.println(obj);
		}
	}
}
