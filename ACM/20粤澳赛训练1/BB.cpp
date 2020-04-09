#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define me memset
const int N = 1e6 + 10;
const int M = 1e9 + 7;
using namespace std;
typedef pair<int,int> PII;
typedef pair<long,long> PLL;
int t;
int n,a[N],c[N];
int p[11]={2,3,5,7,11,13,17,19,23,29,31};
map<int,int> ans;
 
int main() {
    ios::sync_with_stdio(false);
        cin>>t;
         while(t--){
             me(c,0,sizeof(c));
             ans.clear();
             cin>>n;
              for(int i=1;i<=n;++i) cin>>a[i];
              int cnt=0;
              for(int i=1;i<=n;++i)
                  for(int j=0;j<11;++j){
                      if(a[i]%p[j]==0){
                          if(c[j]==0) c[j]=++cnt;
                          ans[i]=c[j];
                          break;
                      }
                  }
              map<int,int>::iterator iter;
                  printf("%d\n",cnt);
                  for(iter=ans.begin();iter!=ans.end();++iter) printf("%d ",iter->se);
                  printf("\n");
         }
    return 0;
}