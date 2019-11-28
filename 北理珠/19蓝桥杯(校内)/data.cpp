#include <ctime>
#include <iostream>
#include <windows.h>
using namespace std;

int random(int x,int y)
{
	int ret = rand()*rand();
	return ret%(y-x+1)+x;
}

int main()
{
	srand(time(NULL));
	while(1)
	{
		cout << random(80,100) << endl;
		Sleep(100);
	}
	return 0;
} 
