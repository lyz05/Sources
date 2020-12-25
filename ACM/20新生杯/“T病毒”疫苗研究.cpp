#include <cstdio>
using namespace std;

void dfs(int l,int r, char c)
{
    if (l>r) return;
    int mid = (l+r)/2;
    dfs(l,mid-1,'R');
    putchar(c);
    dfs(mid+1,r,'L');

}

int main()
{
    int n;
    //freopen("0.in","r",stdin);
    //freopen("0.out","w",stdout);
    while (~scanf("%d",&n)) {
        dfs(1,n,'R');
        puts("");
    }
	return 0;
 } 
/*
1
2 3
4 5 6 7
8 9 10 11 12 13 14 15
*/
