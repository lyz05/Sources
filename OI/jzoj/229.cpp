#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const char s[13][20]={"","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};
char s1[20],s2[20];
int ans=0,t,a[2*T][3];

void work()
{
	
}

int main()
{
	freopen("229.in","r",stdin);
	scanf("%d\n",&t);
	for (int cnt=1;cnt<=t;cnt++)
	{
		scanf("%s",s1);
		for (int i=1;i<=n;i++)
			if (strlen(s1)=strlen(s[i])){
				for (int j=0;j<strlen(s1);j++)
					if s[i][j]!=s1[j] break;
				a[2*cnt-1][1]=i;
			}
		scanf("%s",s1)
		for (int i=0;i<strlen(s1)-1)
			
		printf("Case #%d: %d\n",cnt,ans);
	}
}
