#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int L,N;
	cin>>L>>N;
	double M=pow((double)26,(double)L)-N;
	int m=(int)M;
	//相减得到从0开始的序号 
	char ch[6];//定义长度为6的字符数组 
	int i=0;
	while(L--)//存储L长度的字符 
	{
		ch[i++]='a'+m%26;//数组从前往后存储从从右到左的字符 
		m/=26;
	}
	for(int j=i-1;j>=0;j--)//逆序输出 
	cout<<ch[j];
	return 0;
}
