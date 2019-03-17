#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 10000+125;
int n,g,k,ans;
struct node
{
	char mail[50];
	int score;
} h[N];

bool cmp(node A,node B)
{
	if (A.score == B.score)	return strcmp(A.mail,B.mail)<0;
	else return A.score>B.score;
}

int main()
{
	scanf("%d%d%d",&n,&g,&k);
	for (int i=1;i<=n;i ++)
		scanf("%s%d",h[i].mail,&h[i].score);
	sort(h+1,h+1+n,cmp);
	
	for (int i=1;i<=n;i ++)
	{
		if (h[i].score>=g) ans += 50;
		else if (h[i].score>=60) ans += 20;
	}
	printf("%d\n",ans);
	int lscore = -1,j = 0;
	for (int i=1;i<=n;i ++)
	{
		j = (lscore!=h[i].score)?i:j;
		if (j>k) break;
		printf("%d %s %d\n",j,h[i].mail,h[i].score);
		lscore = h[i].score;
	}
	return 0;
}
