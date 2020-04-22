#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 205;
char s[N];

int main()
{
	//freopen("5.in","r",stdin);
	//freopen(".out","w",stdout);

    cin >> s;
    for (int i=0;i<(int)strlen(s);i ++) 
        s[i] = (s[i]-'a'+3)%26+'a';
    cout << s;
	return 0;
}
