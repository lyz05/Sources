#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <map>
using namespace std;

long long n;

int main()
{
	while (cin >> n) {
		double ans = log(n)/log(2);
		cout << ceil(ans) << endl;
	}
	return 0;
 } 
