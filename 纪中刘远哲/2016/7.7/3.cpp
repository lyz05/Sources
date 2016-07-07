#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	freopen("snow.in","r",stdin);
	//freopen("snow.out","w",stdout);

	scanf("%d%d",&n,&q);
	for (int i=1;i<n;i ++)
	{
		int x,y;
		scanf("%d%d",&x,&y); 
		add(x,y);add(y,x);
	}

	return 0;
}
