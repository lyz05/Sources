#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    //freopen("1005.in","r",stdin);
    float F;
    while (cin >> F)
    {
        float c = 5*(F-32)/9;
        printf("c=%.2f",c);
    }
}

