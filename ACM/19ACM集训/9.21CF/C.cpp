#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6;
//beifugai
int in(int x,int y)
{
	if (x3<=x && x<=x4 && y3<=y && y<=y4)
		return 1;
	else if (x5<=x && x<=x6 && y5<=y && y<=y6)
		return 2;
	else 
		return 0;
}

bool judge1()
{
	return(in(x1,y1)&&in(x2,y2)&&in(x1,y2)&&(x2,y1));
}

bool judge2()
{
	{
		int minx,maxx;
		if (in(x1,y1)==in(x1,y2) && in(x2,y1)==in(x2,y2))
		{
			if (x4<x5) minx = x4,maxx = x5;
			if (x6<x3) minx = x6,maxx = x3;
			if (x1<=minx && maxx<=x2) return 0;
		}
	}
	{
		int miny,maxy;
		if (in(x1,y1)==in(x2,y1) && in(x1,y2)==in(x2,y2))
		{
			if (y6<y3) miny = y6,maxy = y3;
			if (y4<y5) miny = y4,maxy = y5;
			if (y1<=miny && maxy<=y2) return 0;
		}
	}
	return 1;
}

int main()
{
	freopen("C.in","r",stdin);
	//freopen(".out","w",stdout);
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	cin >> x5 >> y5 >> x6 >> y6;
	
	if (judge1() && judge2()) cout << "NO";
	else cout << "YES";
	
	return 0;
}
