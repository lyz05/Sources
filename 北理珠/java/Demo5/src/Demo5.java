import java.util.*;
class Student {
	 //ѧ����
	String stuID,stuName;	
	Student(String stuID,String stuName) {
		this.stuID = stuID;
		this.stuName = stuName;
	}
}
class Course {
	//�γ���
	String courseID,courseName;
	Course(String courseID,String courseName) {
		this.courseID = courseID;
		this.courseName = courseName;
	}
}
class Grade {
	//�ɼ���
	String stuID,courseID;
	int score;
	Grade(String stuID,String CourseID,int score) {
		this.stuID = stuID;
		this.courseID = CourseID;
		this.score = score;
	}
}

public class Demo5 {
	static Vector<Student> vStu = new Vector<Student>();
	static Vector<Course> vCourse = new Vector<Course>();
	static Vector<Grade> vGrade = new Vector<Grade>();
	static void init() {
		//1--ʵ��������ѧ�������ڷ��ͼ��϶����б���ѧ������Ϣ
		Student stu1 = new Student("S001","֣����");
		Student stu2 = new Student("S002","������");
		Student stu3 = new Student("S003","���Ľ�");
		//2--ʵ���������γ̶����ڷ��ͼ��϶����б���γ̵���Ϣ
		Course c1 = new Course("C001","Ƕ��ʽ���ԭ��");
		Course c2 = new Course("C002","�����רҵӢ��");
		Course c3 = new Course("C003","΢���ӿ��뼼��");
		//3--ʵ���������ɼ������ڷ��ͼ��϶����б���ɼ�����Ϣ
		Grade sc11 = new Grade("S001","C001",76);
		Grade sc12 = new Grade("S001","C002",90);
		Grade sc13 = new Grade("S001","C003",67);
		Grade sc21 = new Grade("S002","C001",82);
		Grade sc22 = new Grade("S002","C002",73);
		Grade sc23 = new Grade("S002","C003",85);
		Grade sc31 = new Grade("S003","C001",92);
		Grade sc32 = new Grade("S003","C002",81);
		Grade sc33 = new Grade("S003","C003",83);
		//ʵ����������ķ��ͼ���
		
		vStu.add(stu1);
		vStu.add(stu2);
		vStu.add(stu3);
		
		vCourse.add(c1);
		vCourse.add(c2);
		vCourse.add(c3);
		
		vGrade.add(sc11);
		vGrade.add(sc12);
		vGrade.add(sc13);
		vGrade.add(sc21);
		vGrade.add(sc22);
		vGrade.add(sc23);
		vGrade.add(sc31);
		vGrade.add(sc32);
		vGrade.add(sc33);
	}
	public static void main(String[] args) {
		init();			//ʵ��������
		//4--���ݳɼ����ͼ����е�ѧ�źͿγ̱�Ų�ѯѧ�����ϺͿγ̼��ϵõ�ѧ�������Ϳγ�����
		//5---���ÿ��ѧ�����Ƶĳɼ�
		System.out.println("ѧ��\t\t����\t\t�γ̱��\t�γ�����\t\t\t�ɼ�");
		for(Grade g:vGrade){
			for(Student s:vStu){
				if(g.stuID.equals(s.stuID)){
					//���ҵ��ˣ������ѧ�ź�����
					System.out.print(g.stuID+"\t"+s.stuName+"\t");
					break;
				}
			}
			for(Course c:vCourse){
				if(g.courseID.equals(c.courseID)){
					//���ҵ��ˣ�������γ̱�źͿγ�����
					System.out.print(g.courseID +"\t"+c.courseName+"\t");
					break;
				}
			}
			System.out.println(g.score);
		}
		//����һ�����з�
		System.out.println("**********************************************************");
		//6--ͳ��ÿ�βμӿ��Ե��������ܷ�
		int[] count=new int[vCourse.size()];  //������Ʋο�����
		int[] sums=new int[vCourse.size()];  //������Ƴɼ��ܷ�

		//ͳ��ѧ���������ܷ�
		for(int i=0;i<vCourse.size();i++){
			for(int j=0;j<vGrade.size();j++){
				if(vCourse.get(i).courseID.equals(vGrade.get(j).courseID)){
					count[i]++; //�ο�����+1
					//�ۼ����
					sums[i]=sums[i]+vGrade.get(j).score; 
				}
			}
		}
		//7--���㲢����ÿ�ſγ̵�ƽ����
		//ʵ����TreeMap�������ڱ���γ̱�ź�ƽ����
		TreeMap<String,Integer> total = new TreeMap<String,Integer>();
		//����ƽ����			
		for(int i=0;i<vCourse.size();i++){
			if(count[i]>0){
				//����ƽ����
				sums[i]=sums[i]/count[i]; 
				//���浽������
				total.put(vCourse.get(i).courseID,sums[i]);
			}
		}
		//8--��ӡ����ƽ����
		System.out.println("�γ̱��\t�γ�����\t\t\tƽ����");
	    Set<String> keys = total.keySet();
	    for (String key : keys){
	    	for(Course c:vCourse){
				if(key.equals(c.courseID)){
					//���ҵ��ˣ�������γ̱�źͿγ�����
					System.out.print(key +"\t"+c.courseName+"\t");
					break;
				}
			}
	        System.out.println(total.get(key));
	    }
	}
}
