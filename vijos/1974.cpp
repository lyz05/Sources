//1	2	2	3	3	3	4	4	4	4
//1	3	5	8	11	14	18	22	26	30
#include <iostream>
using namespace std;
const int N=150;
int a[(N*(N+1))/2+5];

int main(){
	int n,tot = 0,sum = 0;
	cin >> n;
	for (int i = 1;i <= N; i ++) 
		for (int j=1;j <= i;j ++)
			a[++ tot] = i;
	for (int i=1;i<=n;i ++) sum += a[i];
	cout << sum; 
}
