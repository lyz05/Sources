#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
using namespace std;

const int N = 10,M = 105;
struct node 
{
	int dep;
	char s[M];
} st,en;
vector <char> v;
queue <node>Q;
map <string,int>flag;
int n,len[N][3];
char list[N][3][M];

bool check(node &A,node &B)
{
	if (strlen(A.s)!=strlen(B.s)) return 0;
	for (int i=0;i<strlen(A.s);i ++)
		if (A.s[i]!=B.s[i]) return 0;
	return 1;
}

void check(node &tmp,int a,int b)
{
	for (int i=a;i<a+len[b][1];i ++)
		if (list[b][1][i-a]!=tmp.s[i])
			return;
	v.clear();
	node now;
	for (int i=0;i<a;i ++) v.push_back(tmp.s[i]);
	for (int i=0;i<len[b][2];i ++) v.push_back(list[b][2][i]);
	for (int i=a+len[b][1];i<strlen(tmp.s);i ++) v.push_back(tmp.s[i]);
	for (int i=0;i<v.size();i ++)
		now.s[i] = v[i];
	now.s[v.size()] = '\0';
	now.dep = tmp.dep + 1;
	if (strlen(now.s)>20) return;
	if (!flag[now.s])
	{
		flag[now.s] = 1;
		Q.push(now);
	}
}


void bfs()
{
	Q.push(st);
	while (!Q.empty())
	{
		node now = Q.front();Q.pop();
		if (now.dep>10)
		{
			printf("NO ANSWER!\n");
			break;
		}
		if (check(now,en))
		{
			printf("%d\n",now.dep);
			break;
		}
		for (int i=0;i<strlen(now.s);i ++)
		for (int j=1;j<=n;j ++)
			check(now,i,j);
		if (Q.empty()) printf("NO ANSWER!\n");
	}
}

int main()
{
	freopen("1124.in","r",stdin);
	//freopen("1124.out","w",stdout);

	scanf("%s %s",st.s,en.s);
	for (n=1;scanf("%s %s",list[n][1],list[n][2])!=EOF;n ++)
	{
		len[n][1] = strlen(list[n][1]);
		len[n][2] = strlen(list[n][2]);
	}
	n --;
	bfs();

	return 0;
}
