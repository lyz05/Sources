class Student<T>{
	T name;
	T sex;
	Student(T name,T sex){
		this.name=name;
		this.sex=sex;
	}
	T getName(){
		return name;
	}
	T getSex(){
		return sex;
	}
}
public class Demo {     	
    public static void main(){
    	Student stu=new Student("���","Ů");
		   System.out.println ("����:"+stu.getName());
		   System.out.println ("�Ա�:"+stu.getSex());
    }
}

