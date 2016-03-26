#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std ;

#define N 16 

int a[N],i,j,k,n,t ;

typedef long long ll ;

struct ecc {
       int  nu ;
       ll va ;
}co[100010] ;

const ll maxans = (ll) 100000 * 100000 * 100000 ;

int gcd( int a , int b ) {
	if( b==0 ) return a ;  
	return gcd( b , a % b ) ;
}

void Combine(  int dep , int st , ll now  ) {
	int i ;
	if( dep!=0 ) co[++t].va = now , co[t].nu = dep ;
	for( i=st+1 ; i<=n ; i++ ) {
		ll j ;
		if( dep==0 ) j = 1 ; else j = now / gcd( now , a[i] ) ;
		j *= a[i] ;
		if( j>maxans ) continue ;
		Combine( dep+1 , i , j ) ;
	}
}

ll P( ll x ) {
	int i , j , k ;
	ll sum = 0  ;
	for( i=1 ; i<=t ; i++ ) {
		if( co[i].nu % 2 ) sum += x/co[i].va * co[i].nu ; else sum-= x / co[i].va * co[i].nu ;
	}
	return sum ;
}

int main() {
	scanf("%d%d",&n,&k ) ;
	for( i=1 ; i<=n ; i++ ) scanf("%d",&a[i] ) ;
	Combine( 0 , 0 , 1 ) ;
	ll l = 1 , r = maxans ;
	while( l<=r ) {
		ll m = ( l+r ) / 2 ;
		ll p = P( m ) ;
		if( p>k ) r = m-1 ; 
		if( p<k ) l = m+1 ;
		if( p==k ) {
			if( P( m-1 )==k ) r = m-1 ; else l = m+1 ;
		}
	}
	printf("%lld",r ) ;
}
