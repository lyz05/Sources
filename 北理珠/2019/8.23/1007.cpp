#include <iostream>
using namespace std;

const int N = 10,MAXN = 1024+12;
int T,n;
int map[MAXN][MAXN];

int main()
{
	freopen("CCPC.in","r",stdin);
	freopen("1007.out","w",stdout);

	map[2][1] = 1;
	for (int k=2;k<=N;k ++)
	{
		int M = (1<<(k-1));
		for (int i=1;i<=M;i ++)
			for (int j=1;j<=M;j ++)
			{
				map[i][j+M] = map[i][j];
				map[i+M][j+M] = map[i][j];
				map[i+M][j] = map[i][j]^1; 
			}
	}

	cin >> T;
	for (int i=1;i<=T;i ++)
	{
		cin >> n;
		for (int i=1;i<=(1<<n);i ++)
		{
				for (int j=1;j<=(1<<n);j ++)
				{
					cout << ((map[i][j]==1)?"P":"C");
				}
			cout << endl;
		}
	
	}
	return 0;
}
