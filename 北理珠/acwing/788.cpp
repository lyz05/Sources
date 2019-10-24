#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+7;
long long n,a[N],b[N],ans;

void merge_sort(int l,int r)
{
	if (l==r)
	{
		return;
	}
	int mid = (l+r)>>1;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	int i,j,k;
	for (i=l,j=mid+1,k=0;i<=mid && j<=r;)
	{
		if (a[i]<=a[j]) b[++ k] = a[i],ans += j-mid-1,i ++;
		else b[++ k] = a[j],j ++;
	}
	for (;i<=mid;i ++) b[++ k] = a[i],ans += r-mid;
	for (;j<=r;j ++) b[++ k] = a[j];
	for (int i=l;i<=r;i ++) a[i] = b[i-l+1];
}

int main()
{
	cin >> n;
	for (int i=1;i<=n;i ++) cin >> a[i];
	merge_sort(1,n); 
	//for (int i=1;i<=n;i ++) cout << a[i] << " ";
	cout << ans << endl;
	return 0;
} 
