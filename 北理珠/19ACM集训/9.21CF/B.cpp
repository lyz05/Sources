#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

const int N = 1000+5;
int n,ans;
struct node
{
	int id,num;
} a[N];
bool cmp(node A,node B)
{
	return A.num>B.num;
}

int main()
{
	//freopen("B.in","r",stdin);
	//freopen(".out","w",stdout);
	
	cin >> n;
	for (int i=1;i<=n;i ++) cin >> a[i].num,a[i].id = i;
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i ++) ans += (i-1)*a[i].num+1;
	cout << ans << endl;
	for (int i=1;i<=n;i ++) cout << a[i].id << " ";
	cout << endl;
	return 0;
}
