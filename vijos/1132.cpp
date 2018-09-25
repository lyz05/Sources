#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 25;

char mid[N],behind[N],front[N];

void dfs(int l1,int r1,int l2,int r2)
{
	printf("%c",behind[r2]);
	if (l1<r1)
		for (int i=l1;i<=r1;i ++)
			if (mid[i] == behind[r2])
			{
				if (l1<=i-1) dfs(l1,i-1,l2,l2+i-1-l1);// left tree
				if (i+1<=r1) dfs(i+1,r1,l2+i-l1,r2-1);// right tree
			}
}

int main()
{
	int len;
	scanf("%s",mid);
	scanf("%s",behind);
	for (int i=0;i<N;i ++) 
		if (mid[i]=='\000') 
		{
			len = i;
			break;
		}
	dfs(0,len-1,0,len-1);
	return 0;
}