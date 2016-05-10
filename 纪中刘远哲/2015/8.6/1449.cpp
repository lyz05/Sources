#include<cstdio>
#include<cstring>
#include<algorithm>

#define Rep(i) for (int i=1;i<=9;i++)
#define ID(i,j) ((i-1)/3*3+(j-1)/3+1)
#define in(i,x,y) (i>=x&&i<=y)
using namespace std;

typedef int Matrix[10][10];
Matrix P,A,can;
int Fx[10][10],Fy[10][10],Fz[10][10],xx[10];
struct node {int x,y;} List[81+19];
int Ans=-1,tmp,x,cnt;

int cmp(node A,node B) 
{
    if (xx[A.x]!=xx[B.x]) return xx[A.x]<xx[B.x];
    return can[A.x][A.y]<can[B.x][B.y];
}
void DFS(int cur)
{
    if (cur==cnt) {Ans=max(Ans,tmp);return;}
    int x=List[cur].x,y=List[cur].y;
    Rep(k) if (Fx[x][k]&&Fy[y][k]&&Fz[ID(x,y)][k]) 
    {
        tmp+=k*P[x][y];
        Fx[x][k]=Fy[y][k]=Fz[ID(x,y)][k]=0;
        DFS(cur+1);
        Fx[x][k]=Fy[y][k]=Fz[ID(x,y)][k]=1;
        tmp-=k*P[x][y];
    }
}

int main()
{
    Rep(i) Rep(j) Fx[i][j]=Fy[i][j]=Fz[i][j]=1;
    Rep(i) Rep(j)
        P[i][j]=
        (in(i,5,5)&&in(j,5,5)?10:
        (in(i,4,6)&&in(j,4,6)?9:
        (in(i,3,7)&&in(j,3,7)?8:
        (in(i,2,8)&&in(j,2,8)?7:6))));
    Rep(i) Rep(j)
    {
        scanf("%d",&x);
        if (x) tmp+=x*P[i][j],Fx[i][x]=Fy[j][x]=Fz[ID(i,j)][x]=0;
        A[i][j]=x;
    }
    Rep(i) Rep(j)
        if (!A[i][j])
        {
            List[cnt++]=(node){i,j};xx[i]++;
            Rep(k) can[i][j]+=Fx[i][k]&&Fy[j][k]&&Fz[ID(i,j)][k];
        }
    sort(List,List+cnt,cmp);
    DFS(0);
    printf("%d\n",Ans);
}
