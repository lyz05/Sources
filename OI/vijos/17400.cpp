#include <cstdio>
#include <iostream>
using namespace std;
long long w[200005],v[200005],l[200005],r[200005];
long long ans=(~0LLU>>4);
long long pre[200005];
long long num[200005];
long long n,m,s;
long long Check(long long x)
{
    long long ans=0;
    for (int i=1;i<=n;i++)
    {
        if (w[i]>=x) pre[i]=pre[i-1]+v[i],num[i]=num[i-1]+1;
        else pre[i]=pre[i-1],num[i]=num[i-1];
    }
    for (int i=1;i<=m;i++)
        ans+=(pre[r[i]]-pre[l[i]-1])*(num[r[i]]-num[l[i]-1]);
    return ans;
}
long long MaxW=0;
int main()
{
    freopen("17400.in","r",stdin);
    //freopen("data.out","w",stdout);
    scanf("%I64d%I64d%I64d",&n,&m,&s);
    for (int i=1;i<=n;i++) scanf("%I64d%I64d",w+i,v+i),MaxW=max(MaxW,w[i]);
    for (int i=1;i<=m;i++) scanf("%I64d%I64d",l+i,r+i);
    long long ll=0,rr=MaxW+1,mid,T;
    while (ll<rr-3)
    {
        mid=ll+rr>>1;
        T=Check(mid);
        if (T<s)
        {
            rr=mid;
            ans=min(ans,s-T);
        }
        else
        {
            ll=mid;
            ans=min(ans,T-s);
        }
    }
    for (int i=ll;i<=rr;i++)
    {
        T=Check(i);
        if (T>s) ans=min(ans,T-s);
        else ans=min(ans,s-T);
    }
    printf("%I64d",ans);
    return 0;
}
