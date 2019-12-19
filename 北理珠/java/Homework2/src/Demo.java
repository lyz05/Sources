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
    	Student stu=new Student("李红","女");
		   System.out.println ("姓名:"+stu.getName());
		   System.out.println ("性别:"+stu.getSex());
    }
}

