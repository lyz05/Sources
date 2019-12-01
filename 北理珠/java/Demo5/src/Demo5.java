import java.util.*;
class Student {
	 //学生类
	String stuID,stuName;	
	Student(String stuID,String stuName) {
		this.stuID = stuID;
		this.stuName = stuName;
	}
}
class Course {
	//课程类
	String courseID,courseName;
	Course(String courseID,String courseName) {
		this.courseID = courseID;
		this.courseName = courseName;
	}
}
class Grade {
	//成绩类
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
		//1--实例化几个学生对象并在泛型集合对象中保存学生的信息
		Student stu1 = new Student("S001","郑东红");
		Student stu2 = new Student("S002","陈明丽");
		Student stu3 = new Student("S003","黄文杰");
		//2--实例化几个课程对象并在泛型集合对象中保存课程的信息
		Course c1 = new Course("C001","嵌入式编程原理");
		Course c2 = new Course("C002","计算机专业英语");
		Course c3 = new Course("C003","微机接口与技术");
		//3--实例化几个成绩对象并在泛型集合对象中保存成绩的信息
		Grade sc11 = new Grade("S001","C001",76);
		Grade sc12 = new Grade("S001","C002",90);
		Grade sc13 = new Grade("S001","C003",67);
		Grade sc21 = new Grade("S002","C001",82);
		Grade sc22 = new Grade("S002","C002",73);
		Grade sc23 = new Grade("S002","C003",85);
		Grade sc31 = new Grade("S003","C001",92);
		Grade sc32 = new Grade("S003","C002",81);
		Grade sc33 = new Grade("S003","C003",83);
		//实例化三种类的泛型集合
		
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
		init();			//实例化对象
		//4--根据成绩泛型集合中的学号和课程编号查询学生集合和课程集合得到学生姓名和课程名称
		//5---输出每个学生各科的成绩
		System.out.println("学号\t\t姓名\t\t课程编号\t课程名称\t\t\t成绩");
		for(Grade g:vGrade){
			for(Student s:vStu){
				if(g.stuID.equals(s.stuID)){
					//若找到了，则输出学号和姓名
					System.out.print(g.stuID+"\t"+s.stuName+"\t");
					break;
				}
			}
			for(Course c:vCourse){
				if(g.courseID.equals(c.courseID)){
					//若找到了，则输出课程编号和课程名称
					System.out.print(g.courseID +"\t"+c.courseName+"\t");
					break;
				}
			}
			System.out.println(g.score);
		}
		//这是一个换行符
		System.out.println("**********************************************************");
		//6--统计每课参加考试的人数和总分
		int[] count=new int[vCourse.size()];  //保存各科参考人数
		int[] sums=new int[vCourse.size()];  //保存各科成绩总分

		//统计学生人数和总分
		for(int i=0;i<vCourse.size();i++){
			for(int j=0;j<vGrade.size();j++){
				if(vCourse.get(i).courseID.equals(vGrade.get(j).courseID)){
					count[i]++; //参考人数+1
					//累计求和
					sums[i]=sums[i]+vGrade.get(j).score; 
				}
			}
		}
		//7--计算并保存每门课程的平均分
		//实例化TreeMap集合用于保存课程编号和平均分
		TreeMap<String,Integer> total = new TreeMap<String,Integer>();
		//计算平均分			
		for(int i=0;i<vCourse.size();i++){
			if(count[i]>0){
				//计算平均分
				sums[i]=sums[i]/count[i]; 
				//保存到集合中
				total.put(vCourse.get(i).courseID,sums[i]);
			}
		}
		//8--打印各科平均分
		System.out.println("课程编号\t课程名称\t\t\t平均分");
	    Set<String> keys = total.keySet();
	    for (String key : keys){
	    	for(Course c:vCourse){
				if(key.equals(c.courseID)){
					//若找到了，则输出课程编号和课程名称
					System.out.print(key +"\t"+c.courseName+"\t");
					break;
				}
			}
	        System.out.println(total.get(key));
	    }
	}
}
