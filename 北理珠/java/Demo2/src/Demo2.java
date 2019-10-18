
abstract class Animal {
	boolean mammal;			//哺乳动物
	boolean carnivorous;	//肉食动物
	int mood;						//心情，1表示心情好，2表示心情不好
	
	//构造函数
	Animal() {}
	//一般情况下打招呼的方法
	abstract void sayHello();
	//根据心情打招呼的方法
	abstract void sayHello(int moodVal);
	//输出动物的类型
	abstract void sayAnimalType();
}

//定义接口
interface LandAnimal{
	int getNumberOfLegs();				//获得有几条腿
	void sayNumberOfLegs();			//输出有几条腿
}
interface WaterAnimal{
	boolean getGillFlags();							//是否有腮
	boolean getLaysEggs();						//是否下蛋
	void saySpecialOfWaterAnimal();	//输出水生动物特殊性
}

class Dog extends Animal implements LandAnimal{
	boolean mammal = true;
	boolean carnivorous = true;
	int numberOfLegs = 4;
	Dog() {}
	void sayHello()
	{
		System.out.println("狗通常情况下，和人打招呼的方式为：摇尾巴");
	}
	//根据心情打招呼的方法
	void sayHello(int moodVal){
		if(moodVal==1){
			System.out.println("狗被抚摸情绪好的情况下，打招呼的方式为：汪汪叫");
		}
		else if(moodVal==2){
			System.out.println("狗烦躁的时候，会：呜呜叫");
		}
	}
	public int getNumberOfLegs(){
		return numberOfLegs;
	}
	void sayAnimalType() {
		System.out.println("狗"+(mammal?"是":"不是")+"哺乳动物");
		System.out.println("狗"+(carnivorous?"是":"不是")+"肉食动物");
	}
	public void sayNumberOfLegs(){
		System.out.println("狗有"+getNumberOfLegs()+"条腿");
	}
}

class Cat extends Animal implements LandAnimal{
	boolean mammal = true;
	boolean carnivorous = true;
	int numberOfLegs = 4;
	Cat() {}
	void sayHello()
	{
		System.out.println("猫通常情况下，和人打招呼的方式为：喵喵叫");
	}
	//根据心情打招呼的方法
	void sayHello(int moodVal){
		if(moodVal==1){
			System.out.println("猫被抚摸情绪好的情况下，打招呼的方式为：咕噜咕噜叫");
		}
		else if(moodVal==2){
			System.out.println("猫烦躁的时候，会：嘶嘶叫");
		}
	}
	public int getNumberOfLegs(){
		return numberOfLegs;
	}
	void sayAnimalType() {
		System.out.println("猫"+(mammal?"是":"不是")+"哺乳动物");
		System.out.println("猫"+(carnivorous?"是":"不是")+"肉食动物");
	}
	public void sayNumberOfLegs(){
		System.out.println("猫有"+getNumberOfLegs()+"条腿");
	}
}

class Frog extends Animal implements LandAnimal,WaterAnimal{
	boolean mammal = false;
	boolean carnivorous = false;
	int numberOfLegs = 4;
	Frog() {}
	void sayHello()
	{
		System.out.println("青蛙通常情况下，和人打招呼的方式为：呱呱叫");
	}
	//根据心情打招呼的方法
	void sayHello(int moodVal){
		if(moodVal==1){
			System.out.println("青蛙情绪好的情况下，打招呼的方式为：呱呱叫");
		}
		else if(moodVal==2){
			System.out.println("青蛙烦躁的时候，会：扑通一声跳入水中");
		}
	}
	public boolean getGillFlags(){	
		return true;
	}
	public boolean getLaysEggs() {
		return false;
	}
	public int getNumberOfLegs(){
		return numberOfLegs;
	}
	void sayAnimalType() {
		System.out.println("青蛙"+(mammal?"是":"不是")+"哺乳动物");
		System.out.println("青蛙"+(carnivorous?"是":"不是")+"肉食动物");
	}
	public void sayNumberOfLegs(){
		System.out.println("青蛙有"+getNumberOfLegs()+"条腿");
	}
	public void saySpecialOfWaterAnimal() {
		System.out.println("青蛙产"+(getLaysEggs()?"蛋":"卵"));
		System.out.println("青蛙"+(getGillFlags()?"有":"没有")+"腮");
	}
}

public class Demo2 {
	static void printSeparate() {
		System.out.println("=================================");
	}
	public static void main(String[] args) {
		//实例化对象
		Frog frog = new Frog();
		Cat cat = new Cat();
		Dog dog = new Dog();
		
		//狗对象显示
		dog.sayAnimalType();
		dog.sayHello();
		dog.sayHello(1);
		dog.sayHello(2);
		dog.sayNumberOfLegs();
		printSeparate();
		
		//猫对象显示
		cat.sayAnimalType();
		cat.sayHello();
		cat.sayHello(1);
		cat.sayHello(2);
		cat.sayNumberOfLegs();
		printSeparate();
		
		//青蛙对象显示
		frog.sayAnimalType();
		frog.sayHello();
		frog.sayHello(1);
		frog.sayHello(2);
		frog.sayNumberOfLegs();
		frog.saySpecialOfWaterAnimal();
	}
}
