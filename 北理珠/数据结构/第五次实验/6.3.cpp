//�㷨6.3�������������������ͨͼ�ĵݹ��㷨

#include <iostream>
#include <cstring>
using namespace std;

#define MVNum 100									//��󶥵���
typedef char VerTexType;							//���趥�����������Ϊ�ַ��� 
typedef int ArcType;                 				//����ߵ�Ȩֵ����Ϊ���� 

typedef struct{ 
	VerTexType vexs[MVNum];            				//����� 
	ArcType arcs[MVNum][MVNum];      				//�ڽӾ��� 
	int vexnum,arcnum;                				//ͼ�ĵ�ǰ�����ͱ��� 
}Graph;
 
bool visited[MVNum];           					//���ʱ�־���飬���ֵΪ"false" 
int FirstAdjVex(Graph G , int v);				//����v�ĵ�һ���ڽӵ�
int NextAdjVex(Graph G , int v , int w);		//����v�����w����һ���ڽӵ�

int LocateVex(Graph G , VerTexType v){
	//ȷ����v��G�е�λ��
	for(int i = 0; i < G.vexnum; ++i)
		if(G.vexs[i] == v)
			return i;
		return -1;
}//LocateVex

void CreateUDN(Graph &G){ 
    //�����ڽӾ����ʾ��������������G ���㷨6.1 
	int i , j , k;
	cout <<"�������ܶ��������ܱ��� , �Կո����:";
    cin >> G.vexnum >> G.arcnum;						 //�����ܶ��������ܱ���
	cout << endl;

	cout << "���������ƣ��� a��" << endl;

    for(i = 0; i < G.vexnum; ++i){   
		cout << "�������" << (i+1) << "���������:";
		cin >> G.vexs[i];                        		 //������������Ϣ 
	}
	cout << endl;

    for(i = 0; i < G.vexnum; ++i)                		 //��ʼ���ڽӾ��󣬱ߵ�Ȩֵ����Ϊ����ֵMaxInt 
		for(j = 0; j < G.vexnum; ++j)   
			G.arcs[i][j] = 0;  
	cout << "����������Ķ��㣬�磺a b" << endl;
	for(k = 0; k < G.arcnum;++k){						 //�����ڽӾ��� 
		VerTexType v1 , v2;
		cout << "�������" << (k + 1) << "���������Ķ���:";
		cin >> v1 >> v2;								 //����һ���������Ķ��㼰Ȩֵ
		i = LocateVex(G, v1);  j = LocateVex(G, v2);	 //ȷ��v1��v2��G�е�λ�ã�������������±� 
		G.arcs[j][i] = G.arcs[i][j] = 1;                 //��<v1, v2>�ĶԳƱ�<v2, v1>��ȨֵΪw 
	}//for
}//CreateUDN 

/******************************�������*******************************/ 
//�㷨6.3 �����������������ͨͼ�ĵݹ��㷨
void DFS(Graph G, int v){        			//�ӵ�v����������ݹ��������ȱ���ͼG 
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
	cout << "************�㷨6.3�������������������ͨͼ�ĵݹ��㷨**************" << endl << endl;
	Graph G;
	CreateUDN(G);
	cout << endl;
	cout << "������ͨͼG������ɣ�" << endl << endl;
	
	cout << "�����������ͨͼ����ʼ�㣺";
	VerTexType c;
	cin >> c;

	int i;
	for(i = 0 ; i < G.vexnum ; ++i){
		if(c == G.vexs[i])
			break;
	}
	cout << endl;
	while(i >= G.vexnum){
		cout << "�õ㲻���ڣ����������룡" << endl;
		cout << "�����������ͨͼ����ʼ�㣺";
		cin >> c;
		for(i = 0 ; i < G.vexnum ; ++i){
			if(c == G.vexs[i])
				break;
		}
	}
	cout << "�����������������ͨͼ�����" << endl;
	
	/*******************�������***********************/
	//��д����DFS�������������ȱ�����������
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
