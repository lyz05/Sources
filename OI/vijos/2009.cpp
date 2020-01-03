#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n,x[4],y[4],ans = 1e9+7;

int main(){
	scanf("%d",&n);
	for (int i=1;i<=3;i ++) {
		int tmp = 0;
		scanf("%d%d",x+i,y+i);
		if (n%x[i]==0) tmp = n/x[i]*y[i];else tmp = (n/x[i]+1)*y[i];
		ans = min(ans,tmp);
	}
	printf("%d\n",ans);
	return 0;
}