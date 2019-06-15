//�㷨5.6 ͳ�ƶ������н��ĸ���
#include<iostream>
using namespace std;

//�������Ķ�������洢��ʾ
typedef struct BiNode
{				
	char data;						//���������
	struct BiNode *lchild,*rchild;	//���Һ���ָ��
}BiTNode,*BiTree;

//���㷨5.3������������
void CreateBiTree(BiTree &T)
{	
	//�������������������н���ֵ��һ���ַ������������������ʾ�Ķ�����T
	char ch;
	cin >> ch;
	if(ch=='#')  T=NULL;			//�ݹ������������
	else{							
		T=new BiTNode;
		T->data=ch;					//���ɸ����
		CreateBiTree(T->lchild);	//�ݹ鴴��������
		CreateBiTree(T->rchild);	//�ݹ鴴��������
	}								//else
}									//CreateBiTree

//************** ����㷨5.6ͳ�ƶ������н��ĸ��� �㷨ʵ��*******************************
int NodeCount(BiTree T)
{
	int ret = 0; 
	if(T!=NULL)
	{
		ret ++;
		ret += NodeCount(T->lchild);
		ret += NodeCount(T->rchild);
	}
	return ret;
}
 

int main()
{
	BiTree tree;
	cout<<"�����뽨��������������У�\n";
	//12#4##35##6##
	CreateBiTree(tree);
	cout<<"������Ϊ��"<<NodeCount(tree)<<endl;
	
	return 0;
}
