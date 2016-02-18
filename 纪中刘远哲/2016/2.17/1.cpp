#include <iostream>
#include <cstdio>

#define MAXN 1000000  
using namespace std;
typedef long long LL;

int h[MAXN+5];      //������ĸ߶�  
int n;              //���������Ŀ  
  
int mq[MAXN+5];     //�������У�����Ԫ��Ϊ������߶ȵ��±�  
int L[MAXN+5];   //L[i]���ڵ�i����������࣬�������ĸ߶�С�Ľ���������  
int R[MAXN+5];  //R[i]���ڵ�i���������Ҳ࣬�������ĸ߶�С�Ľ���������  
  
void CalcLeft(void)  
{  
    mq[0] = 0;  
    int front = 0, rear = 1;  
      
    int i;  
    for (i = 1; i <= n; i++)  
    {  
        while (front < rear && h[i] <= h[mq[rear-1]])  
        {  
            rear--;  
        }  
        L[i] = i - mq[rear-1] - 1;  
        mq[rear++] = i;  
    }  
}  
  
void CalcRight(void)  
{  
    mq[0] = n + 1;  
    int front = 0, rear = 1;  
  
    int i;  
    for (i = n; i >= 1; i--)  
    {  
        while (front < rear && h[i] <= h[mq[rear-1]])  
        {  
            rear--;  
        }  
        R[i] = mq[rear-1] - i - 1;  
        mq[rear++] = i;  
    }  
}  
  
LL MaxRectArea(void)  
{  
    LL maxArea = -1;  
    int i;  
    for (i = 1; i <= n; i++)  
    {  
        LL area = (LL)(L[i] + R[i] + 1) * h[i];  
        if (area > maxArea)  
        {  
            maxArea = area;  
        }  
    }  
    return maxArea;  
}  
  
int main()  
{  
	//freopen("2206.in","r",stdin);
    while (cin >> n)  
    {  
        int i;  
        for (i = 1; i <= n; i++)  
        {  
            cin >> h[i];  
        }  
  
        h[0] = h[n+1] = -1;  
        CalcLeft();  
        CalcRight();  
  /*
        for (i = 1; i <= n; i++)  
        {  
            cout << L[i] << ' ';

        }  
        cout << endl;  
        for (i = 1; i <= n; i++)  
        {  
            cout << R[i] << ' ';  
        }  
        cout << endl;  
  */
        cout << MaxRectArea() << endl;  
    }  
    return 0;  
}  
  
/* 
6 
5 8 4 4 8 4 
6 
9 5 8 2 8 8 
6 
9 6 8 2 8 8 
*/  
