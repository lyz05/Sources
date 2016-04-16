#include <cstdio>
#include <cstring>

const int N = 1e3, M = 1e6;
int T;
int q[M];
char st[N], stt[M][N];

int Bfs(){
	bool b = 0;
	int len = strlen(st);
	for(int i = 0; i < len; i ++){
		stt[1][i] = st[i];
		if(st[i] == '-') b = 1;
	}
	if(!b) return 0;
	q[1] = 0;
	for(int L = 1, R = 1; L <= R; L ++){
		for(int i = 1; i <= len; i ++){
			++ R; b = 0;
			for(int j = i - 1; j >= 0; j --)
				if(stt[L][j] == '+') stt[R][i - j - 1] = '-';
				else stt[R][i - j - 1] = '+';
			for(int j = i + 1; j <= len; j ++) stt[R][j - 1] = stt[L][j - 1];
			q[R] = q[L] + 1;
			for(int j = 0; j < len; j ++) if(stt[R][j] == '-'){b = 1; break;}
			if(!b) return q[R];
		}
	}
}

void Work(){
	scanf("%s", st);
	printf("%d\n", Bfs());
}

int main(){
	//freopen("b.in", "r", stdin), freopen("bp.out", "w", stdout);
	
	scanf("%d", &T); int t = 0;
	while(T --){
		t++;
		printf("Case #%d: ", t);
		Work();
	}
	
	return 0;
}
