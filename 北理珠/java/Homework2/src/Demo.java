import java.util.*;

import javax.management.RuntimeErrorException;

public class Demo {     
	public void evaluate1(List<? extends Person> list){
		list.add(new Student("Jack",21,"�����"));
		list.add(new Teacher("Amy",21,"��ʦ"));
	}

    public static void main(String[] args){
    	try {
    		System.out.println(10/0);
    	}catch (Exception e)
    	{
    		e.printStackTrace();
    	} catch (ArithmeticException e)
    	{
    		e.printStackTrace();
    	}
    }
}

