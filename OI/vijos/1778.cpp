#include <cstdio>

using namespace std;

int a[27][27];
char w1[1000],s[1000],w[1000];

int main()
{
	for (int i=1;i<=26;i++)
		for (int j=1;j<=26;j++)
			if (j+64+i-1>90) 
				a[i][j]=(char) (j+64+i-1-26);
			else
				a[i][j]=(char) (j+64+i-1);
	scanf("%s/n%s",&w1,&s);
	for (int i=1;i<=strlen(s)/strlen(w1)+1) w=w+w1;
	
	return 0;
}
