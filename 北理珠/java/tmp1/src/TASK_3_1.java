import java.util.*;
import java.util.Map.Entry;
class Car implements Comparable<Car>{
    String carCode; //��������
    String brand; //Ʒ��
    String mode;  //��ʽ
    String color; //��ɫ
    int price;
       //д���췽��   

    Car(){
    	
    }
    Car(String carCode,String brand,String mode,String color,int price){
    	this.carCode=carCode;
    	this.brand=brand;
    	this.mode=mode;
    	this.color=color;
    	this.price=price;
    	
    }           
 
	public int compare(Car c1, Car c2) {
		return c2.price-c1.price;
	}
    
    public int compareTo(Car c){ //�Ƚϼ۸�ķ���
        //����
    	return c.price-this.price;  //��������Ĺؼ�
    }
    public void printCarInfo(){ //��ӡ����
        //����
    	System.out.println(carCode+"\t"+brand+"\t"+mode+"\t"+color+"\t"+price+"\t");
    }
    public void printCarInfo(String key){ //��ӡ����������
        //����
    	System.out.println(carCode+"\t"+brand+"\t"+mode+"\t"+color+"\t"+price+"\t"+key);
    }
}

class CarDealer{ //����
    String dealerName; //��������
    ArrayList<Car> cars;
    //���췽��
    CarDealer(){
    }
    CarDealer(String dealerName){
    	this.dealerName=dealerName;
    	
    }
    void printInfo(){
		System.out.println(dealerName);
	}
    

}
class Customer{ //�˿�
    String name;
    HashMap<String,Car> cars; //String�ǹ������ڣ�Car�Ǹù˿͹���ĳ�
    //���췽��
    Customer(){
    	
    }
    Customer(String name){
    	this.name=name;
    	
    }
}

public class TASK_3_1 {
	public static void main(String[] args) {
		//1-ʵ��������Car����
        //2-ʵ����һ��ArrayList���ͼ��϶���
        //3-���������������뵽���ArrayList���ͼ�����
        //4-ʵ����һ��CarDealer����
        //5-�����CarDealer�����������ĳ�
        //6-����1-5һ���ظ����Σ��ֱ�������������������ĳ�
		
		 ArrayList<Car> list1=new ArrayList<Car>();
		 Car c1=new Car("CS1678","����","����","��ɫ",200000);
		 Car c2=new Car("CS4634","����","�ʹ�","��ɫ",210000);
		 Car c3=new Car("CS7789","����","������","��ɫ",180000);
			list1.add(c1);
			list1.add(c2);
			list1.add(c3);
			Collections.sort(list1); //list1����
			
			CarDealer cd1=new CarDealer("�������ﳵ����������");
			System.out.println(cd1.dealerName);
			//��ӡ
			System.out.println("����\tƷ��\t����\t��ɫ\t�۸�");
			System.out.println("======================================");
			for(Car c:list1){
				c.printCarInfo();
			}
			System.out.println("*********************************************");
			
			
			 
		 ArrayList<Car> list2=new ArrayList<Car>();
		 Car c4=new Car("CS2344","����","�ɶ�","��ɫ",170000);
		 Car c5=new Car("CS9234","����","�Ÿ�","��ɫ",220000);
		 Car c6=new Car("CS7789","����","˼��","��ɫ",150000);
			list2.add(c4);
			list2.add(c5);
			list2.add(c6);
			Collections.sort(list2); //list2����
				
			CarDealer cd2=new CarDealer("�������ﳵ����������");
			System.out.println(cd2.dealerName);
				//��ӡ
			System.out.println("����\tƷ��\t����\t��ɫ\t�۸�");
			System.out.println("======================================");
			for(Car c:list2){//��������ת��
					c.printCarInfo();
				}
			System.out.println("*********************************************");
			
			
			
		 ArrayList<Car> list3=new ArrayList<Car>();
			 Car c7=new Car("CS4356","���","��Խ","��ɫ",140000);
			 Car c8=new Car("CS7689","���","����","��ɫ",250000);
			 Car c9=new Car("CS8122","���","����","��ɫ",130000);
				list3.add(c7);
				list3.add(c8);
				list3.add(c9);
			    Collections.sort(list3); //list3����
					
			CarDealer cd3=new CarDealer("������˳�����������");
			System.out.println(cd3.dealerName);
					//��ӡ
			System.out.println("����\tƷ��\t����\t��ɫ\t�۸�");
			System.out.println("======================================");
			for(Car c:list3){//��������ת��
						c.printCarInfo();
					}
					
			System.out.println("*********************************************");
			System.out.println("*********************************************");
			
			
			//7-ʵ����һ��HashMap<String,Car>���϶���
	        //8-������ĳ��������������Ž��ü�����
	        //9-����ù˿͹������ںͳ�
	        //10-����7-9һ���ظ����Σ��ֱ���������˿�������ĳ�����Ϣ
					
			HashMap<String,Car>hashMap1=new HashMap<>();
					hashMap1.put("2020-03-08", c1 );
					hashMap1.put("2020-03-21", c4 );
			Customer customer1=new Customer("��ΰ��");
					
			System.out.println("��һ���˿ͣ�"+customer1.name+ "\t���򳵣�");
			System.out.println("����\tƷ��\t����\t��ɫ\t�۸�\t\t����");
			System.out.println("===================================================");
			Iterator it=hashMap1.keySet().iterator(); //��ü��ļ��ϵĵ�����
			while(it.hasNext()){ //�Ƿ�����һ����
						String key=(String)it.next();//����ǿ��ת��
						Car value=hashMap1.get(key); //���ݼ���ȡֵ
						value.printCarInfo(key);
						//System.out.println(key);
						
					}
					
					System.out.println("*******************************************");
			HashMap<String,Car>hashMap2=new HashMap<>();
					hashMap2.put("2020-11-11", c2 );
					hashMap2.put("2020-02-08", c7 );
					Customer customer2=new Customer("���ǿ");
					
					System.out.println("��һ���˿ͣ�"+customer2.name + "\t���򳵣�");
					System.out.println("����\tƷ��\t����\t��ɫ\t�۸�\t\t����");
					System.out.println("======================================================");
					Iterator it1=hashMap2.keySet().iterator(); //��ü��ļ��ϵĵ�����
					while(it1.hasNext()){ //�Ƿ�����һ����
						String key=(String)it1.next();//�����һ����
						Car value=hashMap2.get(key);//���ݼ���ȡֵ
						value.printCarInfo(key);
						//System.out.println(key);
					}
					
	        //7-ʵ����һ��HashMap<String,Car>���϶���
	        //8-������ĳ��������������Ž��ü�����
	        //9-����ù˿͹������ںͳ�
	        //10-����7-9һ���ظ����Σ��ֱ���������˿�������ĳ�����Ϣ
	    }

}
