#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 1000;
int a[MAXN],n,m;

int insort(int s[], int n)   	 //ֱ�Ӳ������� ��С���� 
{
    int i,j;
    for(i=2;i<=n;i++)   		 	//�����±��2��ʼ��s[0]�������ڣ�s[1]һ�������޿ɱ���
    {
        s[0]=s[i];  				//���������ֵ
        j=i-1;						//ȷ��Ҫ�Ƚ�Ԫ�ص����ұ�λ��
        while(s[0]<s[j])
        {
            s[j+1]=s[j];  			 //��������
            j--;   					 //���������һ��δ�Ƚϵ���
        }
        s[j+1]=s[0];  				 //��ȷ����λ�ò���s[i]
    }
    return 0;
}

void bubblesort(int a[],int n)				//ð������ �Ӵ�С 
{
	int buf;
    for (int i=0; i<n-1; ++i) 			//�Ƚ�n-1��
    {
        for (int j=1; j<=n-1-i; ++j)  	//ÿ�ֱȽ�n-1-i��,
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
            if(a[i]>a[j])    //���ǰһ�����Ⱥ�һ�������������м����tʵ����ֵ����
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
}

void print(int a[],int n)				//��ӡ������Ϣ 
{
	for (int i=1;i<=n;i ++)
		cout << a[i] << " ";
	cout << endl;
}

int half(int a[],int n,int num)			//���ֲ��� 
{
	int l=1,r=n,mid;					//���ұ߽� 
	while (l<=r)
	{
		mid = (l+r) >> 1;				//ȡ�м�λ�� 
		if (a[mid]<num) l = mid+1;
		else if (num<a[mid])r = mid-1;
		else break;
	}
	return (a[mid]==num)?mid:-1;		//�ж��Ƿ���������Ա��� 
}

int main()
{
	cout << "���������Բ��ұ������ݸ���:";
	cin >> n; 
	cout << "������������һϵ������:\n"; 
	for (int i=1;i<=n;i ++) cin >> a[i];
	insort(a,n);
	cout << "ֱ�Ӳ�����������";
	print(a,n);
	bubblesort(a,n);
	cout << "ð����������";
	print(a,n); 
	selectsort(a,n);
	cout << "ѡ����������";
	print(a,n); 
	cout << "��������Ҫ���ֲ��ҵ���:"; 
	cin >> m;
	cout << "���ֲ��ҵõ���λ�ã�"  << half(a,n,m);
	return 0;	
} 
