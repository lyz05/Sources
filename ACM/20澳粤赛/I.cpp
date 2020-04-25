#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 105;
struct Node
{
    int score[3];
    int sum, id;
} a[N];

int n;

bool cmp(Node x, Node y)
{
    if (x.sum != y.sum)
        return x.sum > y.sum;
    else if (x.score[0] != y.score[0])
        return x.score[0] > y.score[0];
    else
        return x.id < y.id;
}

int main()
{
    freopen("I.in", "r", stdin);
    //freopen(".out","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].score[0] >> a[i].score[1] >> a[i].score[2];
        for (int j = 0; j < 3; j++)
            a[i].sum += a[i].score[j];
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= 5; i++)
        cout << a[i].id << " " << a[i].score[0] << " " << a[i].score[1] << " " << a[i].score[2] << endl;
    return 0;
}
