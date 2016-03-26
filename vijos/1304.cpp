#include <cstdio>
#include <cstring>

using namespace std;

const int size=65;
typedef long long LL;
int n;
char m[size];

void add(char x[size],char y[size],char z[size])
{}

bool work(char x[size])
{
	char y[size],z[size];
	int len=strlen(x);
	for (int i=len-1;i>=0;i--)
		strcat(y,x[i]);
	add(x,y,z);
}

int main()
{
	scanf("%d\n%s",&n,&m);
	int step=0
	while (work(m) && step<=30) step++;
	if (step==31) printf("Impossible!\n"); else printf("%d\n",step);
	return 0;
}

