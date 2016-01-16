/*
    ���⣺����һ������ͳ�ƾ����K�ĵ��  O(n^2)�㷨������
    ��rootΪ����������ͳ�� a -> root -> b �ĸ�����Ȼ���ٷ��ζ�ÿ������������ͳ�ƣ�
    ���ܵõ����ˡ�
    ����ͨ������·����һ������root��ȥͳ�ƽ���˼ά���Ӷ���
    ����һ�����⣬����a,b����rootͬһ�������Ļ���ȻҪȥ��
    ��dist[]��㵽���ľ��룬Ȼ��count()����ͷβָ���������*first+*last<=K�ĸ���
    ret+=�����������*first+*last<=K�ĸ��������л����ͬһ�������������
    ��ret-=ͬһ���������*first+*last<=K�ĸ���

    ���ݹ�������seq���������������1-N�ĵݹ飬Ҳ�Ƕ�����seq[1-N]�ĵݹ�
    ���Դ�һ��Ҫ�ݹ������seq[]
    ����Ҫ�Ժܶ���������еݹ飬��һ�����д�ÿ����չ�����������е�ͷβָ��
    ���忴����
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 10005;

struct Node{int w,v,next;}nodes[MAXN*2];

int G[MAXN];
int Q[MAXN][2],front,tail;
int dist[MAXN],seq[MAXN];
bool vi[MAXN];
int N,L,alloc,M;
int best_size,center,len,ret;

void add(int u,int v,int w)
{
    nodes[alloc].v=v,nodes[alloc].w=w;
    nodes[alloc].next=G[u];G[u]=alloc++;
}

int count(int *first,int *last)
{
    int ret = 0;
    sort(first,last--);
    while(first<last)
    {
        if(*first+*last<=L)ret+=last-first++;//last�У���last֮ǰ�϶�Ҳ�У�ͳ��first+1��last�ĸ���
        else last--;
    }
    return ret;
}

int centerOfGravity(int u,int p)
{
    int max_sub = 0,size = 1;
    for(int son=G[u];son!=-1;son=nodes[son].next)
    {
        int v=nodes[son].v;
        if(v==p||!vi[v])continue;
        int t = centerOfGravity(v,u);
        size += t;
        if(t>max_sub)max_sub = t;
    }
    if(Q[front][1]-Q[front][0]-size>max_sub)
        max_sub = Q[front][1]-Q[front][0]-size;
    if(max_sub<best_size)
    {
        center = u;
        best_size = max_sub;
    }
    return size;
}
void find(int u,int p,int now_dist)
{
    seq[len] = u;
    dist[len++] = now_dist;
    int last = len;
    for(int son=G[u];son!=-1;son=nodes[son].next)
    {
        int v = nodes[son].v,w=nodes[son].w;
        if(!vi[v]||v==p)continue;
        find(v,u,now_dist+w);
        if(p==-1){//Ϊ��ʱ
            Q[tail][0]=last,Q[tail][1]=len;//����չ����������seq[last,len)
            tail++;
            ret-=count(dist+last,dist+len);
            last = len;
        }
    }
}
int main()
{
    scanf("%d%d",&N,&L);
        memset(G+1,-1,sizeof(int)*N);
        alloc = 0;
        for(int i=1;i<N;i++)
        {
            int w,v,u;
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        ret = 0;
        front=0;tail=1;
        for(int i=1;i<=N;i++)seq[i]=i;
        for(Q[front][0]=1,Q[front][1]=N+1;front!=tail;front++)
        {
            //if(Q[front][0]==Q[front][1])continue;
            for(int i=Q[front][0];i<Q[front][1];i++)vi[seq[i]]=1;
            
            best_size=N+1;
            centerOfGravity(seq[Q[front][0]],-1);//

            len = Q[front][0];
            find(center,-1,0);
            ret+=count(dist+Q[front][0],dist+Q[front][1]);

            for(int i=Q[front][0];i<Q[front][1];i++)vi[seq[i]]=0;
        }
        printf("%d\n",ret);
    
    return 0;
}
