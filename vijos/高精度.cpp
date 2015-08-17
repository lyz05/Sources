#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef char bign [100];
bign s1,s2,s3,s;

void add(char (&s1)[100],char (&s2)[100],char (&s3)[100])
{
	int len=max(strlen(s1),strlen(s2));
	int r=0;
	/*
	for (int i=strlen(s1);i<len;i ++)
		s1[i]='0';
	for (int i=strlen(s2);i<len;i ++)
		s2[i]='0';
	*/
	for (int i=0;i<len;i ++)
	{
		int t=r;
		if (s1[i]>='0') t+=s1[i]-'0';
		if (s2[i]>='0') t+=s2[i]-'0';

		r=t/10;
		t%=10;
		s3[i]=t+'0';
	}
	if (r!=0) s3[len]=r+'0';
}

void fz(char (&s)[100],int x)
{
	
	int i=0;
	while (x!=0)
	{
		int r=x % 10;
		s[i]=r+'0';
		x=x/10;
		i++;
	}
	s[i]='\0';
}

int main()
{
	scanf("%s",&s);
	for (int i=0;i<strlen(s);i++)
		s1[i]=s[strlen(s)-i-1];
	scanf("%s",&s);
	for (int i=0;i<strlen(s);i++)
		s2[i]=s[strlen(s)-i-1];
	fz(s,154);
	//for (int i=0;i<strlen(s1);i++) a[i]=s1[i];
	//for (int i=0;i<strlen(s2);i++) b[i]=s2[i];

	add(s1,s2,s3);
	for (int i=strlen(s3)-1;i>=0;i--)
		printf("%c",s3[i]);
	return 0;
}
