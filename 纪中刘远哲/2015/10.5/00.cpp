#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	freopen("mission.in","r",stdin);
	//freopen("mission.out","w",stdout);
	int ret = 0;
	for (int i=2;i<=20;i ++) ret += i*i;
	printf("%d\n",ret);	
	return 0;
}
