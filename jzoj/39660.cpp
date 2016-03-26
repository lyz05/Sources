#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 101000;

int a[maxn],n;
double s[maxn];

double check(double t) 
{
	for (int i = 1 ; i <= n ; i ++) s[i] = s[i - 1] + a[i] - t;
	double sm = 1e9 , bi = 0 , flag = 1; 
	for(int i = 2 ; i < n ; i ++) { 
		if (sm > s[i - 1]) sm = s[i-1]; 
		if (flag) bi = s[i] - sm , flag = 0;
		if (bi < s[i] - sm) bi = s[i] - sm; 
	}
	return s[n] - bi;
}

void Work() { 
	int d = int(1e5); int l = 0 , r = int(1e9);
  	double ans; 
	while (l <= r) { 
		int mid = (l+r)>>1; 
  		if (check(double(mid) / d) < 0) {
			ans = double(mid) / d;
		       	r = mid - 1;
	       	} else l = mid + 1; 
	} 
  	printf("%.3lf\n",ans); 
}
int main()
{
	freopen("3960.in","r",stdin);
	scanf("%d" , &n);
	for (int i = 1 ; i <= n ; i ++) scanf("%d" , &a[i]);
	//ans2 = (double) sum / n;
	Work();
}
