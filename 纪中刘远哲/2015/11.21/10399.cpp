/*
令d[i][j]代表i位数，其中最高位为j的Windy数个数：
d[i][j]=∑d[i-1][k](0≤k≤9且|k-j|≥2)
*/
#include<cstdio>
#include<cstdlib>

int i,j,k,d[20][10],t[]={0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,-1u>>1};
void dp()
{	
	for(i=0;i<=9;i++)
		d[1][i]=1;
	for(i=2;i<=9;i++)
		for(j=0;j<=9;j++)
			for(k=0;k<=9;k++)
				if(abs(j-k)>=2)
					d[i][j]+=d[i-1][k];
	for(j=1;j<3;j++)
		for(k=0;k<=9;k++)
			if(abs(j-k)>=2)
				d[10][j]+=d[9][k];
}
int find(int n)
{
	int i,j,k=1,num,last,ans=0;
	while(t[k]<=n)k++;
	k--;
	for(i=1;i<k;i++)
		for(j=1;j<=9;j++)
			ans+=d[i][j];
	num=n/t[k];
	for(j=1;j<num;j++)
		ans+=d[k][j];
	n%=t[k];
	last=num;
	for(i=k-1;i>0;i--)
	{
		num=n/t[i];
		for(j=0;j<num;j++)
			if(abs(last-j)>=2)
				ans+=d[i][j];
		if(abs(num-last)<2)
			break;
		last=num;
		n%=t[i];
	}
	return ans;
}
int main()
{
	freopen("1039.in","r",stdin);
	dp();
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",find(b+1)-find(a));
}

