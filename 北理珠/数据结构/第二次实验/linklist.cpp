#include <bits/stdc++.h>
#define OK 1
#define ERROR 0
using namespace std; 
typedef int ElemType;
typedef int Status;

struct LNode
{
	ElemType data;
	LNode *next;
};

class LinkList
{
	public:
	LNode *L;
	
	Status InitList()
	{
		L = new LNode;
		L -> next = NULL;
		L -> data = -1;
		return OK; 
	}
	Status GetElem(int i,ElemType &e)
	{
		LNode *p = L->next;
		int j = 1;
		while (p && j<i)
		{
			p = p->next;
			j ++;
		}
		if (!p || j>i) return ERROR;
		e = p->data;
		return OK;
	}
	int LocateElem(ElemType e)
	{
		int i;
		LNode *p = L -> next;
		for (i=1;p && p->data!=e;p = p->next,i ++);
		return i;
	}
	Status ListInsert(int i, ElemType e)
	{
		LNode *p = L,*s;
		int j = 0;
		while (p && (j<i-1))
		{
			p = p->next;
			j ++;
		}
		if (!p || j>i-1) return ERROR;
		s = new LNode;
		s->data = e;
		s->next = p->next;
		p->next = s;
		return OK;
	}
	Status ListDelete(int i)
	{
		LNode *p,*q;
		p = L;
		int j = 0;
		while ((p->next) && (j<i-1))
		{
			p = p->next;
			j ++;
		}
		if (!(p->next) || (j>i-1)) return ERROR;
		q = p->next;
		p->next = q->next;
		delete q;
		return OK;
	} 
	Status Converse()
	{
		LNode *p,*q;
		p = L->next;
		L->next = NULL;				//断开头指针 
		while (p)
		{
			q = p;
			p = p->next;
			q->next = L->next;		//反转指针 
			L->next = q;			//头节点指向当前最后一个元素 
		}
		return OK;
	}
	Status OrderInsert(ElemType e) 	//有序递增链表 
	{
		LNode *p = L->next;
		int tot = 1;
		while (p)
		{
			if (p->data >= e) break; //查找位置并插入 
			p = p->next;
			tot ++;
		}
		return ListInsert(tot,e);
	}
	int GetLen()
	{
		int n;
		LNode *p = L->next;
		for (n=0;p!=NULL;p = p->next,n ++);
		return n;
	} 
};

ostream& operator << (ostream &os,LinkList &L)	//输出链表的所有元素 
{
	cout << "elem:";
	for (LNode *p = (L.L)->next;p!=NULL;p = p->next) cout << p->data << " ";
	cout << endl << "length:" << L.GetLen() << endl;
	return os;
}

istream& operator >> (istream &is,LinkList &L) 			//后插法单个结点 
{
	ElemType e;
	cout << "Input a elem:";
	cin >> e;
	LNode *p = L.L,*q = new LNode;
	q->data = e;
	q->next = NULL;
	while (p->next!=NULL) p = p->next;
	p->next = q;
	return is;
}



int main()
{
	int n;
	ElemType e;
	LinkList L;
	L.InitList();
	
	cout << "Please input the length of LinkList:";
	cin >> n;
	for (int i=1;i<=n;i ++) cin >> L; 
	cout << L << endl;
	
	cout << "Please input the elem to Insert the Ordered list:";
	cin >> e;
	L.OrderInsert(e);
	cout << L << endl;
	
	cout << "Please input the number of LinkList to get elem:";
	cin >> n;
	L.GetElem(n,e);
	cout << "elem:" << e << endl << endl;
	
	cout << "Please input the elem of LinkList to get position:";
	cin >> e;
	cout << "Number:" << L.LocateElem(e) << endl << endl;
	
	cout << "Please input the Number of LinkList to Insert:";
	cin >> n;
	cout << "Please input the elem:";
	cin >> e;
	L.ListInsert(n,e);
	cout << L << endl;
	
	cout << "Please input the Number of LinkList to Delete:";
	cin >> n;
	L.ListDelete(n);
	cout << L << endl;
	
	cout << "Converse the LinkList" << endl;
	L.Converse();
	cout << L << endl;
	return 0;
}
