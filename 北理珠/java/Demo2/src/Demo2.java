
abstract class Animal {
	boolean mammal;					//���鶯��
	boolean carnivorous;			//��ʳ����
	int mood;						//���飬1��ʾ����ã�2��ʾ���鲻��
	int numberOfLegs;				//�����м�����
	String name;					//���������
	
	//���캯��
	Animal() {}
	//һ������´��к��ķ���
	abstract void sayHello();
	//�Ƿ�������ķ�ʽ���к�
	abstract void sayHello(boolean Bymood);
	//������������
	abstract void sayAnimalType();
	//������
	abstract void setMood(int mood);
	//ȡ����
	abstract int getMood();
}

//����ӿ�
interface LandAnimal{
	int getNumberOfLegs();						//����м�����
	void sayNumberOfLegs();						//����м�����
}
interface WaterAnimal{
	boolean getGillFlags();						//�Ƿ�����
	boolean getLaysEggs();						//�Ƿ��µ�
	void saySpecialOfWaterAnimal();				//���ˮ������������
}

class Dog extends Animal implements LandAnimal{
	Dog() {
		name  = "��";
		numberOfLegs = 4;
		carnivorous = true;
		mammal = true;
	}
	void sayHello()
	{
		System.out.println(name+"ͨ������£����˴��к��ķ�ʽΪ��ҡβ��");
	}
	//����������к��ķ���
	void sayHello(boolean byMood){
		if (byMood)
		{
			if(getMood() == 1){
				System.out.println(name+"�����������õ�����£����к��ķ�ʽΪ��������");
			}
			else if(getMood() == 2){
				System.out.println(name+"�����ʱ�򣬻᣺���ؽ�");
			}
		} else sayHello();
	}
	public int getNumberOfLegs(){
		return numberOfLegs;
	}
	void sayAnimalType() {
		System.out.println(name+(mammal?"��":"����")+"���鶯��");
		System.out.println(name+(carnivorous?"��":"����")+"��ʳ����");
	}
	public void sayNumberOfLegs(){
		System.out.println(name+"��"+getNumberOfLegs()+"����");
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
		name  = "è";
		numberOfLegs = 4;
		carnivorous = true;
		mammal = true;
	}
	void sayHello()
	{
		System.out.println(name+"ͨ������£����˴��к��ķ�ʽΪ��������");
	}
	//����������к��ķ���
	void sayHello(boolean byMood){
		if (byMood)
		{
			if(getMood() == 1){
				System.out.println(name+"�����������õ�����£����к��ķ�ʽΪ�����๾���");
			}
			else if(getMood() == 2){
				System.out.println(name+"�����ʱ�򣬻᣺˻˻��");
			}
		} else sayHello();
	}
	public int getNumberOfLegs(){
		return numberOfLegs;
	}
	void sayAnimalType() {
		System.out.println(name+(mammal?"��":"����")+"���鶯��");
		System.out.println(name+(carnivorous?"��":"����")+"��ʳ����");
	}
	public void sayNumberOfLegs(){
		System.out.println(name+"��"+getNumberOfLegs()+"����");
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
		name  = "����";
		numberOfLegs = 4;
		carnivorous = false;
		mammal = false;	
	}
	void sayHello()
	{
		System.out.println(name+"ͨ������£����˴��к��ķ�ʽΪ�����ɽ�");
	}
	//����������к��ķ���
	void sayHello(boolean byMood){
		if (byMood)
		{
			if(getMood() == 1){
				System.out.println(name+"�����������õ�����£����к��ķ�ʽΪ�����ɽ�");
			}
			else if(getMood() == 2){
				System.out.println(name+"�����ʱ�򣬻᣺��ͨһ������ˮ��");
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
		System.out.println(name+(mammal?"��":"����")+"���鶯��");
		System.out.println(name+(carnivorous?"��":"����")+"��ʳ����");
	}
	public void sayNumberOfLegs(){
		System.out.println(name+"��"+getNumberOfLegs()+"����");
	}
	public void saySpecialOfWaterAnimal() {
		System.out.println(name+"��"+(getLaysEggs()?"��":"��"));
		System.out.println(name+""+(getGillFlags()?"��":"û��")+"��");
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
	//����ָ���
	static void printSeparate() {
		System.out.println("=============================================");
	}
	public static void main(String[] args) {
		//ʵ��������
		Dog dog = new Dog();
		Cat cat = new Cat();
		Frog frog = new Frog();
		
		//��������ʾ
		dog.sayAnimalType();
		dog.sayHello();
		dog.setMood(1);
		dog.sayHello(true);
		dog.setMood(2);
		dog.sayHello(true);
		dog.sayNumberOfLegs();
		printSeparate();
		
		//è������ʾ
		cat.sayAnimalType();
		cat.sayHello();
		cat.setMood(1);
		cat.sayHello(true);
		cat.setMood(2);
		cat.sayHello(true);
		cat.sayNumberOfLegs();
		printSeparate();
		
		//���ܶ�����ʾ
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
