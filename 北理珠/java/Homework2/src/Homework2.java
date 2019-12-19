import java.sql.*;
import java.util.*;

public class Homework2 {
    public static Connection JdbcCon(){
        try{
            //--2 加载数据库驱动程序
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            //--3 创建连接
            String url="jdbc:sqlserver://localhost:1433;databaseName=StuDB";
            Connection conn=DriverManager.getConnection(url,"sa","");
            return conn ;//返回创建的数据库连接对象
        }catch(ClassNotFoundException ex){//捕获驱动程序找不到异常
            ex.printStackTrace();
            System.out.println("数据库驱动程序加载失败");
            return null;
        }catch(SQLException ex){//捕获数据库连接失败异常
            ex.printStackTrace();
            System.out.println("数据库连接失败");
            return null;
        }
    }
    
    //查询数据(返回二维Vector集合)
    public static Vector<Vector<String>> queryVectorStudents(String sql){
        Connection conn=JdbcCon();
        Statement stmt; //会话对象
        ResultSet rs; //结果集
        try{
            //创建会话对象
            stmt=conn.createStatement();
            //执行SQL语句
            rs=stmt.executeQuery(sql);
            Vector<Vector<String>> data=new Vector<Vector<String>>();
            while(rs.next()){
                Vector<String> line=new Vector<String>();
                for (int i=1;i<=4;i ++) line.add(rs.getString(i));
                data.add(line);
            }
            //关闭
            rs.close();
            stmt.close();
            conn.close();
            return data;
        }catch(SQLException ex){
            ex.printStackTrace();
            System.out.println("查询数据失败");
            return null;
        }
    }
	public static void main(String[] args) {
		Demo.main();
		// TODO 自动生成的方法存根
		Vector<Vector<String>> data = queryVectorStudents("Select * from Student");
		System.out.println("学号\t\t\t姓名\t性别\t年龄");
		System.out.println("********************************");
		for (Vector<String> itm1:data)
		{
			for (String itm2:itm1)
			{
				System.out.print(itm2+"\t");
			}
			System.out.println();
		}
			
		
	}

}
