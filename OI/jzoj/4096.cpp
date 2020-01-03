#include <cstdio>
#include <algorithm>
#include <bitset>
#include <cstring>

//typedef long long LL;
using namespace std;

const int N = 100000+2 , M = 1000000+1 , Mo = 1000;

struct Linker{
	int x , y;
} l[2 * M];

int sum[N] , color[N] , dfn[N] , low[N] , stack[N] , last[N] , anc[N] , bridge[M];
int l0 , colorsum , n , m , q , top , dfncount , t;
bitset<N> b;

void Link(int x , int y)
{
	l[++ l0].x = y; l[l0].y = last[x]; last[x] = l0;
}

void Tarjan(int x , int y){
	dfn[x] = low[x] = ++ dfncount;
	stack[++ top] = x;
	for(int p = last[x]; p; p = l[p].y)
		if(!dfn[l[p].x]){
			Tarjan(l[p].x , p ^ 1);
			low[x] = min(low[x] , low[l[p].x]);
		} 
		else if(p != y) low[x] = min(low[x] , dfn[l[p].x]);
	if(dfn[x] == low[x])
	{
		colorsum ++;
		int stacktop;
		do {
			stacktop = stack[top --];
			color[stacktop] = colorsum;
			sum[colorsum] ++;
		} while(stacktop != x);
	}
}

void Contract(int x , int ancestor){
	if(b[x]) return;
	b[x] = 1; anc[x] = ancestor;
	for(int p = last[x]; p; p = l[p].y)
		if(!b[l[p].x]){
			Contract(l[p].x , ancestor);
			if(color[x] != color[l[p].x]){
				sum[color[x]] += sum[color[l[p].x]];
				bridge[p / 2] = l[p].x;
			} else bridge[p / 2] = anc[l[p].x];
		}
}

int main(){
	//freopen("b.in" , "r" , stdin);
	//freopen("b.out" , "w" , stdout);
	
	l0 = 1;
	scanf("%d %d %d" , &n , &m , &q);
	for(int i = 1; i <= m; i ++){
		int x , y;
		scanf("%d %d" , &x , &y);
		x ++; y ++;
		Link(x , y);
		Link(y,x);
	}
	for(int i = 1; i <= n; i ++)
		if (!dfn[i]){
			dfncount = 0;
			Tarjan(i , 0);
		}
	b.reset();
	for(int i = 1; i <= n; i ++)
		if(!b[i]) Contract(i , i);
	int ans = 0;
	for(int i = 1; i <= n; i ++)
		if(anc[i] == i) ans += sum[color[i]] * (n - sum[color[i]]);
	ans = ans / 2 % Mo;
	for(int i = 1; i <= q; i ++){
		int x;
		scanf("%d" , &x);
		x ++;
		int now = sum[color[bridge[x]]] , ancestor = sum[color[anc[bridge[x]]]];
		printf("%d\n" , (ans + now * (ancestor - now)) % Mo);
	}
	
	return 0;
}
