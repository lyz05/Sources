#include<cstdio>
#include<cstring>
using namespace std;

const int N = 100*3;
char s[N];
const char stdd[]="123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899100";
char Ans[4],Tmp1[N],Tmp2[N],Tmp3[N];
int len,ans;

bool judge()
{
	bool flag = 1;
	int len = strlen(stdd),lenT = strlen(Tmp3);
	for (int i=0;i<len;i ++)
	{
		flag = 1;
		for (int j=0;j<lenT;j ++)
			if (stdd[i+j]!=Tmp3[j])
			{
				flag = 0;
				break;
			}
		if (flag) break;
	}
	return flag;
}

int main()
{
	//freopen("0.in","r",stdin);
	//printf("%d",strlen(stdd));
	scanf("%s",s);
	len = strlen(s);
	for (ans=1;ans<=100;ans ++)
	{
		memset(Ans,0,sizeof Ans);
		memset(Tmp1,0,sizeof Tmp1);
		memset(Tmp2,0,sizeof Tmp2);
		if (ans<10) Ans[0] = ans+'0';
		else if (ans==100) Ans[2]=Ans[1]='0',Ans[0]='1';
		else Ans[1] = ans%10+'0',Ans[0] = ans/10+'0';
		for (int i=1;i<=len;i ++)
		{
			memset(Tmp3,0,sizeof Tmp3);
			strncpy(Tmp1,s,i);
			strcpy(Tmp2,s+i);
			strcat(Tmp3,Tmp1);
			strcat(Tmp3,Ans);
			strcat(Tmp3,Tmp2);
			if (judge())
			{
				printf("%d\n",ans);
				return 0;
			}
		}

	}
	return 0;
} 
