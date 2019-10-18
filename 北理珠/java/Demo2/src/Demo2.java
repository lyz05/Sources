
abstract class Animal {
	boolean mammal;			//���鶯��
	boolean carnivorous;	//��ʳ����
	int mood;						//���飬1��ʾ����ã�2��ʾ���鲻��
	
	//���캯��
	Animal() {}
	//һ������´��к��ķ���
	abstract void sayHello();
	//����������к��ķ���
	abstract void sayHello(int moodVal);
	//������������
	abstract void sayAnimalType();
}

//����ӿ�
interface LandAnimal{
	int getNumberOfLegs();				//����м�����
	void sayNumberOfLegs();			//����м�����
}
interface WaterAnimal{
	boolean getGillFlags();							//�Ƿ�����
	boolean getLaysEggs();						//�Ƿ��µ�
	void saySpecialOfWaterAnimal();	//���ˮ������������
}

class Dog extends Animal implements LandAnimal{
	boolean mammal = true;
	boolean carnivorous = true;
	int numberOfLegs = 4;
	Dog() {}
	void sayHello()
	{
		System.out.println("��ͨ������£����˴��к��ķ�ʽΪ��ҡβ��");
	}
	//����������к��ķ���
	void sayHello(int moodVal){
		if(moodVal==1){
			System.out.println("�������������õ�����£����к��ķ�ʽΪ��������");
		}
		else if(moodVal==2){
			System.out.println("�������ʱ�򣬻᣺���ؽ�");
		}
	}
	public int getNumberOfLegs(){
		return numberOfLegs;
	}
	void sayAnimalType() {
		System.out.println("��"+(mammal?"��":"����")+"���鶯��");
		System.out.println("��"+(carnivorous?"��":"����")+"��ʳ����");
	}
	public void sayNumberOfLegs(){
		System.out.println("����"+getNumberOfLegs()+"����");
	}
}

class Cat extends Animal implements LandAnimal{
	boolean mammal = true;
	boolean carnivorous = true;
	int numberOfLegs = 4;
	Cat() {}
	void sayHello()
	{
		System.out.println("èͨ������£����˴��к��ķ�ʽΪ��������");
	}
	//����������к��ķ���
	void sayHello(int moodVal){
		if(moodVal==1){
			System.out.println("è�����������õ�����£����к��ķ�ʽΪ�����๾���");
		}
		else if(moodVal==2){
			System.out.println("è�����ʱ�򣬻᣺˻˻��");
		}
	}
	public int getNumberOfLegs(){
		return numberOfLegs;
	}
	void sayAnimalType() {
		System.out.println("è"+(mammal?"��":"����")+"���鶯��");
		System.out.println("è"+(carnivorous?"��":"����")+"��ʳ����");
	}
	public void sayNumberOfLegs(){
		System.out.println("è��"+getNumberOfLegs()+"����");
	}
}

class Frog extends Animal implements LandAnimal,WaterAnimal{
	boolean mammal = false;
	boolean carnivorous = false;
	int numberOfLegs = 4;
	Frog() {}
	void sayHello()
	{
		System.out.println("����ͨ������£����˴��к��ķ�ʽΪ�����ɽ�");
	}
	//����������к��ķ���
	void sayHello(int moodVal){
		if(moodVal==1){
			System.out.println("���������õ�����£����к��ķ�ʽΪ�����ɽ�");
		}
		else if(moodVal==2){
			System.out.println("���ܷ����ʱ�򣬻᣺��ͨһ������ˮ��");
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
		System.out.println("����"+(mammal?"��":"����")+"���鶯��");
		System.out.println("����"+(carnivorous?"��":"����")+"��ʳ����");
	}
	public void sayNumberOfLegs(){
		System.out.println("������"+getNumberOfLegs()+"����");
	}
	public void saySpecialOfWaterAnimal() {
		System.out.println("���ܲ�"+(getLaysEggs()?"��":"��"));
		System.out.println("����"+(getGillFlags()?"��":"û��")+"��");
	}
}

public class Demo2 {
	static void printSeparate() {
		System.out.println("=================================");
	}
	public static void main(String[] args) {
		//ʵ��������
		Frog frog = new Frog();
		Cat cat = new Cat();
		Dog dog = new Dog();
		
		//��������ʾ
		dog.sayAnimalType();
		dog.sayHello();
		dog.sayHello(1);
		dog.sayHello(2);
		dog.sayNumberOfLegs();
		printSeparate();
		
		//è������ʾ
		cat.sayAnimalType();
		cat.sayHello();
		cat.sayHello(1);
		cat.sayHello(2);
		cat.sayNumberOfLegs();
		printSeparate();
		
		//���ܶ�����ʾ
		frog.sayAnimalType();
		frog.sayHello();
		frog.sayHello(1);
		frog.sayHello(2);
		frog.sayNumberOfLegs();
		frog.saySpecialOfWaterAnimal();
	}
}
