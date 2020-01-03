#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

bool exist[100];                    //检查出现的字符个数 
int n,num[100],n2;                    //n不解释，num：每个字符的值，n2进制 
string ch[13][13];                    //表格 

void init()
{
    n2 = 0;
    memset(num,0,sizeof(num));
    scanf("%d",&n);
    for (char i = 'A'; i <= 'Z'; ++ i)
        exist[(int)i] = false;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j<= n; ++ j)
        {
            cin >> ch[i][j];
            if (!exist[(int)ch[i][j][0]])
            {
                exist[(int)ch[i][j][0]] = true;
                ++ n2;
            }
        }
    -- n2;                //减去那个加号……
}

void try_work()
{
    bool ten;
    ten = false;
    for (int i = 2; i <= n; ++ i)
    {
        int temp;
        temp = 0;
        for (int j = 2; j <= n; ++ j)
        {
            if (ch[i][j].length() == 2)
            {
                if (num[(int)ch[i][j][0]] != 0 && num[(int)ch[i][j][0]] != 1)
                {
                    cout<<num[(int)ch[i][1][0]];
                    cout<<"Wrong!";
                    exit(0);
                }
                else
                {
                    ten = true;
                    num[(int)ch[i][j][0]] = 1;
                }
                ++ temp;
            }
        }
        if (num[(int)ch[i][1][0]] == 0)
            num[(int)ch[i][1][0]] = temp;
        else
            if (!ten)
            {
                cout<<"Wrong!";
                exit(0);
            }
    }
}

void judge()
{
    for (int i = 2; i <= n; ++ i)
    {
        int a;
        a = num[(int)ch[i][1][0]];
        for (int j = 2; j <= n; ++ j)
        {
            int b,c;
            b = num[(int)ch[1][j][0]];
            if (ch[i][j].length() == 1)
            {
                c = num[(int)ch[i][j][0]];

            }
            if (ch[i][j].length() == 2)
            {
                c = num[(int)ch[i][j][1]] + n2 * num[(int)ch[i][j][0]];
            }
            if (a + b != c)
            {
                cout<<"Wrong!";
                exit(0);
            }
        }
    }
}

int main()
{
	freopen("1596.in","r",stdin);
    init();
    try_work();
    judge();
    for (int i = 2; i <= n; ++ i)
        cout << ch[1][i] << "=" << num[(int)ch[1][i][0]] << " ";
    cout << endl << n2;
    return 0;
}
