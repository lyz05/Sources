#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
const int maxn = 1e5 + 10;
struct node {
    //char nm[20];
    string nm;
    int sc;
    int id;
}a[maxn];
int cmp(node a, node b) {
    if (a.sc == b.sc) {
        //return strcmp(a.nm, b.nm) < 0;
        return a.nm.compare(b.nm) < 0;
        //return a.nm.compare(b.nm) == -1 ? 1 : 0;
    }
    return a.sc > b.sc;
}
int main()
{
    //string str1 = "ssssine3gbc";
    //string str2 = "zajkebfguiajghvcutyvuiyfdcutyxcywsrutydxcktyjsrutxuiytetydxcuiysrutgyxcuyjdrutyxktgyjhxrtzxjrutyxtydcuitydxcyutofduityvcuioyfcuoycuityityxcjbegbz";
    //cout << str1.compare(str2) << endl;
    int n, g, k; int ans = 0;
    scanf("%d%d%d", &n, &g, &k);
    for (int i = 1; i <= n; i++) {
        cin >>a[i].nm >> a[i].sc;
        if (a[i].sc >= g) ans += 50;
        else if (a[i].sc >= 60) ans += 20;
    }
    sort(a + 1, a + 1 + n, cmp);
    a[0].sc = -1;
    for (int i = 1; i <= n+2; i++) {
        if (a[i].sc == a[i - 1].sc) a[i].id = a[i - 1].id;
        else a[i].id = i;
    }
    cout << ans << endl;
    for (int i = 1; a[i].id <= k; i++) {
        cout << a[i].id << " " << a[i].nm << " " << a[i].sc << endl;
    }

    return 0;
}

