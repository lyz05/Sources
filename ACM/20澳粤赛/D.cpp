#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

vector<int> ans[3];
int n;
int main()
{
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        ans[i % 3].push_back(num);
    }
    for (int i = 0; i < 3; i++)
    {
        if (!ans[i].empty())
        {
            for (int j = 0; j < ans[i].size() - 1; j++)
                cout << ans[i][j] << " ";
            cout << ans[i][ans[i].size() - 1];
        }

        cout << endl;
    }
    return 0;
}
