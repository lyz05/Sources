#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <list>
using namespace std;

list<int> q;
int T, n, m;

int main()
{
    freopen("L.in", "r", stdin);
    //freopen(".out","w",stdout);

    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            q.push_back(x);
        }
        cin >> m;
        for (int i = 1; i <= m; i++)
        {
            int op, y;
            cin >> op;
            if (op == 1 || op == 3)
                cin >> y;
            if (op == 1)
                q.push_front(y);
            if (op == 2)
                q.pop_front();
            if (op == 3)
                q.push_back(y);
            if (op == 4)
                q.pop_back();
        }
        cout << "Case #" << t << ":" << endl;
        int l, r;
        cin >> l >> r;
        for (int i = 1; i <= r && !q.empty(); i++)
        {
            if (l <= i && i <= r)
                cout << q.front() << " ";
            q.pop_front();
        }
        cout << endl;
    }

    return 0;
}
