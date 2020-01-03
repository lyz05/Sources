#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;
const int Max = 4097 ;
int n , weight[Max] , sum ;
int package[Max] , top ;
int book[Max] ;
 
int DFS( int stick , int res , int i ){
	if( res == 0 && stick == n )    //  package[i] 时恰好全部用完，返回 1 
		return 1 ;
	if( res == 0 )                  // 刚组合了一个 package[i] , 但是还有棍子还用过，重置继续组合
		res = package[i] ;
	for( int j = n ; j >= 1 ; --j )
		if( res >= weight[j] && book[j] == 0 ){ 
			if( j != n && book[j+1] == 0 && weight[j] == weight[j+1] )   // 相同大小的棍子不用重复搜索
				continue ;
			book[j] = 1 ;
			if( DFS( stick+1 , res-weight[j] , i ) )
				return 1 ;
			else{
				book[j] = 0 ; // 回溯，这根棍子无解
				if( res == package[i] || weight[j] == res )  // 如果根本选，得不到组合；刚才选的就是剩下的，却也无解
					return 0 ;
			}
		}
	return 0 ;
}
 
int main(){
	freopen("A.in","r",stdin);
	while( cin >> n && n ){
		sum = 0 ;
		for( int i = 1 ; i <= n ; ++i ){
			cin >> weight[i] ;
			sum += weight[i] ;
		}
		sort( weight+1 , weight+n+1 ) ;   // 让小的可以有更多组合
		if( weight[n] > sum >> 1 ){       // 如果最大的棍子比总和的一般还要大，就只有一根了
			cout << sum << endl ;
			continue ;
		}
		top = 0 ;
		for( int i = weight[n] ; i <= sum ; ++i )
			if( sum % i == 0 )
				package[++top] = i ;        // package 数组保存因子，因为要恰好组合，n 肯定是 i 的倍数
		for( int i = 1 ; i <= top ; ++i ){
			memset( book , 0 , sizeof( book ) ) ;
			if( DFS( 0 , package[i] , i ) ){
		    	cout << package[i] << endl ;
		    	break ;
		    }
		}
	}
	return 0 ;
}
