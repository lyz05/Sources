#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

typedef long long LL;

const int MaxN=2005;
const int MaxM=1000005;
const int MinMod=999973;
const LL MaxMod=499999999999993ll;

struct Node
{int no,cnt;//no为单词所在文章编号,cnt为单词出现的次数 
 LL s;//s为单词的hash值 
 int next;//用开散列解决冲突 
}h[MaxM];

int N,M,L,tot,ans;
int first[MaxM];
char str[MaxN][MaxN];

void add(int u,int x,LL s)//将在第x篇文章中出现的短hash值为u,长hash值为s的单词加入hash表 
{++tot;
 h[tot].s=s;
 h[tot].cnt=1;
 h[tot].no=x;
 h[tot].next=first[u];
 first[u]=tot;
}

void hash(int x,int u,LL s)
{int i;
 for(i=first[u];i!=0;i=h[i].next)
   if (s==h[i].s)//在hash表出现过 
     {if (h[i].no==x) return;//也是在第x篇文章中出现 
      h[i].no=x;
      h[i].cnt++;//出现的次数加1 
      return;
     }
 add(u,x,s);
}

void init()
{int i;
 scanf("%d%d%d",&N,&M,&L);
 for(i=1;i<=N;i++)
   scanf("%s",&str[i]);
 ans=0;
}

void work()
{int i,j,u,k,k1;
 LL s,k2;
 k1=k2=1;
 for(j=0;j<L-1;j++)
   {k1=k1*26%MinMod;//数量级 
    k2=k2*26%MaxMod;
   }
 for(i=1;i<=N;i++)
   {u=s=0;
    for (j=0;j<L;j++)
      {u=(u*26+str[i][j])%MinMod;//短hash值 
       s=(s*26+str[i][j])%MaxMod;//长hash值 
      }
    hash(i,u,s);
    k=strlen(str[i]);
    for(j=L;j<k;j++)
      {u=((u-str[i][j-L]*k1)%MinMod+MinMod)%MinMod;//前面去一位后面加一位 
       s=((s-str[i][j-L]*k2)%MaxMod+MaxMod)%MaxMod;
       u=(u*26+str[i][j])%MinMod;
       s=(s*26+str[i][j])%MaxMod;
       hash(i,u,s);
      }
   }
}

void output()
{int i;
 for(i=1;i<=tot;i++)
   if(h[i].cnt>=M) ++ans;
 printf("%d\n",ans);
}

int main(void)
{
 init();
 work();
 output();
 return 0;
}
