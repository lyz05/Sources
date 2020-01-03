#include <cstdio>

long long st=0,m=0,tt;
int l,t,ans,tmp=0;
char s[100];
int a[100];

void dfs(int dep,int cnt)
{
	if (cnt<0) return;
	if (dep>l-t) {
		for (int i=dep;i<l;i++){
			if ((st & (long long) 1<<i)!=0) cnt --;
		}
		if ((cnt==0) && (tmp<ans)) {
			ans=tmp;
		}
		return;
	}
	for (int i=0;i<=1;i++)
	{
		if (i==0) {
			a[dep]=true;
			tmp ++;
			st^=(long long) m<<dep;
			
			if ((st & (long long) 1<<dep)!=0){
				dfs(dep+1,cnt-1);
			}else {
				dfs(dep+1,cnt);
			}
			st^=(long long) m<<dep;
			tmp --;
			a[dep]=false;
		}else {

			if ((st & (long long) 1<<dep)!=0){
				dfs(dep+1,cnt-1);
			}else {
				dfs(dep+1,cnt);
			}
		}
	}
}

int main()
{
	freopen("xlite.in","r",stdin);
	freopen("xlite.out","w",stdout);
	
	scanf("%d%d\n",&l,&t);
	scanf("%s",&s);
	for (int i = 0;i < l;i ++) {
		st=(st<<1)+s[i]-'0';
	}
	scanf("%s",&s);
	for (int i = 0;i < t;i ++) m=(m<<1)+s[i]-48;

	for (int i=0;i<=l;i ++)
	{
		ans=1<<30;
		dfs(0,i);
		if (ans!=1<<30) 
		{
			printf("%d\n",ans);
			return 0;
		}
	}

	return 0;
}
