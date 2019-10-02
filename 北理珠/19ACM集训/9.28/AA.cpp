#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;
const int Max = 4097 ;
int n , weight[Max] , sum ;
int package[Max] , top ;
int book[Max] ;
 
int DFS( int stick , int res , int i ){
	if( res == 0 && stick == n )    //  package[i] ʱǡ��ȫ�����꣬���� 1 
		return 1 ;
	if( res == 0 )                  // �������һ�� package[i] , ���ǻ��й��ӻ��ù������ü������
		res = package[i] ;
	for( int j = n ; j >= 1 ; --j )
		if( res >= weight[j] && book[j] == 0 ){ 
			if( j != n && book[j+1] == 0 && weight[j] == weight[j+1] )   // ��ͬ��С�Ĺ��Ӳ����ظ�����
				continue ;
			book[j] = 1 ;
			if( DFS( stick+1 , res-weight[j] , i ) )
				return 1 ;
			else{
				book[j] = 0 ; // ���ݣ���������޽�
				if( res == package[i] || weight[j] == res )  // �������ѡ���ò�����ϣ��ղ�ѡ�ľ���ʣ�µģ�ȴҲ�޽�
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
		sort( weight+1 , weight+n+1 ) ;   // ��С�Ŀ����и������
		if( weight[n] > sum >> 1 ){       // ������Ĺ��ӱ��ܺ͵�һ�㻹Ҫ�󣬾�ֻ��һ����
			cout << sum << endl ;
			continue ;
		}
		top = 0 ;
		for( int i = weight[n] ; i <= sum ; ++i )
			if( sum % i == 0 )
				package[++top] = i ;        // package ���鱣�����ӣ���ΪҪǡ����ϣ�n �϶��� i �ı���
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
