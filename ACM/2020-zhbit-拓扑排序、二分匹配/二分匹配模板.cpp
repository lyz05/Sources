#include<bits/stdc++.h>
using namespace std;

int graph[20][20];                                   //ͼ�Ĵ�С
int n;                                               //�ڵ���
int visit[20];                                       //�Ƿ����
int matched[20];                                     //�Ƿ��Ѿ�ƥ�䣬��Ӧ��ƥ���

//��ʾƥ����
void show(){
    memset(visit, 0, sizeof(visit));

    for(int i = 0; i < n; i++){
        if(!visit[i]){
            if(matched[i] != -1){
                cout<<"("<<(i + 1)<<", "<<(matched[i] + 1)<<")"<<endl;
                visit[i] = 1;
                visit[matched[i]] = 1;
            }
        }
    }
}

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
                cout<<(x+1)<<" �� "<<(i+1)<<" ƥ��"<<endl;
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
*       sum:���ͼ�����ƥ�� 
*/
int hungarian1(){
    memset(matched, -1, sizeof(matched));
    int sum = 0;

    for(int i = 0; i < n; i++){
        if(matched[i] == -1){
            cout<<endl;
            cout<<"�� "<<(i + 1)<<" ��ʼƥ��"<<endl;
            memset(visit, 0 , sizeof(visit));
            sum += dfs_solve(i);
        }
    }

    cout<<"���� "<<sum<<" ƥ����"<<endl;
    show();

    return sum;
}

//�������㷨��bfsʵ��
int bfs_solve(int x){
    queue<int> items;
    int prev[20];
    int num = 0;

    memset(prev, -1, sizeof(prev));

    items.push(x);
    bool flag = 0;
    while(!flag && items.size()){
        int u = items.front();
        items.pop();

        for(int i = 0; i < n; i++){
            if(graph[u][i] && !visit[i] && !flag){
                visit[i] = 1;

                if(matched[i] == -1){                           //�ҵ�һ��δƥ���
                    flag = 1;                                   //����ƥ��·����δƥ��·���������û��ݣ�ֻ����ǰ������

                    int l = u, r = i;

                    while(l != -1){
                        int tmp = matched[l];

                        matched[l] = r;
                        matched[r] = l;

                        cout<<(l+1)<<" �� "<<(r+1)<<" ƥ��"<<endl;

                        r = tmp;
                        l = prev[l];
                    }
                    num++;
                }
                else{                                           //�㲻��δƥ���
                    prev[matched[i]] = u;
                    items.push(matched[i]);                     //ֻ���ҵ���ƥ��߲���ѹ��˵㣬��֤�������
                }
            }
        }
    }
    return num;
}

int hungarian2(){
    memset(matched, -1, sizeof(matched));
    int sum = 0;

    for(int i = 0 ; i < n; i++){
        if(matched[i] == -1){
            cout<<endl;
            cout<<"�� "<<(i + 1)<<" ��ʼƥ��"<<endl;

            memset(visit, 0, sizeof(visit));
            sum += bfs_solve(i);
        }
    }

    cout<<"���� "<<sum<<" ƥ����"<<endl;
    show();

    return sum;
}

int main()
{
    memset(graph, 0, sizeof(graph));

    graph[0][4] = 1;
    graph[0][6] = 1;

    graph[1][4] = 1;

    graph[2][4] = 1;
    graph[2][5] = 1;

    graph[3][6] = 1;
    graph[3][7] = 1;

    graph[4][0] = 1;
    graph[4][1] = 1;
    graph[4][2] = 1;

    graph[5][2] = 1;

    graph[6][0] = 1;
    graph[6][3] = 1;

    graph[7][3] = 1;

    n = 8;

    hungarian1();

    cout<<"**********************************"<<endl;

    //hungarian2();


    return 0;
}
