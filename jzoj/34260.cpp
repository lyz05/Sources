#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct rec{int x,y;}c[200010];
int a[100010],b[100010],n,i,p;
long long sa,sp,ans;
bool operator <(rec a,rec b)
{
 return a.x<b.x||a.x==b.x&&a.y>b.y;
}
int main()
{
 freopen("seal.in","r",stdin);
 freopen("seal.out","w",stdout);
 cin>>n;
 for(i=1;i<=n;i++)
 {
  scanf("%d%d",&a[i],&b[i]);
  sa+=a[i];
  c[i].x=a[i],c[i].y=1;
  c[n+i].x=b[i],c[n+i].y=-1; 
 }
 sort(c+1,c+2*n+1);
 for(i=1;i<=2*n;i++)
  if(c[i].y==1)
  {
   sp++,sa-=c[i].x;
   if(ans<sa+sp*c[i].x) ans=sa+sp*c[i].x,p=c[i].x;
  }
  else{
   if(ans<sa+sp*c[i].x) ans=sa+sp*c[i].x,p=c[i].x;
   sp--;
  }
 cout<<p<<' '<<ans<<endl;
 fclose(stdin),fclose(stdout);
 return 0; 
}
