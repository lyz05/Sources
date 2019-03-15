#include<cstdio>
#define OK 1
#define ERROR 0
#define OVERFLOW -1 
#define MAXSIZE
using namespace std;

typedef Status int;
typedef ElemType int;

class SqList{
	private:
		ElemType *elem;
		int length;
	public:
		Status InitList(Sqlist &l)
		{
			elem = new ElemType[MAXSIZE];
			if (!elem) return OVERFLOW;
			L.length = 0;
			return OK;
		}
		Status GetElem(Sqlist L,int i,ElemType &e);
		{
			if (i<0 || i>=len) return ERROR;
			e = elem[i];
			return OK;
		}
		Status Locate
};

int main()
{

	return 0;
} 
