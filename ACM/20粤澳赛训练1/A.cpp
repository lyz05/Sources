#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	freopen("A.in","r",stdin);
	//freopen(".out","w",stdout);

    int T;
    cin >> T;
    while (T --) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int x,y,x1,y1,x2,y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        x += b-a;
        y += d-c;
        if ((x1==x2 && (a || b) || (y1==y2 && (c ||d)))) {
            cout << "NO" << endl;
            continue;
        }
        if (x1<=x && x<=x2 && y1<=y && y<=y2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

	return 0;
}
