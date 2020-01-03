#include <cstdio>
#include <iostream> 
#include <cstring>
using namespace std;

char s[100];
int num1,num2,ans;

int transfer(char s[])
{
	if (strcmp(s,"one")==0) return 1;
	if (strcmp(s,"two")==0) return 2;
	if (strcmp(s,"three")==0) return 3;
	if (strcmp(s,"four")==0) return 4;
	if (strcmp(s,"five")==0) return 5;
	if (strcmp(s,"six")==0) return 6;
	if (strcmp(s,"seven")==0) return 7;
	if (strcmp(s,"eight")==0) return 8;
	if (strcmp(s,"nine")==0) return 9;
	if (strcmp(s,"zero")==0) return 0;
	return -1;
}

int main()
{
	while (1)
	{
		num1 = 0;
		for (scanf("%s",s);s[0]!='=' && s[0] != '+';scanf("%s",s))
		{
			num1 = num1*10 + transfer(s);
		}
		num2 = 0;
		for (scanf("%s",s);s[0]!='=' && s[0] != '+';scanf("%s",s))
		{
			num2 = num2*10 + transfer(s);
		}
		
		//cout << num1 << " " << num2 << endl;
		ans = num1 + num2;
		if (num1==0 && num2==0) break;
		printf("%d\n",ans);
	}
	return 0;	
} 
