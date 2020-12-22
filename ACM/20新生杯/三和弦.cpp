#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 7;
const char name[N][10]={"la","si","do","re","mi","fa","sol"};
int a[N],n;

int main()
{
	while (cin >> n) {
		memset(a,0,sizeof a);
		for (int i=1;i<=n;i ++)
		{
			char ch;
			cin >> ch;
			a[ch-'A'] ++;
		}
		bool flag = 0;
		for (int i=0;i<N;i ++)
		{
			int j = (i+2)%N,k = (i+2+2)%N;
			if (a[i] && a[j] && a[k] && a[i]+a[j]+a[k]==n)
			{
				flag = 1;
				cout << name[i] << " " << name[j] << " " << name[k] << endl;
				break;
			}
		}
		if (!flag) {
			cout << "null" << endl;
		}
	}
	return 0;
 } 
