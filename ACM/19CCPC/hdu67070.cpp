//
// Created by congcong on 2020/9/17.
//

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stack>
#include <map>


using namespace std;

const int N = 1e5 + 7;
stack<int> s;
map<int,bool> Map;
int n, m, a[N], ans[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++) {
        int num;
        cin >> num;
        s.push(num);
    }
    for (int i = 1; i <= m; i++) {
        int now = s.top();
        s.pop();
        if (!Map[now]) ans[++ans[0]] = now;
        Map[now] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!Map[a[i]]) ans[++ans[0]] = a[i];
    }
    for (int i = 1; i <= ans[0]; i++)
        printf("%d ", ans[i]);

    return 0;
}