#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map> 
using namespace std;

map<string,int> m;
int n;

void insert(int x)
{
    tot ++;
    h[tot].x = x;
    h[tot].next = Index;
    Index = tot;
}

void add(int k,int x)
{
    tot ++;
    h[tot].x = x;
    int j = h[k].next;
    h[k].next = tot;
    h[tot].next = j;
}

void remove(int k)
{
    
}

int main()
{
	cin >> n;
	while (n --)
	{
		string s;
        int x,k;
		cin >> s;
		if (s=="I") 
		{
            cin >> k >> x;
			add(k,x);
		}
		if (s=="H") 
        {
            cin >> x;
            insert(x);
        }
        if (s=="D")
        {
            cin >> k;
            remove(k);
        }
	}
    output();
	return 0;
} 
