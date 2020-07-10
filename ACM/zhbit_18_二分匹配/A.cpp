#include<iostream>
#include<cstring>
using namespace std;

const int N = 2*500+5;
int graph[N][N];                                   //图的大小
int n,m,k;                                               //节点数
int visit[N];                                       //是否访问
int matched[N];                                     //是否已经匹配，对应的匹配点


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
                //cout<<(x+1)<<" 和 "<<(i+1)<<" 匹配"<<endl;
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
            //cout<<endl;
            //cout<<"从 "<<(i + 1)<<" 开始匹配"<<endl;
            memset(visit, 0 , sizeof(visit));
            sum += dfs_solve(i);
        }
    }

    //cout<<"共有 "<<sum<<" 匹配项"<<endl;

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
