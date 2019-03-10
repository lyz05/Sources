#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;

const int M = 25;
char name[2][M];
int num;
int main()
{
	for (int i=1;;i ++)
	{
		char s[M];
		cin.getline(s,M);
		if (strcmp(s,".")==0) break;
		if (i==2 || i==14) strcpy(name[num ++],s);
	} 
	if (num==0) printf("Momo... No one is for you ...");
	if (num==1) printf("%s is the only one for you...",name[0]);
	if (num==2) printf("%s and %s are inviting you to dinner...",name[0],name[1]);
	return 0;
} 
