#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

typedef long long LL;
const int N = 50005,mo1 = N,mo2 = 1e6+7;
char s[3][N*2],t[3][N];
int p[3][N*2];
int len;
LL ans;

struct node
{
	LL num[3],ha;
} a[N];
//map <int,node> a;

void cmp(int kind)
{
	int mx = 0,id;
	int n = strlen(s[kind]);
	for (int i=1;i<n;i ++)
	{
		if (mx>i) p[kind][i] = min(p[kind][2*id-i],mx-i);
		else p[kind][i] = 1;
		for (;s[kind][i+p[kind][i]]==s[kind][i-p[kind][i]];p[kind][i] ++);
		if (p[kind][i]+i>mx)
		{
			mx = p[kind][i]+i;
			id = i;
		}
	}
}

void insert(int ha1,int ha2,int kind)
{
	ha1 = ha1%mo1;
	ha2 = ha2%mo2;
	for (;a[ha1].ha!=0 && a[ha1].ha!=ha2;ha1 ++);
	a[ha1].ha = ha2;
	a[ha1].num[kind] ++;
}

int main()
{
	//freopen("3291.in","r",stdin);
	//freopen("3291.out","w",stdout);
	s[1][0]=s[2][0]='$';
	scanf("%s\n%s\n",t[1]+1,t[2]+1);

	for (int j=1;j<=2;j ++)
	{
		len = strlen(t[j]+1);
		for (int i=1;i<=len;i ++) s[j][2*i] = t[j][i],s[j][2*i-1]='#';
		s[j][2*len+1] = '#',s[j][2*len+2] = '\0';
	}

	cmp(1);cmp(2);
	for (int k=1;k<=2;k ++)
	{
		int len = strlen(s[k])-1,ha1,ha2;
		for (int i=1;i<=len;i ++)
		{
			ha1 = 0;ha2 = 0;
			if (s[k][i]=='#')
			{
				for (int j=1;j<=p[k][i]-1;j ++)
				{
					int tmp = (s[k][i-j]=='#')?27+'A':s[k][i-j];
					ha1 = (ha1*27+tmp-'A'+1)%mo1;
					ha2 = (ha2*27+tmp-'A'+1)%mo2;
					if (j%2==0) 
						insert(ha1,ha2,k);
					//printf("%c",s[k][i-j]);
				}
			} else
			{
				int tmp = (s[k][i]=='#')?27+'A':s[k][i];
				ha1 = (ha1*27+tmp-'A'+1)%mo1;
				ha2 = (ha2*27+tmp-'A'+1)%mo2;
				//printf("%c",s[k][i]);
				insert(ha1,ha2,k);
				for (int j=2;j<=p[k][i]-1;j ++)
				{
					int tmp = (s[k][i-j]=='#')?27+'A':s[k][i-j];
					ha1 = (ha1*27+tmp-'A'+1)%mo1;
					ha2 = (ha2*27+tmp-'A'+1)%mo2;
					if (j%2==1) 
						insert(ha1,ha2,k);
					//printf("%c",s[k][i-j]);
				}
			}
			//puts("");
			//for (int j=1;j<=p[k][i]-1;j += 2)
		}
	}
	/*
	for (map<int,node>::iterator it=a.begin();it!=a.end();it ++)
	{
		node A = it->second;
		ans += A.num[1]*A.num[2];
		//printf("%d\n",it->first);
	}
	*/
	for (int i=0;i<N;i ++) ans += (LL)a[i].num[1]*a[i].num[2];
	printf("%lld\n",ans);
	return 0;
}
