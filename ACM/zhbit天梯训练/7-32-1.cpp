#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int L,N;
	cin>>L>>N;
	double M=pow((double)26,(double)L)-N;
	int m=(int)M;
	//����õ���0��ʼ����� 
	char ch[6];//���峤��Ϊ6���ַ����� 
	int i=0;
	while(L--)//�洢L���ȵ��ַ� 
	{
		ch[i++]='a'+m%26;//�����ǰ����洢�Ӵ��ҵ�����ַ� 
		m/=26;
	}
	for(int j=i-1;j>=0;j--)//������� 
	cout<<ch[j];
	return 0;
}
