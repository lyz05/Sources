#include <cstdio>

using namespace std;

const int L=30,N=550;
char s[L],s1[L],s2[L];
int a[N][4],b[N][4];

int read1()
{
	if (s1[0]=='J')
	{
		if (s1[1]=='a') return 1;
		if ((s1[1]=='u')&&(s1[2]=='n')) return 6;
		if ((s1[1]=='u')&&(s1[2]=='l')) return 7;
	}
	if (s1[0]=='F') return 2;
	if (s1[0]=='M') 
	{
		if (s1[2]=='r') return 3;
		if (s1[2]=='y') return 5;
	}
	if (s1[0]=='S') return 9;
	if (s1[0]=='O') return 10;
	if (s1[0]=='N') return 11;
	if (s1[0]=='D') return 12;
	if ((s1[0]=='A')&&(s1[1]=='p')) return 4;
	if ((s1[0]=='A')&&(s1[1]=='u')) return 8;
}

void init(int cnt)
{
	scanf("%s %d, %d",&s1,&a[cnt][2],&a[cnt][3]);
	a[cnt][1]=read1();
	scanf("%s %d, %d",&s1,&b[cnt][2],&b[cnt][3]);
	b[cnt][1]=read1();
}

int work(int i)
{
	int ans=0;
	int l=a[i][3]+1,r=b[i][3]-1;
	if (a[i][1]<3) l--;
	if ((b[i][1]>=3)||((b[i][1]==2)&&b[i][2]==29)) r++;
	for (int j=l;j<=r;j++)
	{
		if (j%100==0){
			if (j%400==0) ans++;
		}else
			if (j%4==0) ans++;	
	}
	return ans;
}

int main()
{
	freopen("1.in","r",stdin);
	int n;
	scanf("%d",&n);
	for (int cnt=1;cnt<=n;cnt++)
	{
		init(cnt);
		int ans=work(cnt);
		printf("Case #%d: %d\n",cnt,ans);
	}
	return 0;
}
/*
 *   "April", "August", 
 */
