#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

const int MAXN = 1e6 + 10;
int n, totl, totff, ans;
int Last[MAXN], Lastff[MAXN], F[MAXN], a[MAXN];
bool b[MAXN];
struct side{
	int x, y;
} S[MAXN], FF[MAXN];

void Link(int x, int y){S[++ totl].x = y; S[totl].y = Last[x]; Last[x] = totl;}

bool Judge(int x, int y){
	while(FF[Lastff[x]].x != 0 && !b[FF[Lastff[x]].x]) Lastff[x] = FF[Lastff[x]].y;
	if(FF[Lastff[x]].x == 0 || a[FF[Lastff[x]].x] > a[y]) return 0;
	return 1;
}

int Half(int x,int deep){
	int L = 1, R = deep;
	while(L <= R){
		int mid = (L + R) / 2;
		if(Judge(mid, x)) L = mid + 1;
		else R = mid - 1;
	}
	return R;
}

void Dp(int x, int deep){
	b[x] = 1;
	F[x] = Half(x, deep) + 1;
	if(F[x] > ans) ans = F[x];
	if(FF[Lastff[F[x]]].x == 0 || a[FF[Lastff[F[x]]].x] > a[x]){
		FF[++ totff].x = x; FF[totff].y = Lastff[F[x]]; Lastff[F[x]] = totff;
	}
	for(int p = Last[x]; p; p = S[p].y)
		Dp(S[p].x, deep + 1);
	b[x] = 0;
}

void Input(int &x){
	char c;
	bool b = 0, Fu = 0;
	while((c = getchar()) != EOF){
		if(isdigit(c)){b = 1; x = x * 10 + c - '0';}
		else if(c == '-'){Fu = 1;}
		else if(b) break;
	}
	if(Fu) x = -x;
}

void Work(){
	scanf("%d", &n);
	for(int i = 2; i <= n; i ++){
		int x = 0; Input(x);
		Link(x, i);
	}
	for(int i = 1; i <= n; i ++) Input(a[i]);
	Dp(1, 1);
	printf("%d", ans);
}

int main(){
	freopen("cicada1.in", "r", stdin);
	//freopen("cicada.out", "w", stdout);
	
	Work();
	
	return 0;
}
