#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;

typedef long long LL;
const int N = 3000000+5, oo = 1000000000;
int n,a[N],l,r,f[N],g[N],s[N],id[N];
char c;

void read(int& num) {
    num=0;
    bool status=false;
    while((c=getchar())!=EOF) {
        if(isdigit(c)) {status=true;num=num*10+c-'0';}
        else if(status) break;
    }
}

int main()
{
	freopen("b.in","r",stdin);
	//freopen("b.out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1;i<=n;i ++) read(a[i]);
	
	l = 1;r = 1;s[1] = oo;id[1] = 0;
	for (int i=1;i<=n;i ++)
	{
		while (l<r && s[r]<a[i]) r --;
		f[i] = id[r];
		r ++;
		s[r] = a[i];
		id[r] = i;
	}
	
	l = 1;r = 1;s[1] = oo;id[1] = n+1;
	for (int i=n;i>=1;i --)
	{
		while (l<r && s[r]<=a[i]) r --;
		g[i] = id[r];
		r ++;
		s[r] = a[i];
		id[r] = i;
	}

	for (int i=1;i<=n;i ++)
		printf("%lld ",(long long)(g[i]-i)*(i-f[i]));
	return 0;
}
