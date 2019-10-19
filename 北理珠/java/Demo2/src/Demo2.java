
abstract class Animal {
	boolean mammal;					//哺乳动物
	boolean carnivorous;			//肉食动物
	int mood;						//心情，1表示心情好，2表示心情不好
	int numberOfLegs;				//动物有几条腿
	String name;					//动物的名字
	
	//构造函数
	Animal() {}
	//一般情况下打招呼的方法
	abstract void sayHello();
	//是否以心情的方式打招呼
	abstract void sayHello(boolean Bymood);
	//输出动物的类型
	abstract void sayAnimalType();
	//置心情
	abstract void setMood(int mood);
	//取心情
	abstract int getMood();
}

//定义接口
interface LandAnimal{
	int getNumberOfLegs();						//获得有几条腿
	void sayNumberOfLegs();						//输出有几条腿
}
interface WaterAnimal{
	boolean getGillFlags();						//是否有腮
	boolean getLaysEggs();						//是否下蛋
	void saySpecialOfWaterAnimal();				//输出水生动物特殊性
}

class Dog extends Animal implements LandAnimal{
	Dog() {
		name  = "狗";
		numberOfLegs = 4;
		carnivorous = true;
		mammal = true;
	}
	void sayHello()
	{
		System.out.println(name+"通常情况下，和人打招呼的方式为：摇尾巴");
	}
	//根据心情打招呼的方法
	void sayHello(boolean byMood){
		if (byMood)
		{
			if(getMood() == 1){
				System.out.println(name+"被抚摸情绪好的情况下，打招呼的方式为：汪汪叫");
			}
			else if(getMood() == 2){
				System.out.println(name+"烦躁的时候，会：呜呜叫");
			}
		} else sayHello();
	}
	public int getNumberOfLegs(){
		return numberOfLegs;
	}
	void sayAnimalType() {
		System.out.println(name+(mammal?"是":"不是")+"哺乳动物");
		System.out.println(name+(carnivorous?"是":"不是")+"肉食动物");
	}
	public void sayNumberOfLegs(){
		System.out.println(name+"有"+getNumberOfLegs()+"条腿");
	}
	void setMood(int mood)
	{
		this.mood = mood;
	}
	int getMood()
	{
		return mood;
	}
}

class Cat extends Animal implements LandAnimal{

	Cat() {
		name  = "猫";
		numberOfLegs = 4;
		carnivorous = true;
		mammal = true;
	}
	void sayHello()
	{
		System.out.println(name+"通常情况下，和人打招呼的方式为：喵喵叫");
	}
	//根据心情打招呼的方法
	void sayHello(boolean byMood){
		if (byMood)
		{
			if(getMood() == 1){
				System.out.println(name+"被抚摸情绪好的情况下，打招呼的方式为：咕噜咕噜叫");
			}
			else if(getMood() == 2){
				System.out.println(name+"烦躁的时候，会：嘶嘶叫");
			}
		} else sayHello();
	}
	public int getNumberOfLegs(){
		return numberOfLegs;
	}
	void sayAnimalType() {
		System.out.println(name+(mammal?"是":"不是")+"哺乳动物");
		System.out.println(name+(carnivorous?"是":"不是")+"肉食动物");
	}
	public void sayNumberOfLegs(){
		System.out.println(name+"有"+getNumberOfLegs()+"条腿");
	}
	void setMood(int mood)
	{
		this.mood = mood;
	}
	int getMood()
	{
		return mood;
	}
}

class Frog extends Animal implements LandAnimal,WaterAnimal{
	
	Frog() {
		name  = "青蛙";
		numberOfLegs = 4;
		carnivorous = false;
		mammal = false;	
	}
	void sayHello()
	{
		System.out.println(name+"通常情况下，和人打招呼的方式为：呱呱叫");
	}
	//根据心情打招呼的方法
	void sayHello(boolean byMood){
		if (byMood)
		{
			if(getMood() == 1){
				System.out.println(name+"被抚摸情绪好的情况下，打招呼的方式为：呱呱叫");
			}
			else if(getMood() == 2){
				System.out.println(name+"烦躁的时候，会：扑通一声跳入水中");
			}
		} else sayHello();
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
		System.out.println(name+(mammal?"是":"不是")+"哺乳动物");
		System.out.println(name+(carnivorous?"是":"不是")+"肉食动物");
	}
	public void sayNumberOfLegs(){
		System.out.println(name+"有"+getNumberOfLegs()+"条腿");
	}
	public void saySpecialOfWaterAnimal() {
		System.out.println(name+"产"+(getLaysEggs()?"蛋":"卵"));
		System.out.println(name+""+(getGillFlags()?"有":"没有")+"腮");
	}
	void setMood(int mood)
	{
		this.mood = mood;
	}
	int getMood()
	{
		return mood;
	}
}

public class Demo2 {
	//输出分隔符
	static void printSeparate() {
		System.out.println("=============================================");
	}
	public static void main(String[] args) {
		//实例化对象
		Dog dog = new Dog();
		Cat cat = new Cat();
		Frog frog = new Frog();
		
		//狗对象显示
		dog.sayAnimalType();
		dog.sayHello();
		dog.setMood(1);
		dog.sayHello(true);
		dog.setMood(2);
		dog.sayHello(true);
		dog.sayNumberOfLegs();
		printSeparate();
		
		//猫对象显示
		cat.sayAnimalType();
		cat.sayHello();
		cat.setMood(1);
		cat.sayHello(true);
		cat.setMood(2);
		cat.sayHello(true);
		cat.sayNumberOfLegs();
		printSeparate();
		
		//青蛙对象显示
		frog.sayAnimalType();
		frog.sayHello();
		frog.setMood(1);
		frog.sayHello(true);
		frog.setMood(2);
		frog.sayHello(true);
		frog.sayNumberOfLegs();
		frog.saySpecialOfWaterAnimal();
	}
}
