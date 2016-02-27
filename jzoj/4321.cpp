#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <cctype>
using namespace std;

int len;
char s[1000005];

void calc(stack<int> &num,char opt)
{
	int x,y;
	
	x = num.top();num.pop();
	if (opt=='!') 
	{
		num.push(x?0:1);
		return;
	}
	y = num.top(),num.pop();
	if (opt=='|') num.push(x|y);
	if (opt=='&') num.push(x&y);
}

int level(char ch)
{
	if (ch=='(') return 0;
	if (ch=='|') return 1;
	if (ch=='&') return 2;
	if (ch=='!') return 3;
	return -1;
}

bool work(char *s,int len)
{
	stack <int> num;
	stack <char> opt;
	for (int i=1;i<=len;i ++)
	{
		if (isalpha(s[i]))
		{
			num.push(s[i]=='V');
		}else 
		{
			if (s[i]==')')
			{
				while (opt.top()!='(')
				{
					calc(num,opt.top());
					opt.pop();
				}
				opt.pop();
			} else
			if (s[i]!='(')
			{
				while (!opt.empty() && level(opt.top())>level(s[i]))
				{
					calc(num,opt.top());
					opt.pop();
				}
			}
			if (s[i]!=')') opt.push(s[i]);
		}
	}
	//while (!opt.empty()) printf("%c",opt.top()),opt.pop();
	//while (!num.empty()) printf("%d",num.top()),num.pop();
	while (!opt.empty()) 
	{
		//printf("%d %d",num.size(),opt.size());
		calc(num,opt.top());
		opt.pop();
		//printf("%d %d",num.size(),opt.size());
	}
	return num.top();
}

int main()
{
	freopen("boolean.in","r",stdin);
	//freopen("boolean.out","w",stdout);

	char ch='\n';
	while (scanf("%c",&ch)!=EOF)
	{
		if (isblank(ch) || ch=='\n') continue;
		s[++ len] = ch;
	}
	s[len+1] = '\0';
	printf("%s\n",work(s,len)?"V":"F");
	return 0;
}
