#include <iostream>
#include <stdio.h>
using namespace std;
char a[1000];
int main()
{
	int m1=0,m2=0,r1,r2,r3;
	while(cin>>m1>>m2)
	{
		r1=r2=r3=0;
		char c='\0',*t;
		cin>>a;
		t=a;
		while(*t!=c)
		{
	
			if(*t=='A')
			{
				r1=m1;
			}	
			if(*t=='B')
			{
				r2=m2;
			}
			if(*t=='C')
			{
				m1=r3;
			}	
			if(*t=='D')
			{
				m2=r3;
			}
			if(*t=='E')
			{
				r3=r1+r2;
			}	
			if(*t=='F')
			{
				r3=r1-r2;
			}
			t++;
		}
		cout<<m1<<","<<m2<<endl;
	}
	return 0;
}
