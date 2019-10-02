#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;

const int MAXN=32000;
LL a[MAXN],n;
int T;

int main()
{
	//freopen("E.in","r",stdin);
	//freopen(".out","w",stdout);
	for (int i=1;i<=MAXN;i ++)
	{
		a[i] = a[i-1];
		LL now = i;
		while (now) a[i] ++,now /= 10;
	}
	cin >> T;
	while (T --) 
	{
		cin >> n;
		for (int i=1;n-a[i]>0;i ++) n -= a[i];
		int i;
		for (i=1;n-a[i]>0;i ++);
		int cnt = a[i]-n,now = i;
		for (int i=1;i<=cnt;i ++) now /=10;
		cout << now%10 << endl;

	}

	return 0;
}