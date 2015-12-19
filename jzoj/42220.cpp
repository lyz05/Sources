#include <cstdio>
typedef long long LL;

const int Maxn = 1010;
LL n, m, k;
LL Reg[Maxn], a[Maxn];


int main(){
	freopen("4222.in","r",stdin);

	scanf("%lld %lld %lld", &n, &m, &k);
	if(m == 1){
		printf("0");
		return 0;
	}
	a[1] = 1;
	LL sum = 1, p = 1;
	n ++;
	bool b = 0;
	while(p < n){
		LL sons = sum, t = sum;
		if(p >= m){
			sons -= a[m];
			t -= a[m];
		}
		if(sum + sons >= k) break;
		sum = t;
		for(int i = 1000; i > 1; i --) a[i] = a[i - 1];
		a[1] = sons;
		sum += sons;
		p ++;
	}
	if(p == n){
		printf("%lld" , sum);
		return 0;
	}
	if(p >= m){
		Reg[1] = sum;
		for(int i = 2; i <= m + 1; i ++){
			LL sons = sum;
			sons -= a[m];
			if(sum + sons > k) sons = k - sum;
			sum -= a[m];
			for(int j = 1000; j > 1; j --) a[j] = a[j - 1];
			sum += sons;
			a[1] = sons;
			Reg[i] = sum;
		}
		LL t = (n - p + 1) % (m + 1);
		if(!t) t = m + 1;
		printf("%lld", Reg[t]);
	}
	else{
		LL front = m - p + 1, t = (n - p + 1) % (m + 1);
		if(!t) t = m + 1;
		if(t == 1) printf("%lld", sum);
		else if(t <= front) printf("%lld" , k);
		else{
			t = t - front;
			printf("%lld" , k - a[p - t + 1]);
		}
	}
	
	return 0;
}
