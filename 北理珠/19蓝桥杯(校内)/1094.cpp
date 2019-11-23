#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    freopen("1094.in","r",stdin);
    int n;
    scanf("%d\n",&n);
    for (int i=1;i<=n;i ++)
    {
        string s;
        getline(cin,s);
        cout << s << endl << endl;
    }
    string s;
    while (cin >> s)
    {
        cout << s << endl << endl;
    }
    return 0;
}
