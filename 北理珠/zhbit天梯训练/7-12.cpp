#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

vector<int> a;
int n,m;

int find(int x)
{
	for (int i=0;i<(int)a.size();i ++)
		if (a[i] == x) return i+1;
	return -1;
}

int main()
{
	freopen("7-12.in","r",stdin);
	cin >> n >> m;
	for (int i=1;i<=n;i ++)
	{
		int t;
		cin >> t;
		a.push_back(t);
	}
	make_heap(a.begin(),a.end(),greater<int>());
	for (int i=0;i<(int)a.size();i ++) cout << a[i] << " ";
	//cout << endl;
	for (int i=1;i<=m;i ++)
	{
		int x,y;
		string s;
		cin >> x;
		cin >> s;
		if (s == "and") {
			cin >> y;
			int u = find(x),v = find(y);
			if (u/2==v/2)
				cout << "T";
			else
				cout << "F";
			cin >>s>>s;
		} else
		{
			cin >> s;
			if (s == "a")
			{
				cin>>s>>s>>y;
				int u = find(x),v = find(y);
				if (a[u/2-1]==y) cout << "T";
				else cout << "F";
			}else
			{
				cin >> s;
				if (s=="root")
				{
					if (x == a[0]) cout << "T";
					else cout << "F";
				}else
				{
					cin >> s >> y;
					int u = find(x),v = find(y);
					if (a[v/2-1]==x) cout << "T";
					else cout << "F";
				}
			}
		}
		cout << endl;
	}
	return 0;
}
 
