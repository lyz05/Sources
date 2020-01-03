#include <cstdio>

void swap(int &x,int &y)
{
	x=x^y;
	y=y^x;
	x=x^y;
}

int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	swap(x,y);
	printf("%d %d\n",x,y);
	return 0;
}
