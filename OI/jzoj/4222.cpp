#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 1010;
LL n, m, k;
LL Reg[N], a[N];

int main(){
	//freopen("horrible.in","r",stdin);
	//freopen("horrible.out","w",stdout);

	scanf("%lld%lld%lld", &n, &m, &k);
	if(m == 1){
		printf("0");
		return 0;
	}
	a[1] = 1;
	LL sum = 1, p = 1;
	n ++;

	for (p = 1;p < n;p ++)			//进入循环的位置
	{
		LL sons = sum, t = sum;	//儿子数等于总人数
		if(p >= m){
			sons -= a[m];
			t -= a[m];
		}				//开始有人死亡
		if(sum + sons >= k) break;//进入循环标志
		sum = t;
		for(int i = 1000; i >= 2; i --) 
			a[i] = a[i - 1];	//扣血数加一
		a[1] = sons;		//开始扣血
		sum += sons;
	}
	if(p == n){				//n比较小已经暴力获得答案
		printf("%lld" , sum);
		return 0;
	}
	if(p >= m){							//不存在相同的数
		Reg[1] = sum;
		for(int i = 2; i <= m + 1; i ++){		//处理处循环出的数组
			LL sons = sum;
			sons -= a[m];
			if(sum + sons > k) sons = k - sum;	//超过限制人数
			sum -= a[m];
			for(int j = 1000; j >= 2; j --) 
				a[j] = a[j - 1];
			a[1] = sons;
			sum += sons;
			Reg[i] = sum;
		}
		LL t = (n - p + 1) % (m + 1);
		if(!t) t = m + 1;
		printf("%lld", Reg[t]);
	}
	else{
		LL front = m - p + 1, t = (n - p + 1) % (m + 1);
		//front相同的数的长度，值为k
		if(!t) t = m + 1;
		if(t == 1) printf("%lld", sum);
		else if(t <= front) printf("%lld" , k);
		else{
			t = t - front;
			printf("%lld" , k - a[p - t + 1]);//??
		}
	}
	
	return 0;
}

