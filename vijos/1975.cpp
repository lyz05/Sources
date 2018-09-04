#include <iostream>
#include <cstdio>
using namespace std;
const int N=150;
int a[(N*(N+1))/2+5];

int main(){
	int n,m,tot = 0,sum = 0;
	char c[100+5][100+5];
	int ans[100+5][100+5];
	cin >> n >> m;
	for (int i=1;i<=n;i ++)
		for (int j=1;j<=m;j ++) {
			cin >> c[i][j];
		}
	for (int i=1;i<=n;i ++)
		for (int j=1;j<=m;j ++) {
			ans[i][j] = (c[i-1][j] == '*')+(c[i][j-1] == '*')+(c[i+1][j] == '*')+(c[i][j+1] == '*')+(c[i+1][j-1] == '*')+(c[i-1][j+1] == '*')+(c[i+1][j+1] == '*')+(c[i-1][j-1] == '*');
		}
	for (int i=1;i<=n;i ++){
		for (int j=1;j<=m;j ++) {
				if (c[i][j]=='*') cout << '*';else	cout << ans[i][j];
			}
		cout << endl;
		}
	
}
