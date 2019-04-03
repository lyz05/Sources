#include<bits/stdc++.h>
using namespace std;

int x,y;
double ans;

int main()
{
	cin >> x >> y;
	ans = 100*100/2-x*y*0.5-(100-x)*y-(100-x)*(100-y)*0.5;
	cout << ans; 
	return 0;
} 
