#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 300+7;
string s1,s2;
int f[N][N],a[N],sum[N];

bool compare(string &x,string &y)
{	//<
	if (s1.length()>s2.length()) return 1;
}

int main()
{
	cin >> s1 >> s2;
	cout << (s1>s2) << endl;
	return 0;
} 
