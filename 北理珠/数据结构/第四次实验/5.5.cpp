//�㷨5.5 ��������������
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

//************** ����㷨5.5 �������������� �㷨ʵ��*******************************
int Depth(BiTree T)
{
	int i,j;
	if(T==NULL)
		return 0;
	if(T->lchild)
		i=Depth(T->lchild); // ���������
	else
		i=0;
	if(T->rchild)
		j=Depth(T->rchild);  // ���������
	else
		j=0;
	
	return i>j?i+1:j+1;
}



int main()
{
	BiTree tree;
	cout<<"�����뽨��������������У�\n";
	//12#4##35##6##
	CreateBiTree(tree);
	cout<<"�������Ϊ��"<<Depth(tree)<<endl;

	return 0;
}
