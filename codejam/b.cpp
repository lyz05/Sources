#include <cstdio>
#include <cstring>

const int Len = 1e3;
int T;
char st[Len];

void Work(){
	int ans = 0;
	scanf("%s", st);
	int len = strlen(st);
	for(int i = 1; i < len; i ++)
		if(st[i] != st[i - 1]) ans ++;
	if(st[len - 1] == '-') ans ++;
	printf("%d\n", ans);
}

int main(){
	//freopen("b.in", "r", stdin), freopen("b.out", "w", stdout);
	
	scanf("%d", &T); int t = 0;
	while(T --){
		t ++; printf("Case #%d: ", t); Work();
	}
	
	return 0;
}
