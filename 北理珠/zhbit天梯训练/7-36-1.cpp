#include <iostream> 
#include <cstdlib> 
#include <stdio.h> 
#include <algorithm> 
#include <math.h> 
#include <cstring>
using namespace std;
int main(){ 
	int a,b;
	int x, y, z;
	int a1=0,b1=0;
	cin>>a>>b>>x>>y>>z;
	if(x==0) a1++;
	else b1++;
	if(y==0) a1++;
	else b1++;
	if(z==0) a1++;
	else b1++;
	if(a1==3)
	printf("The winner is a: %d + %d\n",a,a1);
	else if(a1==0)
	printf("The winner is b: %d + %d\n",b,b1);
	else if(a>b)
	printf("The winner is a: %d + %d\n",a,a1);
	else
	printf("The winner is b: %d + %d\n",b,b1); 
	return 0;
}

