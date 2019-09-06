#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int ans[20][20];
int map1[20][20];
int lasans[20][20];
int M,N;
int minans;

int getdata()
{
    for(int i=1;i<=M;++i)
        for(int j=1;j<=N;++j)
            cin>>map1[i][j];
}

inline void slove()
{
    minans=1e8;
    int L=(1<<N);
    int rem;
    bool ok;

    for(int i=0;i<L;++i)
    {
        rem=0;

        for(int j=1;j<=N;++j)
            if((1<<(j-1))&i)
            {
                ans[1][j]=1;
                ++rem;
            }
            else
                ans[1][j]=0;

        for(int j=2;j<=M;++j)
        {
            for(int k=1;k<=N;++k)
            {
                if((map1[j-1][k]+ans[j-1][k]+ans[j-2][k]+ans[j-1][k-1]+ans[j-1][k+1])%2)
                {
                    ans[j][k]=1;
                    ++rem;
                    if(rem>minans)
                        goto next1;
                }
                else
                    ans[j][k]=0;
            }
        }

        ok=1;
        for(int j=1;j<=N;++j)
            if((map1[M][j]+ans[M][j]+ans[M-1][j]+ans[M][j-1]+ans[M][j+1])%2)
            {
                ok=0;
                break;
            }

        if(ok)
            if(rem<minans)
            {
                minans=rem;
                for(int i=1;i<=M;++i)
                    for(int j=1;j<=N;++j)
                        lasans[i][j]=ans[i][j];
            }

        next1:;
    }
}

int main()
{
	//freopen("C.in","r",stdin);
    ios::sync_with_stdio(false);

    while(cin>>M>>N)
    {
        memset(ans,0,sizeof(ans));
        memset(map1,0,sizeof(map1));

        getdata();
        slove();

        if(minans==1e8)
            cout<<"IMPOSSIBLE\n";
        else
            for(int i=1;i<=M;++i,cout<<endl)
                for(int j=1;j<=N;++j)
                    cout<<lasans[i][j]<<' ';
    }

    return 0;
}