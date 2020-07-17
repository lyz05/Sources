#include<iostream>
#include<cstring>
using namespace std;

const int N = 2*500+5;
int graph[N][N];                                   //ͼ�Ĵ�С
int n,m,k;                                               //�ڵ���
int visit[N];                                       //�Ƿ����
int matched[N];                                     //�Ƿ��Ѿ�ƥ�䣬��Ӧ��ƥ���


/*
*   dfsʵ��,
*   params:
*       x:��ʼ��δƥ���
*   return:
*       1:�ҵ�����·
*       0:δ�ҵ�
*/
int dfs_solve(int x){
    //�ҵ�һ���ͽڵ���ڱߵĵ㣬���Ҹõ��ڱ�����û�б����ʹ�
    for(int i = 0; i < n; i++){
        if(graph[x][i] && !visit[i]){
                visit[i] = 1;                         //���Ϊƥ���
            //���ս���·��ģʽ������·������·����ڽ���·�������Ǿ��ǣ���һ���ڵ�����һ���ڵ㶼��δƥ����Ľڵ�
            if(matched[i] == -1 || dfs_solve(matched[i]) == 1){           //ֱ������matched[i]�ܹ���֤ƥ��ߺ�δƥ��߽���
                //˵���ҵ���һ��δƥ��ڵ㣬������ƥ��߱�Ϊδƥ��ߣ�������δƥ��߱�Ϊƥ��ߣ�����ƥ��������1,�����������ͨ������ʵ��
				//x--i--matched[i]
                matched[x] = i;
                matched[i] = x;
                //cout<<(x+1)<<" �� "<<(i+1)<<" ƥ��"<<endl;
                return 1;
            }
        }
    }
    return 0;
}

/*
*   dfsʵ��,
*   params:
*       x:��ʼ��δƥ���
*   return:
*       num:0��ʾδ�ҵ�����·��1��ʾ�ҵ�
*/
int hungarian1(){
    memset(matched, -1, sizeof(matched));
    int sum = 0;

    for(int i = 0; i < n; i++){
        if(matched[i] == -1){
            //cout<<endl;
            //cout<<"�� "<<(i + 1)<<" ��ʼƥ��"<<endl;
            memset(visit, 0 , sizeof(visit));
            sum += dfs_solve(i);
        }
    }

    //cout<<"���� "<<sum<<" ƥ����"<<endl;

    return sum;
}

int main()
{
	freopen("H.in","r",stdin);
	
	while (cin >> k >> m >> n && k){
		memset(graph, 0, sizeof(graph));
		n = m+n;
		while (k --)
		{
			int x,y;
			cin >> x >> y;
			y += m;
			graph[x-1][y-1] = 1;
			graph[y-1][x-1] = 1;
		}
		cout << hungarian1() << endl;
	} 

    return 0;
}
