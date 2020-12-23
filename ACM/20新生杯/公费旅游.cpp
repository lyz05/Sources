#include <iostream>
#include <cstring>
using namespace std;

long long n;

bool map[256];
int a[256],T;

int main()
{
	cin >> T;
	while (T --) {
		memset(a,0,sizeof a);
		memset(map,0,sizeof map);
		int m;
		cin >> m;
		while (m --)
		{
			char x,y;
			cin >> x >> y;
			a[x]++;
			map[x] = map[y] = 1;	
		}
		for (char i='A';i<='Z';i ++)
		{
			if (map[i] && a[i]==0) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
 } 
/*
1
2 3
4 5 6 7
8 9 10 11 12 13 14 15
*/
