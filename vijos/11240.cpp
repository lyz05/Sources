#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
using namespace std;
const int MAXN = 50;

int n = 1, len1[MAXN], len2[MAXN];
char list1[MAXN][MAXN], list2[MAXN][MAXN];
vector<char> v;
set<string> st;

struct Status{
    int dep;       
    char s[100];   
}first1, first2;

queue<Status> q;

bool check(Status a, Status b){
    if(strlen(a.s) != strlen(b.s))
      return 0;     
    for(int i=0; i<strlen(a.s); i++)
      if(a.s[i] != b.s[i])
        return 0;
    return 1; 
}

void clear(Status &now){
    for(int i=0; i<50; i++)
       now.s[i] = '\0';
}

void check(Status tmp, int a, int b){
    //int bri = strlen(tmp.s);
    //int tot = min(a+len1[b], bri);
    for(int i=a; i<a+len1[b]; i++)
      if(list1[b][i-a] != tmp.s[i])
        return; 
    v.clear();    
    Status now;
    clear(now);
    for(int i=0; i<a; i++)
      v.push_back(tmp.s[i]);
    for(int i=0; i<len2[b]; i++)
      v.push_back(list2[b][i]);
    for(int i=a+len1[b]; i<strlen(tmp.s); i++)
      v.push_back(tmp.s[i]);
    for(int i=0; i<v.size(); i++)
      now.s[i] = v[i];
    now.dep = tmp.dep + 1;
    if(strlen(now.s) > 20)
      return;
    if(!st.count(now.s)){
      q.push(now);
      st.insert(now.s);
    } 
}

void bfs(){
    q.push(first1);
    while(!q.empty()){
      Status now = q.front();
      if(now.dep > 10){
        printf("NO ANSWER!");
        break;
      }
      if(check(now, first2)){
        printf("%d", now.dep);
        break;
      }
      q.pop();
      for(int i=0; i<strlen(now.s); i++)
        for(int j=1; j<=n; j++)
          check(now, i, j); 
      if(q.empty())
        printf("NO ANSWER!");      
    }
}

int main()
{
    FILE *fin = fopen("1124.in", "r");
    fscanf(fin, "%s%s", first1.s, first2.s);
    while(fscanf(fin, "%s%s", list1[n], list2[n]) != EOF){
      len1[n] = strlen(list1[n]);
      len2[n] = strlen(list2[n]);
      n++;
    }
    n--;       
    bfs();
    return 0;
}
