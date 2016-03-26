#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
const int oo = 1000000000;
using namespace std;

struct case1
{
   int v;
};
char a[200001][3];
int b[200001],c[200001],rec[200001];
priority_queue<case1> h;

bool operator < (case1 x,case1 y)
{
   return b[x.v]>b[y.v];
}

int main()
{
   int n,o=0,ans=0;
   cin>>n;
   for (int i=1;i<n;i++)
      scanf("%s%d",a[i],&b[i]);
   c[n-1]=oo;
   for (int i=n-2;i;i--)
   {
      c[i]=c[i+1];
      if (a[i][0]=='p')
         c[i]=min(c[i],b[i]-1);
   }
   for (int i=1;i<n;i++)
   {
      if (a[i][0]=='d')
         h.push((case1){i});
      while (h.size()>c[i])
         h.pop();
   }
   while (h.size())
   {
      rec[++o]=h.top().v;
      ans+=b[rec[o]];
      h.pop();
   }
   if (o>=b[n-1])
      cout<<ans<<endl;
   else
      cout<<-1<<endl;
   return 0;
}
