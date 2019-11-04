#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100+7;
int n,V;
int v[N][N],w[N][N],tot[N],f[N][N][N];

int main()
{
	cin >> n >> V;
    for (int i=1;i<=n;i ++)
    {
        cin >> tot[i];
        for (int j=1;j<=tot[i];j ++) 
            cin >> v[i][j] >> w[i][j];
    }
    //f[i][j][k]表示前i组中第i组选第j个容量为k的最大价值
    for (int i=1;i<=n;i ++)
    {
        for (int j=1;j<=tot[i];j ++)
            for (int k=0;k<=V;k ++)
            {
                if (k-v[i][j]>=0)
                    f[i][j][k] = f[i-1][0][k-v[i][j]]+w[i][j];
            }
        
        for (int j=1;j<=tot[i];j ++)
            for (int k=0;k<=V;k ++)
            {
                f[i][0][k] = max(f[i][0][k],f[i][j][k]);
            }
        for (int k=0;k<=V;k ++)
            f[i][0][k] = max(f[i][0][k],f[i-1][0][k]);
    }
    cout << f[n][0][V] << endl;
	return 0;
}
