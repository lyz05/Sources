#include <cstdio>
#include <cstring>

int max(int x,int y)
{
	int t=x>y?x:y;
	return t;
}

const int N = 205;
int a[N][N],b[N][N],v[N][N],tot[N][N],f[N][N];
int n,m,k;

int main(){
	freopen("1249.in","r",stdin);

	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j ++){
			char ch;
			scanf("%d %c",&a[i][j],&ch);
			if (ch=='Y') b[i][j]=1;
		}
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j ++)
		{
			tot[i][j]=tot[i][j-1]+a[n-j+1][i];
			//�ܻ�õ�����
			if ((!b[n-j+1][i]) || (v[i][j-1]>=k)) 
				v[i][j]=v[i][j-1]+1;
			//�����ǰ�����н����ӵ�������Ҫ�ӵ���ǰ���ǵ�ǰ�ӵ���û�þ�
			else v[i][j]=v[i][j-1];
		}
	int ans=0;
	memset(f,255,sizeof f);//����ֵ-1
	//f����ǰi�з����˹�j���ӵ����������
	for (int i=1;i<=n;i ++)
		if (v[1][i]<=k) f[1][v[1][i]]=tot[1][i];
	f[1][0]=0;
	for (int i=1;i<m;i++)
		for (int j=0;j<=k;j++){
			if (f[i][j]==-1) continue;
			f[i+1][j]=max(f[i][j],f[i+1][j]);
			for (int l=1;l<=n;l++){
				if (v[i+1][l]+j>k) break;
				//�ﵽ��һ����Ҫ���ӵ����Ѿ��õ��ӵ����������ӵ�
				f[i+1][v[i+1][l]+j]=max(f[i+1][v[i+1][l]+j],f[i][j]+tot[i+1][l]);
				ans=max(ans,f[i+1][v[i+1][l]+j]);
			}
		}
	printf("%d\n",ans);
	return 0;
}
