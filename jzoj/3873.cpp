#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
set<int> s;
#define maxn 500010
int a[maxn+10],b[maxn+10],c[maxn+10],t[maxn+10];
#define lowbit(x) ((x)&(-x)) 
int add(int x) {
	for (;x<maxn;x+=lowbit(x)) t[x]++;
}
int sum(int x) {
	int ans=0;
	for (;x;x-=lowbit(x)) ans+=t[x];
	return ans;
}
int work(int x,long long y) {
	int l;
	for (l=1;l<=x;l++) {
		if ((x-l)*1ll*(x-l-1)/2>=y) c[l]=l;
		else break;
	}
	int n=x-l+1,i=l+1,j;
	c[l]=x-n*1ll*(n-1)/2+y;
	for (j=x;j>c[l];i++,j--) c[i]=j;
	for (j=c[l]-1;i<=x;i++,j--) 
		c[i]=j;
		return 0;
}
int main(){
	int n;
//	freopen("1.out","r",stdin);
//	freopen("1.in","w",stdout);
	scanf("%d\n",&n);
	for (int i=1;i<=n;i++) scanf("%d",a+i);
	long long sigma=0;
	bool flag=1;
	for (int i=n;i;i--) {
		sigma+=sum(a[i]);
		set<int>::iterator iter=s.upper_bound(a[i]);
		if (iter!=s.end()) {
			int tmp=sum(*iter) ;
			if (!flag&&sigma-tmp<=(n-i)*1ll*(n-i-1)/2){
				for (int j=1;j<i;j++) printf("%d ",a[j]);
				printf("%d ",*iter);
				s.insert(a[i]);
				sigma-=tmp;
				s.erase(*iter);
				tmp=1;
				for (set<int>::iterator j=s.begin();j!=s.end();j++,tmp++) b[tmp]=*j;
				work(n-i,sigma);
//				for (int j=1;j<=n-i;j++) printf("%d ",c[j]);
				for (int j=1;j<=n-i;j++) printf("%d ",b[c[j]]);
				return 0;
			}
		}
		s.insert(a[i]);
		add(a[i]);
		if (i!=n&&a[i]>a[i+1]) flag=0;
	}
	return 0;
}

	
