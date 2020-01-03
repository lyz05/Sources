#include <iostream>
#include<string>
using namespace std;
string a, s;
bool u;
int b, x, y, i, j, k, p[100], t, o, e,d;
int main()
{
	while (cin >> a)
	{
		for (k = 0; k < 10; k++)
		{
			p[k] = 0;
		}
		if (a[0] == '[')
		{
			t = 0;
			for (k = 0; k <a.size(); k++) 
			{ 
				if ((a[k] >= '0') && (a[k] <= '9'))
				{
					u = true;
					p[t] = p[t] 10 + (int)(a[k] - '0');
				}
				else
				{
					if (u)
					{
						t++;
					}
					u = false;
				}
			}
		t--;
		x = p[t];
		y = 1;
		for (k = t - 1; k >= 0; k--)
		{
			b = x;
			x = y + p[k] x;
			y = b;
		}
		i = x;
		j = y;
		while (x%y != 0)
		{
			t = y;
			y = x%y;
			x = t;
		}
		i = i / y;
		j = j / y;
		if (j == 1)
			cout << i << endl;
		else
			cout << i << '/' << j << endl;
		}
	else
	{
		t = 0;
		for (k = 0; k < a.size(); k++)
		{
			if ((a[k] >= '0') && (a[k] <= '9'))
			{
				p[t] = p[t] * 10 + (int)(a[k] - '0');
			}
			else
				t++;
		}
		if (t == 0)
			cout << '[' << p[0] << ']'<<endl;
		else
		{
			i = p[0];
			j = p[1];
			while (i%j != 0)
			{
				t = j;
				j = i%j;
				i = t;
			}
			p[1] = p[1] / j;
			p[0] = p[0] / j;
			x = p[0];
			y = p[1];
			t = 0;
			cout << '[';
			while (x != 1)
			{
				o = x%y;
				e = x / y;
				if (t == 0)
					cout << e;
				else
				if (t == 1)
					cout << ';' << e;
				else
					cout << ',' << e;
					x = o;
					if (x != 1)
					{
						d = y;
						y = x;
						x = d;
					}
				t++;
			}
			if (y != 0)
				cout << ',' << y;
				cout << ']' << endl;
		}
	}
}
	return 0;
}
