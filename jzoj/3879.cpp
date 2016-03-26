#include <cstdio>
#include <cmath>
using namespace std;

long long a, b;

int main() {
	
	while (scanf("%lld%lld", &a, &b) != -1) {
		if (a == 1000000000) {
			if (!b)	printf("no\n");
			else	printf("yes\n");
		}else {
			if (abs(a) <= 1000000000 || a + b == 1000000000)	printf("no\n");
			else	printf("yes\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
}
