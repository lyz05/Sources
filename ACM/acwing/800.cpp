#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

const int N = 500000+5;
int n,m,x;
int a[N][2]; 

void Hash(int now,int val)
{
	int truenow = now;
	for (;a[now%N][0];now ++);
	a[now%N][0] = truenow;
	a[now%N][1] = val;
}
int gethash(int truenow)
{
	int now = truenow;
	for (;a[now%N][0];now ++) 
		if (a[now%N][0] == truenow) 
			return a[now%N][1];
	return -1;
}


int main()
{
	cin >> n >> m >> x;
	for (int i=0;i<n;i ++) 
	{
		int t;
		cin >> t;
		Hash(t,i);
	} 
	for (int i=0;i<m;i ++) 
	{
		int t;
		cin >> t;
		int j = gethash(x-t);
		if (j!=-1)
		{
			cout << j << " " << i;
			return 0;
		}
	}
	

	return 0;
} 
