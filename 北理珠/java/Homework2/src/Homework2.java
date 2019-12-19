import java.sql.*;
import java.util.*;

public class Homework2 {
    public static Connection JdbcCon(){
        try{
            //--2 �������ݿ���������
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            //--3 ��������
            String url="jdbc:sqlserver://localhost:1433;databaseName=StuDB";
            Connection conn=DriverManager.getConnection(url,"sa","");
            return conn ;//���ش��������ݿ����Ӷ���
        }catch(ClassNotFoundException ex){//�������������Ҳ����쳣
            ex.printStackTrace();
            System.out.println("���ݿ������������ʧ��");
            return null;
        }catch(SQLException ex){//�������ݿ�����ʧ���쳣
            ex.printStackTrace();
            System.out.println("���ݿ�����ʧ��");
            return null;
        }
    }
    
    //��ѯ����(���ض�άVector����)
    public static Vector<Vector<String>> queryVectorStudents(String sql){
        Connection conn=JdbcCon();
        Statement stmt; //�Ự����
        ResultSet rs; //�����
        try{
            //�����Ự����
            stmt=conn.createStatement();
            //ִ��SQL���
            rs=stmt.executeQuery(sql);
            Vector<Vector<String>> data=new Vector<Vector<String>>();
            while(rs.next()){
                Vector<String> line=new Vector<String>();
                for (int i=1;i<=4;i ++) line.add(rs.getString(i));
                data.add(line);
            }
            //�ر�
            rs.close();
            stmt.close();
            conn.close();
            return data;
        }catch(SQLException ex){
            ex.printStackTrace();
            System.out.println("��ѯ����ʧ��");
            return null;
        }
    }
	public static void main(String[] args) {
		Demo.main();
		// TODO �Զ����ɵķ������
		Vector<Vector<String>> data = queryVectorStudents("Select * from Student");
		System.out.println("ѧ��\t\t\t����\t�Ա�\t����");
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
