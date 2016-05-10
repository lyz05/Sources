#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define ull long long
 
const int MAXN=1000000;
const int mod=1000000007;
 
char str[MAXN+10];
 
int mat[MAXN+10];
 
ull l[MAXN+10],r[MAXN+10],up[MAXN+10];
 
ull ans[MAXN+10],sum;
 
void init()
{
	freopen("scare.in","r",stdin);
    int T;
    scanf("%d",&T);
     
    while (T--) {
        scanf("%s",str+1);
        int len=strlen(str+1);
         
        sum=0;
         
        static int st[MAXN+10];
         
        int top=0;
         
        for (int i=1;i<=len;i++)
            if (str[i]=='(') st[++top]=i;
            else if (top) {
                mat[i]=st[top]; 
		mat[st[top]]=i;
                top--;
	       	up[mat[i]]=st[top];
	    }
         
        for (int i=1;i<=len;i++)
            if (mat[i] && str[i]==')') r[i]=r[mat[i]-1]+1;
         
        for (int i=len;i>=1;i--)
            if (mat[i] && str[i]=='(') l[i]=l[mat[i]+1]+1;
         
        for (int i=1;i<=len;i++)
            if (mat[i]) {
                if (str[i]=='(')
                    ans[i]=(l[i]*r[mat[i]]%mod+ans[up[i]])%mod;
                else ans[i]=ans[mat[i]];
                sum+=ans[i]*i%mod; 
	    }
         
        cout<<sum<<endl;
         
        for (int i=1;i<=len;i++)
            l[i]=r[i]=up[i]=mat[i]=ans[i]=0; 
    }
     
    return ;
}
 
int main()
{
    init();
    return 0;
}
