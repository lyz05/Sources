#include <iostream>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <algorithm>  
  
using namespace std;  
long long a,b,x,y;  
long long extended_gcd(long long  a,long long b,long long &x,long long &y)  
{  
    if (!b) { x=1; y=0; return a; }  
    else {   
         long long ans=extended_gcd(b,a%b,x,y);   
         long long t=x; x=y; y=t-(a/b)*y;  
         return ans;  
    }  
}  
int main()  
{  
    cin>>a>>b;  
    long long ans = extended_gcd(a, b, x, y);  
    //cout << a*x+b*y<<endl;  
  
    if (ans!=1) cout<<"No answer"<<endl;  
    else  
    {  
        x=x%b;  
        while (x<0) x+=b;  
        cout <<x<<endl;  
    }  
    system("pause");  
    return 0;  
}  
