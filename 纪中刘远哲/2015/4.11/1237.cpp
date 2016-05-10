#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 2001;
int n , m , ans;
char st[N][N];
//int sum[N][N];
int up[N][N];

int main(){
	freopen("3.in","r",stdin);
	scanf("%d %d" , &n , &m);
	for(int i = 1; i <= n; i ++) scanf("%s" , &st[i]);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++){
			if (st[i][j - 1] == 'X') up[i][j] = 0;
			else up[i][j] = up[i - 1][j] + 1;
		}
	
	int i = n;
	ans = 0;
	while(i >= 1){
		for(int j = 1; j <= m; j ++){
			int low = up[i][j];
			for(int k  = j; k <= m; k ++){
				low = min(low , up[i][k]);
				if(low == 0) break;
				ans = max(ans , (k - j + 1 + low) * 2);
			}
		}
		i --;
	}
	
	printf("%d" , ans - 1);
	
	return 0;
}
