#include <ctime>
#include <iostream>
#include <windows.h>
using namespace std;

int random(int x,int y)			//在int范围下生成区间为[x,y]的随机整数
{
	int ret = rand()*rand();
	return ret%(y-x+1)+x;
}

int main()
{
	srand(time(0));
	int n = random(2,100), m = random(2,100);
	cout << n << " "<< m << endl;
	cout << random(1,n) << " "<< random(1,m)<< endl;
	
	return 0;
}

/*
int main()
{
	srand(time(NULL));
	int n = random(1,1000);
	cout << n << endl;
	cout << int(1e9+7) << " ";
	for (int i=2;i<=n;i ++)
		cout << random(-1000000,1000000) << " ";
	return 0;
}

*/
/*
int main()
{
	srand(time(NULL));
	int n = random(1,100);
	for (int i=1;i<=n;i ++)
		if (random(0,1))
			cout << char('a'+random(0,25));
		else
			cout << char('A'+random(0,25));
	return 0;
}
*/
