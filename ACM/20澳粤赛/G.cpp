#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

int n,ans,k;
map<int,int> a;

int main()
{
	freopen("G.in","r",stdin);
	//freopen(".out","w",stdout);

    cin >> n;
    for (int i=0;i<n;i ++){
        int num;
        cin >> num;
        a[num] ++;
        if (ans<a[num]) {
            ans = a[num];
            k = num;
        }
    }
    cout << k << endl;
	return 0;
}
