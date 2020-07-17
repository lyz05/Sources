#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
using namespace std;
int main()
{
    int n,sum;
    char a[50],b[50];
    while(scanf("%d",&n),n)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        map<string,int>m;
        map<string,int>::iterator it;
        sum=0;
        while(n--)
        {
            scanf("%s%s",a,b);
            if(m.count(a)==0)
                m[a]=1;
            m[b]=0; //输过的不可能是冠军
        }
        for(it=m.begin();it!=m.end();it++)
            sum+=it->second;
        if(sum==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
