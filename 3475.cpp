#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int C = 50000,N = 1000000 - C;
int n = 0,tail = 1 ,head = 1,c,t;
int s[N],q[C];
bool empty = 1,dir = 1;

int next(int x)
{
	if (dir) return (x % c) + 1;
	else return (x+c-2) % c + 1;
}
int front(int x)
{
	if (dir) return (x + c - 2) % c + 1;
	else return (x % c) + 1;
}

void push()
{
	int num,ne;
	scanf("%d",&num);
	ne = next(head);
	if (ne == tail)
	{
		n ++;
		s[n] = q[tail];
		tail = next(tail);
	}
	if (empty) empty = 0;
	else head = ne;
	q[head] = num;
}

void pop()
{
	if (empty) 
	{	
		puts("Error: the stack is empty!");
		return;
	}
	printf("%d\n",q[head]);
	if (tail == head) empty = 1;
	else 
	{
		head = front(head);
		if (n > 0)
		{
			tail = front (tail);
			q[tail] = s[n];
			n --;
		}
	}
}

void reserse()
{
	int tmp;
	if (next(head) == tail)
	{
		dir = ! dir;
		tmp = head;
		head = tail;
		tail = tmp;
	} else printf("Error: less than %d elements in the stack!\n", c);
}

int main()
{
	freopen("3475.in","r",stdin);
	
	scanf("%d",&c);
	do
	{
		scanf("%d",&t);
		if (t==1) push();
		if (t==2) pop();
		if (t==3) reserse();
	} while (t!=0);
	
	return 0;
}

