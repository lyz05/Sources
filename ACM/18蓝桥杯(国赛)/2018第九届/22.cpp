
#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
using namespace std;
typedef long long ll;
const int maxn = 2e5+5;
const double esp = 1e-12;
const int ff = 0x3f3f3f3f;
map<int,int>::iterator it;
 
ll ans;
int sta[52];
void dfs(int x)
{
	if(x == 31)
	{
		ans++;
		return ;
	}
	dfs(x+1);
	if(sta[x-1] == 0)
	{
		sta[x] = 1;
		dfs(x+1);
		sta[x] = 0;
	}
	return ;
}
 
int main()
{ 
	dfs(1);
	
	cout<<ans<<endl;
	
	return 0;

}
