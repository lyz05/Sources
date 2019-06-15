//算法6.3　深度优先搜索遍历连通图的递归算法

#include <iostream>
#include <cstring>
using namespace std;

#define MVNum 100									//最大顶点数
typedef char VerTexType;							//假设顶点的数据类型为字符型 
typedef int ArcType;                 				//假设边的权值类型为整型 

typedef struct{ 
	VerTexType vexs[MVNum];            				//顶点表 
	ArcType arcs[MVNum][MVNum];      				//邻接矩阵 
	int vexnum,arcnum;                				//图的当前点数和边数 
}Graph;
 
bool visited[MVNum];           					//访问标志数组，其初值为"false" 
int FirstAdjVex(Graph G , int v);				//返回v的第一个邻接点
int NextAdjVex(Graph G , int v , int w);		//返回v相对于w的下一个邻接点

int LocateVex(Graph G , VerTexType v){
	//确定点v在G中的位置
	for(int i = 0; i < G.vexnum; ++i)
		if(G.vexs[i] == v)
			return i;
		return -1;
}//LocateVex

void CreateUDN(Graph &G){ 
    //采用邻接矩阵表示法，创建无向网G ，算法6.1 
	int i , j , k;
	cout <<"请输入总顶点数，总边数 , 以空格隔开:";
    cin >> G.vexnum >> G.arcnum;						 //输入总顶点数，总边数
	cout << endl;

	cout << "输入点的名称，如 a：" << endl;

    for(i = 0; i < G.vexnum; ++i){   
		cout << "请输入第" << (i+1) << "个点的名称:";
		cin >> G.vexs[i];                        		 //依次输入点的信息 
	}
	cout << endl;

    for(i = 0; i < G.vexnum; ++i)                		 //初始化邻接矩阵，边的权值均置为极大值MaxInt 
		for(j = 0; j < G.vexnum; ++j)   
			G.arcs[i][j] = 0;  
	cout << "输入边依附的顶点，如：a b" << endl;
	for(k = 0; k < G.arcnum;++k){						 //构造邻接矩阵 
		VerTexType v1 , v2;
		cout << "请输入第" << (k + 1) << "条边依附的顶点:";
		cin >> v1 >> v2;								 //输入一条边依附的顶点及权值
		i = LocateVex(G, v1);  j = LocateVex(G, v2);	 //确定v1和v2在G中的位置，即顶点数组的下标 
		G.arcs[j][i] = G.arcs[i][j] = 1;                 //置<v1, v2>的对称边<v2, v1>的权值为w 
	}//for
}//CreateUDN 

/******************************程序填空*******************************/ 
//算法6.3 深度优先搜索遍历连通图的递归算法
void DFS(Graph G, int v){        			//从第v个顶点出发递归地深度优先遍历图G 
	cout << G.vexs[v] << " "; 
 	for (int j = 0;j <= G.vexnum;j ++)
 	{
 		if (G.arcs[v][j] != 0 && !visited[j])
		{
			visited[j] = 1;
			DFS(G,j);
			//visited[j] = 0;
		}
 	}
}//DFS


int main(){
	cout << "************算法6.3　深度优先搜索遍历连通图的递归算法**************" << endl << endl;
	Graph G;
	CreateUDN(G);
	cout << endl;
	cout << "无向连通图G创建完成！" << endl << endl;
	
	cout << "请输入遍历连通图的起始点：";
	VerTexType c;
	cin >> c;

	int i;
	for(i = 0 ; i < G.vexnum ; ++i){
		if(c == G.vexs[i])
			break;
	}
	cout << endl;
	while(i >= G.vexnum){
		cout << "该点不存在，请重新输入！" << endl;
		cout << "请输入遍历连通图的起始点：";
		cin >> c;
		for(i = 0 ; i < G.vexnum ; ++i){
			if(c == G.vexs[i])
				break;
		}
	}
	cout << "深度优先搜索遍历连通图结果：" << endl;
	
	/*******************程序填空***********************/
	//填写调用DFS函数输出深度优先遍历结果的语句
	memset(visited,0,sizeof visited);
	for(i = 0 ; i < G.vexnum ; ++i){
		if(c == G.vexs[i])
		{ 
			visited[i] = 1;
			DFS(G,i);
			break;
		}
	}
	cout << endl;
	return 0;
}//main
