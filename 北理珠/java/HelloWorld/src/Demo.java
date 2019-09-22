import javax.swing.*;
import java.awt.*;
import java.sql.*;

public class Demo extends JFrame
{    
	public static void main(String[] args) 
	{        
		JFrame f = new JFrame("SWING");        
		f.setSize(400,200);        
		f.setLayout(new BorderLayout());        
		JButton b1 = new JButton("1");        
		JButton b2 = new JButton("2");        
		JTextArea ta = new JTextArea("3");        
		JButton b4 = new JButton("4");        
		JButton b5 = new JButton("5");        
		f.add(b1, BorderLayout.NORTH);        
		f.add(b2, BorderLayout.WEST);        
		f.add(ta, BorderLayout.CENTER);        
		f.add(b4, BorderLayout.EAST);        
		f.add(b5, BorderLayout.SOUTH);        
		f.setBounds(300, 200, 500, 300);        
		f.setVisible(true);        
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);    
		}
}