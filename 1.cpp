#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

const int maxn=510;

int n,m,i,j,tot,ans,q,l[30],level[30],cost[30][30],value[30][30],f[30][maxn],head[30],next[30],g[30];
string s[30],fa[30];

void insert(int x,int y)
{
printf("%d %d\n",x,y);
head[++tot]=y;
next[tot]=g[x];
g[x]=tot;
}

bool cmp(string a,string b)
{
if (a.length()!=b.length()) return false;
int t=a.length();
for (int i=0;i<t;i++)
if (a[i]!=b[i]) return false;
return true;
}

void dfs(int a)
{
int i,j,k,t;
if (level[a]==0) t=cost[a][1]; else
{
t=0;
f[a][0]=0;
}
for (i=level[a]+1;i<=l[a];i++)
f[a][cost[a][i]-cost[a][level[a]]]=value[a][i];
for (i=g[a];i;i=next[i])
{
if ((a!=0)&&(level[head[i]])) continue;
dfs(head[i]);
for (j=q;j>t;j--)
for (k=0;k<=j-t;k++)
if ((f[head[i]][k]!=-1)&&(f[a][j-k]!=-1)&&(f[head[i]][k]+f[a][j-k]>f[a][j]))
f[a][j]=f[head[i]][k]+f[a][j-k];
}
}

int main()
{
freopen("1.in","r",stdin);
scanf("%d\n",&n);
for (i=1;i<=n;i++)
{
getline(cin,s[i]);
getline(cin,fa[i]);
cout<<s[i];
printf("\n");
cout<<fa[i];
printf("\n");
scanf("%d\n",&l[i]);
for (j=1;j<=l[i];j++) {scanf("%d",&cost[i][j]);cost[i][j]+=cost[i][j-1];}
for (j=1;j<=l[i];j++) {scanf("%d",&value[i][j]);value[i][j]+=value[i][j-1];}
scanf("\n");
}
scanf("%d",&q);
for (i=1;i<=n;i++)
{
scanf("%d",&level[i]);
if (level[i]) insert(0,i);
for (j=level[i]+1;j<=l[i];j++) value[i][j]=value[i][j]-value[i][level[i]];
}
for (i=1;i<=n;i++)
{
if (level[i]) continue;
if (fa[i].length()==0) insert(0,i);
else
{
if (i==1) printf("wrong!");
for (j=1;j<=n;j++)
if (cmp(s[j],fa[i])) {insert(j,i);break;}
}
}
memset(f,255,sizeof(f));
f[0][0]=0;
dfs(0);
for (i=0;i<=q;i++) ans=max(ans,f[0][i]);
printf("%d\n",ans);
return 0;
} 
