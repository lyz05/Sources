#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 5;
int map[N][N];
int p[]={0,0,0,0,0,0,10000,36,720,360,80,252,108,72,54,180,72,180,119,36,306,1080,144,1800,3600};

int main()
{
	int tmp = 1+2+3+4+5+6+7+8+9;
	for (int i=1;i<=3;i ++)
		for (int j=1;j<=3;j ++)
			cin >> map[i][j],tmp-=map[i][j];
	for (int i=1;i<=3;i ++)
		for (int j=1;j<=3;j ++)
			if (map[i][j]==0) map[i][j] = tmp;
			
	for (int i=1;i<=3;i ++)
	{
		int x,y;
		cin >> x >> y;
		cout << map[x][y] << endl;
	}
	int dir=0,ans = 0;
	cin >> dir;
	if (dir<=3)
	{
		int i = dir;
		for (int j=1;j<=3;j ++)
			ans += map[i][j];
	} else if (dir <= 6)
	{
		int j = dir-3;
		for (int i=1;i<=3;i ++)
			ans += map[i][j];
	} else if (dir==7){
		for (int i=1,j=1;i<=3 && j<=3;i ++,j ++)
			ans += map[i][j];
	} else {
		for (int i=1,j=3;i<=3 && j>=1;i++,j--)
			ans += map[i][j];
	}
	ans = p[ans];
	cout << ans << endl;
	return 0;
}
