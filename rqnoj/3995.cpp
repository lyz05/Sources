#include <cstdio>
#include <cstring>

using namespace std;

const int N=10+5;

int n;
char cube[N][N][N];
char map[6][N][N];

bool inside(int x,int y,int z)	//判断cube[x][y][z]是否合法
{
	return 0<=x && x<n && 0<=y && y<n && 0<=z && z<n;
}

int paint(int dir) //return 1 表示矛盾 return -1 表示不合法 return 0 合法
{
	int res=0;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			int a,b,c,dx,dy,dz;
			dx=dy=dz=0;
			//dir前左后右下上
			switch(dir)
			{
				case 0:
					a=n-1,b=j,c=i,dx=-1;
					break;
				case 1:
					a=j,b=0,c=i,dy=1;
					break;
				case 2:
					a=0,b=n-1-j,c=i,dx=1;
					break;
				case 3:
					a=n-1-j,b=n-1,c=i,dy=-1;
					break;
				case 4:
					a=i,b=j,c=0,dz=1;
					break;
				case 5:
					a=n-1-i,b=j,c=n-1,dz=-1;
					break;
			}
			//给出cube[a][b][c]初始位置，及深入方向
			while (inside(a,b,c) && cube[a][b][c]=='.')
				a+=dx,b+=dy,c+=dz;
			//找到方块准确位置
			while (inside(a,b,c) && map[dir][i][j]=='.')
			{
				cube[a][b][c]='.';
				a+=dx,b+=dy,c+=dz;
			}
			//贯穿整个方向的方块
			if (map[dir][i][j]=='.') continue;
			if (!inside(a,b,c) && map[dir][i][j]!='.')
				return -1;
			//方块已被打穿，与map有颜色矛盾,数据不合法，不存在方案
			if (cube[a][b][c] && cube[a][b][c]!=map[dir][i][j])
				cube[a][b][c]='.',res=1;//存在染色，但是矛盾
			else if (!cube[a][b][c])	//不存在颜色
				cube[a][b][c]=map[dir][i][j];//染色
		}
	
	}
	return res;
}

int main()
{
	freopen("3995.in","r",stdin);freopen("3995.out","w",stdout);
	while (scanf("%d",&n) , n)
	{
		for (int i=0;i<n;i++)
			for (int j=0;j<6;j++)
				scanf(" %s",map[j][i]);
		//数据读入

		int ans=0;
		memset(cube,0,sizeof(cube));
		while (true)			//寻找答案
		{
			bool tmp=false;
			for (int i=0;i<n;i++)
				for (int j=0;j<n;j++)
					for (int k=0;k<n;k++)
					{
						if (cube[i][j][k]!='.')
							cube[i][j][k]=0;
					}
			//清除染色数据重新paint
			for (int i=0;i<6;i++)
			{
				int ans=paint(i);//得到染色情况
				if (ans==-1) break;
					else if (ans==1) tmp=true;
			}
			if (ans==-1 || !tmp) break;
		}

		if (ans!=-1)
		{
			for (int i=0;i<n;i++)
				for (int j=0;j<n;j++)
					for (int k=0;k<n;k++)
						ans+=(cube[i][j][k] != '.');

		} else ans=0;			//统计答案
		printf("Maximum weight: %d gram(s)\n", ans);
		//数据输出
	}
	return 0;
	
}
