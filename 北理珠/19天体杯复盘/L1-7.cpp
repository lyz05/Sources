#include <bits/stdc++.h>
using namespace std;

int T,sex,height,weight;

int main()
{
	cin >> T;
	while (T --)
	{
		cin >> sex >> height >> weight;
		if (sex==0)
		{
			if (height==129) cout << "wan mei!";
			if (height>129) cout << "ni li hai!";
			if (height<129) cout << "duo chi yu!";
			cout << " ";
			if (weight==25) cout << "wan mei!";
			if (weight>25) cout << "shao chi rou!";
			if (weight<25) cout << "duo chi rou!";
			cout << endl;
		} else
		{
			if (height==130) cout << "wan mei!";
			if (height>130) cout << "ni li hai!";
			if (height<130) cout << "duo chi yu!";
			cout << " ";
			if (weight==27) cout << "wan mei!";
			if (weight>27) cout << "shao chi rou!";
			if (weight<27) cout << "duo chi rou!";
			cout << endl;
		}
	}
	return 0;
}
