
#include<stdio.h>
#include<string.h>
#define MAXN 500
char a[MAXN],b[MAXN];
int c[MAXN],d[MAXN],e[MAXN],f[MAXN],x[MAXN],y[MAXN];
int main()
{
	//freopen("D.in","r",stdin);
	int i,j,k,m,p,q,len1,len2,t;
	while(scanf("%s%s",a,b)!=EOF)
	{
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		memset(f,0,sizeof(f));
//		memset(x,0,sizeof(x));
//		memset(y,0,sizeof(y));
		k=len1=strlen(a);
		for(i=0;i<len1;i++)
		{
			if(a[i]=='.')
			k=i;			//the point position of first 
		}
		m=len2=strlen(b);
		for(i=0;i<len2;i++)
		{
			if(b[i]=='.')
			m=i;			//the point position of second 
		}
			/*	change char of zhengshu to int */
		for(j=0,i=k-1;i>=0;i--)
		{
			c[j++]=a[i]-'0';
		}
		for(j=0,i=m-1;i>=0;i--)
		{
			d[j++]=b[i]-'0';
		}
		//change char of xiaoshu to int
		for(j=0,i=k+1;i<len1;i++)
		{
			e[j++]=a[i]-'0';
		}
		for(j=0,i=m+1;i<len2;i++)
		{
			f[j++]=b[i]-'0';
		}
		//count the xiaoshu
		p=q=0;
		if(len1-k<len2-m)
		p=len2-m;
		else
		p=len1-k;
		for(i=p-1;i>=0;i--)
		{
			x[i]=(e[i]+f[i]+q)%10;
			if(e[i]+f[i]+q>=10)
			{
				q=(e[i]+f[i]+q)/10;
			}
			else
			q=0;
		}
		//	count the zhengsu 
		if(k<m)
		t=m;
		else
		t=k;
		for(i=0;i<=t;i++)
		{
			y[i]=(c[i]+d[i]+q)%10;
			if(c[i]+d[i]+q>=10)
			{
				q=(c[i]+d[i]+q)/10;
			}
			else
			q=0;
		}
		if(y[t]>0)
		t=t+1;
		for(i=t-1;i>=0;i--)
		printf("%d",y[i]);
	/**************************************/
		while(x[p-1]==0)//deal the 0 behind of xiaoshu
		{
			if(x[p-1]==0)
			p=p-1;
		}
		
		
	/**************************************/
		if(p>0)
		printf(".");
		
		for(i=0;i<p;i++)
		printf("%d",x[i]);
		
		printf("\n");	
	}
	return 0;
}

