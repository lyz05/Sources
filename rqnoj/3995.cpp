#include <cstdio>
#include <cstring>

using namespace std;

const int N=10+5;

int n;
char cube[N][N][N];
char map[6][N][N];

bool inside(int x,int y,int z)	//�ж�cube[x][y][z]�Ƿ�Ϸ�
{
	return 0<=x && x<n && 0<=y && y<n && 0<=z && z<n;
}

int paint(int dir) //return 1 ��ʾì�� return -1 ��ʾ���Ϸ� return 0 �Ϸ�
{
	int res=0;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			int a,b,c,dx,dy,dz;
			dx=dy=dz=0;
			//dirǰ���������
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
			//����cube[a][b][c]��ʼλ�ã������뷽��
			while (inside(a,b,c) && cube[a][b][c]=='.')
				a+=dx,b+=dy,c+=dz;
			//�ҵ�����׼ȷλ��
			while (inside(a,b,c) && map[dir][i][j]=='.')
			{
				cube[a][b][c]='.';
				a+=dx,b+=dy,c+=dz;
			}
			//�ᴩ��������ķ���
			if (map[dir][i][j]=='.') continue;
			if (!inside(a,b,c) && map[dir][i][j]!='.')
				return -1;
			//�����ѱ��򴩣���map����ɫì��,���ݲ��Ϸ��������ڷ���
			if (cube[a][b][c] && cube[a][b][c]!=map[dir][i][j])
				cube[a][b][c]='.',res=1;//����Ⱦɫ������ì��
			else if (!cube[a][b][c])	//��������ɫ
				cube[a][b][c]=map[dir][i][j];//Ⱦɫ
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
		//���ݶ���

		int ans=0;
		memset(cube,0,sizeof(cube));
		while (true)			//Ѱ�Ҵ�
		{
			bool tmp=false;
			for (int i=0;i<n;i++)
				for (int j=0;j<n;j++)
					for (int k=0;k<n;k++)
					{
						if (cube[i][j][k]!='.')
							cube[i][j][k]=0;
					}
			//���Ⱦɫ��������paint
			for (int i=0;i<6;i++)
			{
				int ans=paint(i);//�õ�Ⱦɫ���
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

		} else ans=0;			//ͳ�ƴ�
		printf("Maximum weight: %d gram(s)\n", ans);
		//�������
	}
	return 0;
	
}
