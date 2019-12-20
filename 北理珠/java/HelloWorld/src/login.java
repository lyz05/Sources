import java.util.Scanner;

public class login
{    
	public static String encodeInp(String input)
	{
		input += "\0\0\0";
		char keyStr[] = ("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=").toCharArray();
		String output = new String();
		int chr1,chr2,chr3;
		int enc1,enc2,enc3,enc4;
		int i=0;
		do{
			chr1 = input.charAt(i ++);
			chr2 = input.charAt(i ++);
			chr3 = input.charAt(i ++);
			enc1 = chr1 >> 2;
			enc2 = ((chr1 & 3) << 4) | (chr2 >> 4);
			enc3 = ((chr2 & 15) << 2) | (chr3 >> 6);
			enc4 = chr3 & 63;
			if(chr2==0)
			{
				enc3 = enc4 = 64;
			} else if (chr3==0)
			{
				enc4 = 64;
			}
			output += keyStr[enc1];
			output += keyStr[enc2];
			output += keyStr[enc3];
			output += keyStr[enc4];
			
			chr1 = chr2 = chr3 = 0;
			enc1 = enc2 = enc3 = enc4 = 0;
			
		}while (input.charAt(i) != '\0');
		return output;
	}
	
	public static void main(String[] args) 
	{
		Scanner scan = new Scanner(System.in);
		String str = scan.next();
		//System.out.println(str.length());
		System.out.println(encodeInp(str));
		scan.close();
	}
}