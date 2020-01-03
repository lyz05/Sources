#include <iostream>
#include <cstring>
using namespace std;

const int M = 1107;
int n;
char s[M];

int judge(char ch)
{
	if (ch>='A' && ch<='Z') return 1;
	if (ch>='a' && ch<='z') return 2;
	if (ch>='0' && ch<='9') return 3;
	if (ch==' ') return 4;
	return -1;
}

bool independ(char s[],char st[],int &k)
{
	int L = k,R = k+strlen(st)-1;
	if (L<0 || R>=strlen(s)) return 0;
	for (int i=0;i<(int)strlen(st);i ++)
		if (s[k+i] != st[i]) return 0;
	bool flag;
	if (L==0 || judge(s[L-1])==4 || judge(s[L-1])==-1) flag = 1; else flag = 0;
	if (R==strlen(s)-1 || judge(s[R+1])==4 || judge(s[R+1])==-1) flag &= 1; else flag = 0;
	if (flag) k=R;
	return flag;
	
}

void work(char s[])
{
	cout << "AI: "; 
	int len = strlen(s),L,R;
	for (int i=0;i<len;i ++)
		if (s[i]!=' ') 
		{
			L = i;
			break;
		}
	for (int i=len-1;i>=0;i ++)
		if (s[i]!=' ')
		{
			R = i;
			break;
		}
	char news[M]="";
	len = 0;
	for (int i=L;i<=R;i ++)
	{
		if (judge(s[i])==1 && s[i]!='I') s[i] = s[i]-'A'+'a';
		if (s[i]=='?') s[i] = '!';
		if (judge(s[i])==4 && len!=0 && news[len-1]==' ') continue;
		if (len!=0 && news[len-1]==' ' && judge(s[i])==-1) len --;
		news[len ++] = s[i];
	}
	for (int i=0;i<(int)strlen(news);i ++)
	{
		if (independ(news,"can you",i)) cout << "I can";
		else if (independ(news,"could you",i)) cout << "I could";
		else if (independ(news,"I",i) || independ(news,"me",i)) cout << "you";
		else cout << news[i];
	}
	cout << endl;
	//cout << news <<endl;
}

int main()
{
	freopen("L1-8.in","r",stdin);
	scanf("%d\n",&n); 
	while (n --)
	{
		cin.getline(s,sizeof s);
		cout << s << endl;
		work(s);
	}
	return 0;	
} 
