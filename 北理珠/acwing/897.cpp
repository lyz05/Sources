#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000+7;
int n,m;
int f[N][N];
string s1,s2;

int main()
{
	cin >> n >> m;
    cin >> s1 >> s2;
	for (int i=1;i<=n;i ++) 
		for (int j=1;j<=m;j ++)
        {
            if (s1[i-1] == s2[j-1])
            {
                f[i][j] = f[i-1][j-1] + 1;
            }
            f[i][j] = max(f[i][j],max(f[i-1][j],f[i][j-1]));
        }

	cout << f[n][m] << endl;
	return 0;
} 
