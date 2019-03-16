#include<cstdio>
#include<iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW -1 
#define MAXSIZE 100
using namespace std;

typedef int Status;
typedef int ElemType ;

class SqList{
	public:
		ElemType *elem;
		int length;
		SqList()
		{
			InitList();
		}
		Status InitList()
		{
			elem = new ElemType[MAXSIZE];
			if (!elem) return OVERFLOW;
			length = 0;
			return OK;
		}
		Status GetElem(int i,ElemType &e)
		{
			if (i<1 || i>length) return ERROR;
			e = elem[i];
			return OK;
		}
		int Locate(ElemType e)
		{
			for (int i=0;i < length;i ++)
				if (elem[i] == e) return i+1;
			return 0;
		} 
		Status ListInsert(int i,ElemType e)
		{
			if (i<1 || i>length) return ERROR;
			if (length == MAXSIZE) return ERROR;
			for (int j=length-1;j>=i-1;j --)
				elem[j+1] = elem[j];
			elem[i-1] = e;
			length ++;
			return OK; 
		}
		Status ListDelete(int i)
		{
			if (i<1 || i>length) return ERROR;
			for (int j=i;j<=length-1;j ++)
			{
				elem[j-1] = elem[j];
			}
			length --;
			return OK;
		}
};

ostream& operator << (ostream &os,const SqList &L)
{
	cout << "length:" << L.length << endl;
	cout << "elem:";
	for (int i=0;i<L.length;i ++) cout << L.elem[i] << " ";
	cout << endl;
	return os;
}

istream& operator >> (istream &is,SqList &L)
{
	ElemType e;
	cout << "Input a elem:";
	cin >> e;
	L.length ++;
	L.elem[L.length-1] = e;
	return is;
}

int main()
{
	SqList L;
	int n;
	ElemType e;
	
	L.InitList();
	cout << "Please input 10 elem" << endl;
	for (int i=1;i<=10;i ++)		//连续输入10个elem 
		cin >> L;
	cout << L << endl;
	
	cout << "Input a position to delete elem:";
	cin >> n;
	L.ListDelete(n);
	cout << L << endl;
	
	
	cout << "Input a position to Insert elem:";
	cin >> n;
	cout << "Input this elem:";
	cin >> e;
	L.ListInsert(n,e);
	cout << L << endl;
	
	cout << "Input a elem to find:";
	cin >> e;
	cout << "The position is:";
	if (L.Locate(e)) cout << L.Locate(e) << endl;
	else cout << "Not found" << endl;
	return 0;
} 
