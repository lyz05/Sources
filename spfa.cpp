#include <iostream>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
 
const int MAXN=100;
const int INF=0x7FFFFFFF;
 
struct edge
{
    int to,weight;
};
 
vector<edge> adjmap[MAXN];//�ڽӱ�
bool in_queue[MAXN];//�����Ƿ��ڶ�����
int in_sum[MAXN];//������Ӵ���
int dist[MAXN];//Դ�㵽��������·��
int path[MAXN];//�洢����i��ǰһ������
int nodesum;//������
int edgesum;//����
 
bool SPFA(int source)
{
    deque<int> dq;
    int i,j,x,to;
    for(i=1;i<=nodesum;i++)
    {
        in_sum[i]=0;
        in_queue[i]=false;
        dist[i]=INF;
        path[i]=-1;
    }
    dq.push_back(source);
    in_sum[source]++;
    dist[source]=0;
    in_queue[source]=true;
//��ʼ�����
 
    while(!dq.empty())
    {
        x=dq.front();
        dq.pop_front();
        in_queue[x]=false;
        for(i=0;i<adjmap[x].size();i++)
        {
            to=adjmap[x][i].to;
            if((dist[x]<INF)&&(dist[to]>dist[x]+adjmap[x][i].weight))
            {
                dist[to]=dist[x]+adjmap[x][i].weight;
                path[to]=x;
                if(!in_queue[to])
                {
                    in_queue[to]=true;
                    in_sum[to]++;
                    if(in_sum[to]==nodesum) return false;
                    if(!dq.empty())
                    {
                        if(dist[to]>dist[dq.front()]) dq.push_back(to);
                        else dq.push_front(to);
                    }else dq.push_back(to);
                }
            }
        }
    }
    return true;
}
 
void Print_Path(int x)
{
    stack<int> s;
    int w=x;
    while(path[w]!=-1)
    {
        s.push(w);
        w=path[w];
    }
    cout<<"����1������"<<x<<"�����·������Ϊ��"<<dist[x]<<endl;
    cout<<"��������·��Ϊ��1";
    while(!s.empty())
    {
        cout<<s.top()<<"";
        s.pop();
    }
    cout<<endl;
}
 
int main()
{
    int i,s,e,w;
    edge temp;
    cout<<"���붥�����ͱ�����";
    cin>>nodesum>>edgesum;
    for(i=1;i<=nodesum;i++)
    adjmap[i].clear();//����ڽӱ�
    for(i=1;i<=edgesum;i++)
    {
        cout<<"�����"<<i<<"���ߵ���㡢�յ㻹�ж�Ӧ��Ȩֵ��";
        cin>>s>>e>>w;
        temp.to=e;
        temp.weight=w;
        adjmap[s].push_back(temp);
    }
    if(SPFA(1))
    {
        for(i=2;i<=nodesum;i++) Print_Path(i);
    } else cout<<"ͼ�д��ڸ�Ȩ��·"<<endl;
    return 0;
}
