#include <cstdio>
#include <cstring>
int k;
long long ans;
int n,m,x;
long long Exp(int y){
	if(!y)return 1;
	if(y==1)return 10%n;
	if(y&1){
		return(((Exp(y>>1)*Exp(y>>1))%n)*10)%n;
	}else return(Exp(y>>1)*Exp(y>>1))%n;
}
int main(){
scanf("%d%d%d%d",&n,&m,&k,&x);
ans=Exp(k);
ans*=m;
ans%=n;
ans+=x;
ans%=n;
printf("%lld",ans);
return 0;
