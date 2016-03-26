#include<cstdio>
#include<bitset>
#include<algorithm>
using namespace std;
int n,t,m,l,X;
char s[805][805];
int nex[805][805];
int r[805];
//bitset<805> flag[805];
int flag[805][805];

bool cmp(const int &x,const int &y)
{
	return nex[x][X]>nex[y][X];
}
int main()
{
	freopen("3949.in","r",stdin);
	int i,j;
	scanf("%d%d%d%d",&n,&t,&m,&l);
	for(i=1;i<=n;i++)
	{
		r[i]=i;
		scanf("%s",s[i]+1);
		for(j=t;j;j--)
			if(s[i][j]==48)
				nex[i][j]=0;
			else
				nex[i][j]=nex[i][j+1]+1;
	}
	X=1;
	sort(r+1,r+1+n,cmp);
	for(i=1;i<=m;i++)
		flag[1][r[i]]=1;
	for(i=2;i<=t;i++)
	{
		for(int jj=0;jj<=804;jj++) flag[i][jj]=flag[i-1][jj];
		X=i;
		sort(r+1,r+1+n,cmp);
		int s=1,t=n;
		for(j=1;j<=l;j++)
		{
			while(s<=n&&flag[i][r[s]])s++;
			while(t>0&&!flag[i][r[t]])t--;
			if(s>=t)break;
			flag[i][r[s]]=1;
			flag[i][r[t]]=0;
		}
		for(j=1;j<=n;j++)
			if(flag[i][j]&&!nex[j][i])//标记[i,j]可行，实际不可行
				return puts("-1");
	}
	for(i=1;i<=t;i++,puts(""))
		for(j=1;j<=n;j++)
			if(flag[i][j])
				printf("%d ",j);
	return 0;
}
