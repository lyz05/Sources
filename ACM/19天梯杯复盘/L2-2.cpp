#include <iostream>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

const int M = 125,N = 1e5+7;
int n,m,dep[N];
map <string,int> maps;
struct node
{
	char name[M],fname[M];
	int sex;
} h[N];

int gf(int x) {return maps[string(h[x].fname)];}

int LCA(int x,int y)
{
	while (dep[x]>dep[y]) x = gf(x);
	while (dep[x]<dep[y]) y = gf(y);
	while (x!=y) x = gf(x),y = gf(y);
	return x;
}

int query(char s1[],char s2[],char s3[],char s4[])
{
	if (maps[string(s1)]==0 || maps[string(s3)]==0) return -2;
	int L = maps[string(s1)],R = maps[string(s3)];
	if (h[L].sex==h[R].sex) return -1;
	
	int id = LCA(L,R);
	//if (id==L || id==R) return 0;
	if (dep[R]-dep[L]==4) return 1;
	if ((dep[L]-dep[id]<4 || dep[R]-dep[id]<4) && id) return 0; else return 1;
}

int dfs(int x)
{
	if (x==0) return 1;
	if (dep[x]) return dep[x];
	return dep[x] = dfs(gf(x))+1;
}

int main()
{
	freopen("L2-2.in","r",stdin);
	cin >> n;
	for (int i=1;i<=n;i ++)
	{
		cin >> h[i].name >> h[i].fname;
		char ch = h[i].fname[strlen(h[i].fname)-1];
		if (ch=='m' || ch=='n') h[i].sex = 1; else h[i].sex = 0;
		if (ch=='m' || ch=='f') h[i].fname[strlen(h[i].fname)-1] ='\0';
		if (ch=='n') h[i].fname[strlen(h[i].fname)-4] = '\0';
		if (ch=='r') h[i].fname[strlen(h[i].fname)-7] = '\0';
		maps[string(h[i].name)] = i;
		//cout << h[i].name << " " << h[i].fname << " " << h[i].sex << endl;
	}
	for (int i=1;i<=n;i ++)
		dfs(i);
	cin >> m;
	for (int i=1;i<=m;i ++)
	{
		char s1[M],s2[M],s3[M],s4[M];
		cin >> s1 >> s2 >> s3 >> s4;
		int t = query(s1,s2,s3,s4);
		if (t==-2) cout << "NA" << endl;
		if (t==-1) cout << "Whatever" << endl;
		if (t==0) cout << "No" << endl;
		if (t==1) cout << "Yes" << endl; 
	}
	return 0;
} 
