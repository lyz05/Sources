import java.util.*;
import java.util.Map.Entry;
class Car implements Comparable<Car>{
    String carCode; //车辆代号
    String brand; //品牌
    String mode;  //款式
    String color; //颜色
    int price;
       //写构造方法   

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
    
    public int compareTo(Car c){ //比较价格的方法
        //……
    	return c.price-this.price;  //倒序输出的关键
    }
    public void printCarInfo(){ //打印方法
        //……
    	System.out.println(carCode+"\t"+brand+"\t"+mode+"\t"+color+"\t"+price+"\t");
    }
    public void printCarInfo(String key){ //打印方法含日期
        //……
    	System.out.println(carCode+"\t"+brand+"\t"+mode+"\t"+color+"\t"+price+"\t"+key);
    }
}

class CarDealer{ //车行
    String dealerName; //车行名称
    ArrayList<Car> cars;
    //构造方法
    CarDealer(){
    }
    CarDealer(String dealerName){
    	this.dealerName=dealerName;
    	
    }
    void printInfo(){
		System.out.println(dealerName);
	}
    

}
class Customer{ //顾客
    String name;
    HashMap<String,Car> cars; //String是购买日期，Car是该顾客购买的车
    //构造方法
    Customer(){
    	
    }
    Customer(String name){
    	this.name=name;
    	
    }
}

public class TASK_3_1 {
	public static void main(String[] args) {
		//1-实例化三个Car对象
        //2-实例化一个ArrayList泛型集合对象
        //3-把以上三部车加入到这个ArrayList泛型集合里
        //4-实例化一个CarDealer对象
        //5-输出该CarDealer车行所热销的车
        //6-步骤1-5一共重复三次，分别输出三个车行所热销的车
		
		 ArrayList<Car> list1=new ArrayList<Car>();
		 Car c1=new Car("CS1678","丰田","佳美","白色",200000);
		 Car c2=new Car("CS4634","丰田","皇冠","灰色",210000);
		 Car c3=new Car("CS7789","丰田","科罗拉","蓝色",180000);
			list1.add(c1);
			list1.add(c2);
			list1.add(c3);
			Collections.sort(list1); //list1排序
			
			CarDealer cd1=new CarDealer("广汽丰田车行热销车辆");
			System.out.println(cd1.dealerName);
			//打印
			System.out.println("车号\t品牌\t款型\t颜色\t价格");
			System.out.println("======================================");
			for(Car c:list1){
				c.printCarInfo();
			}
			System.out.println("*********************************************");
			
			
			 
		 ArrayList<Car> list2=new ArrayList<Car>();
		 Car c4=new Car("CS2344","本田","飞度","红色",170000);
		 Car c5=new Car("CS9234","本田","雅阁","黑色",220000);
		 Car c6=new Car("CS7789","本田","思域","银色",150000);
			list2.add(c4);
			list2.add(c5);
			list2.add(c6);
			Collections.sort(list2); //list2排序
				
			CarDealer cd2=new CarDealer("广汽本田车行热销车辆");
			System.out.println(cd2.dealerName);
				//打印
			System.out.println("车号\t品牌\t款型\t颜色\t价格");
			System.out.println("======================================");
			for(Car c:list2){//无需类型转换
					c.printCarInfo();
				}
			System.out.println("*********************************************");
			
			
			
		 ArrayList<Car> list3=new ArrayList<Car>();
			 Car c7=new Car("CS4356","别克","凯越","黑色",140000);
			 Car c8=new Car("CS7689","别克","君威","银色",250000);
			 Car c9=new Car("CS8122","别克","阅朗","红色",130000);
				list3.add(c7);
				list3.add(c8);
				list3.add(c9);
			    Collections.sort(list3); //list3排序
					
			CarDealer cd3=new CarDealer("上汽别克车行热销车俩");
			System.out.println(cd3.dealerName);
					//打印
			System.out.println("车号\t品牌\t款型\t颜色\t价格");
			System.out.println("======================================");
			for(Car c:list3){//无需类型转换
						c.printCarInfo();
					}
					
			System.out.println("*********************************************");
			System.out.println("*********************************************");
			
			
			//7-实例化一个HashMap<String,Car>集合对象
	        //8-从上面的车行里挑两部车放进该集合里
	        //9-输出该顾客购买日期和车
	        //10-步骤7-9一共重复两次，分别输出两个顾客所购买的车的信息
					
			HashMap<String,Car>hashMap1=new HashMap<>();
					hashMap1.put("2020-03-08", c1 );
					hashMap1.put("2020-03-21", c4 );
			Customer customer1=new Customer("李伟文");
					
			System.out.println("第一个顾客："+customer1.name+ "\t所买车：");
			System.out.println("车号\t品牌\t款型\t颜色\t价格\t\t日期");
			System.out.println("===================================================");
			Iterator it=hashMap1.keySet().iterator(); //获得键的集合的迭代器
			while(it.hasNext()){ //是否还有下一个键
						String key=(String)it.next();//类型强制转换
						Car value=hashMap1.get(key); //根据键获取值
						value.printCarInfo(key);
						//System.out.println(key);
						
					}
					
					System.out.println("*******************************************");
			HashMap<String,Car>hashMap2=new HashMap<>();
					hashMap2.put("2020-11-11", c2 );
					hashMap2.put("2020-02-08", c7 );
					Customer customer2=new Customer("吴浩强");
					
					System.out.println("第一个顾客："+customer2.name + "\t所买车：");
					System.out.println("车号\t品牌\t款型\t颜色\t价格\t\t日期");
					System.out.println("======================================================");
					Iterator it1=hashMap2.keySet().iterator(); //获得键的集合的迭代器
					while(it1.hasNext()){ //是否还有下一个键
						String key=(String)it1.next();//获得下一个键
						Car value=hashMap2.get(key);//根据键获取值
						value.printCarInfo(key);
						//System.out.println(key);
					}
					
	        //7-实例化一个HashMap<String,Car>集合对象
	        //8-从上面的车行里挑两部车放进该集合里
	        //9-输出该顾客购买日期和车
	        //10-步骤7-9一共重复两次，分别输出两个顾客所购买的车的信息
	    }

}
