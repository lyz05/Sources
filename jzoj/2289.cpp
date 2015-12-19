#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

int n,m,k,T,S;
map <int,int>p;


const int NN = 101;//mo = 1e9+7;
struct Matrix
{
	int num[NN][NN],Node;
	Matrix()
	{
		memset(num,0,sizeof num);
		Node = n;
	}
	void init() {for (int i=0;i<=Node;i ++) num[i][i] = 1;}
	Matrix operator *(const Matrix &b) const
	{
		Matrix ret;
		for (int i=0;i<=Node;i ++)
		for (int j=0;j<=Node;j ++)
		if (num[i][j])
		for (int k=0;k<=Node;k ++)
		if (b.num[j][k])
		{
			//ret.num[i][k] += num[i][j]*b.num[j][k];
			//(ret.num[i][k] += (num[i][j]*b.num[j][k])%mo)%=mo;
			if (ret.num[i][k])
				ret.num[i][k] = min(ret.num[i][k],num[i][j]+b.num[j][k]);
			else	ret.num[i][k] = num[i][j]+b.num[j][k];
		}
		return ret;
	}
	Matrix operator +(const Matrix &b) const
	{
		Matrix ret;
		for (int i=0;i<=Node;i ++)
			for (int j=0;j<=Node;j ++)
				//ret.num[i][j] = (num[i][j]+b.num[i][j])%mo;
				ret.num[i][j] = num[i][j]+b.num[i][j];
		return ret;
	}
} a,ans;

Matrix pow(Matrix a,int y)
{
	Matrix ret;
	ret.init();
	bool flag = 0;
	while (y)
	{
		if (y & 1) 
		{
			if (!flag) flag = 1,ret = a;
			else ret = ret*a;
		}
		a = a*a;
		y >>= 1;
	}
	return ret;
}


int get(int x)
{
	if (p[x]==0) p[x] = ++n;
	return p[x];
}

int main()
{
	freopen("2289.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d%d%d%d",&k,&m,&T,&S);
	T = get(T),S = get(S);
	for (int i=1;i<=m;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&z,&x,&y);
		x = get(x),y = get(y);
		a.num[x][y] = a.num[y][x] = z;
	}
	//a.Node = n,ans.Node = n;
	a.Node = n;
	ans = pow(a,k);
	printf("%d\n",ans.num[S][T]);
	return 0;
}
