#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 10000+5;
int n,ans,a[N];
string s;

struct Node
{
	int l,r,mid,num;
}h[4*N];

int query(int id,int l,int r)
{
	if (l>r) return 0;
	if (l==h[id].l && r==h[id].r)
	{
		return h[id].num;
	}
	if (r<=h[id].mid)
		return query(id*2,l,r);
	else if (l>h[id].mid)
		return query(id*2+1,l,r);
	else return max(query(id*2,l,h[id].mid),query(id*2+1,h[id].mid+1,r));
}

void maketree(int id,int l,int r)
{
	h[id].l = l;
	h[id].r = r;
	h[id].mid = (l+r)>>1;
	if (l==r)
	{
		h[id].num = a[l];
		return;
	}
	maketree(id*2,l,h[id].mid);
	maketree(id*2+1,h[id].mid+1,r);
	h[id].num = max(h[id*2].num,h[id*2+1].num);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("1003.out","w",stdout);
	
	while (cin >> n && n)
	{
		for (int i=1;i<=n;i ++) cin >> a[i];
		maketree(1,1,n);
		cin >> s;
		for (int k=0,i=0,j=0,maxid=0;k<s.length();k ++)
		{
			if (s[k] == 'm') 
				j ++;
			else 
				i ++;
			cout << query(1,i+1,j) << ((k+1<s.length())?" ":"");
		}
		cout << endl;
	}
	return 0;
}

//5
//1 2 4

//13
//1 2 4 8 
