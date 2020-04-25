#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int k;
char Time[12];

int calc(int Time)
{
    int ret = 0;
    while (Time)
    {
        ret += Time % 10;
        Time /= 10;
    }
    if (ret < 10)
        return ret;
    else
        return calc(ret);
}

//是否闰年
int IsLeapYear(int year)
{
    return ((year % 4 == 0) && (year % 100 != 0) || year % 400 == 0);
}

int days(int year, int month)
{
    int num;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        num = 31;
        break;
    case 2:
        num = 28 + IsLeapYear(year);
        break;
    default:
        num = 30;
    }
    return num;
}

bool vaild(int Time)
{
    int year = Time / 10000;
    int month = Time / 100 % 100;
    int day = Time % 100;
    if (year <= 2020 && year >= 1900 && month <= 12 && month >= 1 && day >= 1 && day <= days(year, month))
        return 1;
    else
        return 0;
}

char s[256];

void transfer(char s[], int k)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
            s[i] = '#';
        if (s[i] <= 'z' && s[i] >= 'a')
            s[i] = ((s[i] - 'a' + k) % 26) + 'a';
        if (s[i] <= 'Z' && s[i] >= 'A')
            s[i] = ((s[i] - 'A' + k) % 26) + 'A';
    }
}

bool valids(char s[])
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!(s[i] == ' ' || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')))
            return 0;
    }
    return 1;
}

int main()
{
    freopen("A.in", "r", stdin);
    //freopen(".out","w",stdout);
    while (cin >> Time)
    {
        getchar();
        cin.getline(s, 256);
        bool flag = 0;
        int date = 0;
        for (int i = 0; i < strlen(Time); i++)
        {
            if (Time[i] < '0' || Time[i] > '9')
            {
                flag = 1;
                break;
            }
            date *= 10;
            date += Time[i]-'0';
        }
        
        if (flag || !vaild(date) || !valids(s))
        {
            cout << "none" << endl;
            continue;
        }
        k = calc(date);
        transfer(s, k);
        cout << s << endl;
    }
    return 0;
}
