#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 1000;
int a[MAXN],n,m;

int insort(int s[], int n)   	 //直接插入排序 从小到大 
{
    int i,j;
    for(i=2;i<=n;i++)   		 	//数组下标从2开始，s[0]做监视哨，s[1]一个数据无可比性
    {
        s[0]=s[i];  				//给监视哨陚值
        j=i-1;						//确定要比较元素的最右边位黄
        while(s[0]<s[j])
        {
            s[j+1]=s[j];  			 //数据右移
            j--;   					 //产移向左边一个未比较的数
        }
        s[j+1]=s[0];  				 //在确定的位置插入s[i]
    }
    return 0;
}

void bubblesort(int a[],int n)				//冒泡排序 从大到小 
{
	int buf;
    for (int i=0; i<n-1; ++i) 			//比较n-1轮
    {
        for (int j=1; j<=n-1-i; ++j)  	//每轮比较n-1-i次,
        {
            if (a[j] < a[j+1])
            {
                buf = a[j];
                a[j] = a[j+1];
                a[j+1] = buf;
            }
        }
    }
}

void selectsort(int a[],int n)
{
	int t;
    for(int i=1;i<=n-1;i++)
        for (int j=i+1;j<=n;j++)
            if(a[i]>a[j])    //如果前一个数比后一个数大，则利用中间变量t实现两值互换
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
}

void print(int a[],int n)				//打印数组信息 
{
	for (int i=1;i<=n;i ++)
		cout << a[i] << " ";
	cout << endl;
}

int half(int a[],int n,int num)			//二分查找 
{
	int l=1,r=n,mid;					//左右边界 
	while (l<=r)
	{
		mid = (l+r) >> 1;				//取中间位置 
		if (a[mid]<num) l = mid+1;
		else if (num<a[mid])r = mid-1;
		else break;
	}
	return (a[mid]==num)?mid:-1;		//判断是否存在于线性表中 
}

int main()
{
	cout << "请输入线性查找表中数据个数:";
	cin >> n; 
	cout << "请依次输入这一系列整数:\n"; 
	for (int i=1;i<=n;i ++) cin >> a[i];
	insort(a,n);
	cout << "直接插入排序结果：";
	print(a,n);
	bubblesort(a,n);
	cout << "冒泡排序结果：";
	print(a,n); 
	selectsort(a,n);
	cout << "选择排序结果：";
	print(a,n); 
	cout << "请输入需要二分查找的数:"; 
	cin >> m;
	cout << "二分查找得到的位置："  << half(a,n,m);
	return 0;	
} 
