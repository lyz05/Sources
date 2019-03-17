#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100000+125;
int n,k;
int a[N],h[N],maxx;

int find(int x)
{
	if (h[x]!=0) return h[x];
	if (a[x]==-1) return 1;
	return h[x] = find(a[x])+1;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i ++) scanf("%d",a+i);
	for (int i=1;i<=n;i ++) h[i] = find(i),maxx = max(maxx,h[i]),k=(maxx==h[i])?i:k;
	printf("%d\n",maxx);
	for (int i=1;i<=n;i ++) 
		if (h[i]==maxx) printf("%d%c",i,(i!=k)?' ':'\n');
	return 0;
}
