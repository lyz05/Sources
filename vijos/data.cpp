#include <cstdio>
#include <ctime>
#include <algorithm>
using namespace std;

int main(){
	//freopen("a.in" , "w" , stdout);
	
	srand(unsigned(time(0)));
	int t = 5;
	printf("%d\n" , t);
	for (int ti = 1; ti <= t; ti ++){
		int n = rand() % 100000 + 1 , m = rand() % 1000000000 + 1;
		printf("%d %d\n" , n , m);
		for (int i = 1; i <= n; i ++){
			int x = rand() % 1000000000 + 1 , y , z = rand() % 1000000000 + 1;
			int luck = rand() % 10000;
			if (luck == 1) y = 1;
			else y = rand() % x + 1;
			printf("%d %d %d\n" , x , y , z);
		}
	}
	
	return 0;
}
