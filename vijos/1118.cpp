#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define for1(v,a,b) for (int v=a;v<=b;v++)
#define for2(v,a,b) for (int v=a;v>=b;v--)
using namespace std;
char s[201],word[10][201];
int f[201][201][41],sum[201][201],len[10];
int n,k,p,part;
void Init(){
    char ch;
    int pos;
    for1(i,0,p-1){
        scanf("%c",&ch);
        for1(j,1,20)
            scanf("%c",&s[i*20+j]);
    }
    scanf("%d",&k);
    scanf("%c",&ch);
    for1(i,1,k){
        pos=0;
        while (scanf("%c",&ch),(ch>='a')&&(ch<='z'))
            pos++,word[i][pos]=ch;
        len[i]=pos;
    }
    n=20*p;    
}
void check(int x,int y){
    bool flag=true;
    for1(i,1,len[y])
        if (s[x+i-1]!=word[y][i]){
            flag=false;
            break;
        }
    if (!flag) return;
    for1(i,1,x){
        sum[i][x+len[y]-1]++;
        f[i][x+len[y]-1][0]=sum[i][x+len[y]-1];
    }
    for1(i,x+len[y]-1,n){
        sum[x][i]++;
        f[x][i][0]=sum[x][i];
    } 
}
int main(){
    //freopen("p1.in","r",stdin);
    scanf("%d%d",&p,&part);
    Init();
    for1(i,1,n)
        for1(j,1,k)
            if (i+len[j]<=n+1) check(i,j);
    for1(t,1,part)
        for1(i,1,n)
            for1(j,i+1,n)
                for1(h,i+1,j-1)
                f[i][j][t]=max(f[i][j][t],f[i][h][t-1]+f[h+1][j][t-1]);
    printf("%d",f[1][n][part]);
    return 0;

}
