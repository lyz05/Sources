#include<bits/stdc++.h>
using namespace std;

int graph[20][20];                                   //图的大小
int n;                                               //节点数
int visit[20];                                       //是否访问
int matched[20];                                     //是否已经匹配，对应的匹配点

//显示匹配结果
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
*   dfs实现,
*   params:
*       x:起始的未匹配点
*   return:
*       1:找到增广路
*       0:未找到
*/
int dfs_solve(int x){
    //找到一个和节点存在边的点，并且该点在本轮中没有被访问过
    for(int i = 0; i < n; i++){
        if(graph[x][i] && !visit[i]){
                visit[i] = 1;                         //标记为匹配过
            //按照交替路的模式找增广路，增广路相对于交替路的特性是就是，第一个节点和最后一个节点都是未匹配过的节点
            if(matched[i] == -1 || dfs_solve(matched[i]) == 1){           //直接跳到matched[i]能够保证匹配边和未匹配边交替
                //说明找到了一个未匹配节点，将所有匹配边变为未匹配边，将所有未匹配边变为匹配边，这样匹配边数会加1,这个交换过程通过回溯实现
				//x--i--matched[i]
                matched[x] = i;
                matched[i] = x;
                cout<<(x+1)<<" 和 "<<(i+1)<<" 匹配"<<endl;
                return 1;
            }
        }
    }
    return 0;
}

/*
*   dfs实现,
*   params:
*       x:起始的未匹配点
*   return:
*       num:0表示未找到增广路，1表示找到
*/
int hungarian1(){
    memset(matched, -1, sizeof(matched));
    int sum = 0;

    for(int i = 0; i < n; i++){
        if(matched[i] == -1){
            cout<<endl;
            cout<<"从 "<<(i + 1)<<" 开始匹配"<<endl;
            memset(visit, 0 , sizeof(visit));
            sum += dfs_solve(i);
        }
    }

    cout<<"共有 "<<sum<<" 匹配项"<<endl;
    show();

    return sum;
}

//匈牙利算法，bfs实现
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

                if(matched[i] == -1){                           //找到一个未匹配点
                    flag = 1;                                   //交换匹配路径和未匹配路径，不能用回溯，只能向前找祖先

                    int l = u, r = i;

                    while(l != -1){
                        int tmp = matched[l];

                        matched[l] = r;
                        matched[r] = l;

                        cout<<(l+1)<<" 和 "<<(r+1)<<" 匹配"<<endl;

                        r = tmp;
                        l = prev[l];
                    }
                    num++;
                }
                else{                                           //点不是未匹配点
                    prev[matched[i]] = u;
                    items.push(matched[i]);                     //只有找到了匹配边才能压入端点，保证交替进行
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
            cout<<"从 "<<(i + 1)<<" 开始匹配"<<endl;

            memset(visit, 0, sizeof(visit));
            sum += bfs_solve(i);
        }
    }

    cout<<"共有 "<<sum<<" 匹配项"<<endl;
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

    hungarian2();


    return 0;
}
