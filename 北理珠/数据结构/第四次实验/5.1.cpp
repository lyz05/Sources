//�㷨5.1 ��������ĵݹ��㷨
#include<iostream>
using namespace std;
typedef struct BiNode{				//����������
	char data;
	struct BiNode *lchild,*rchild;
}BiTNode,*BiTree;

//���㷨5.3 ���������˳������������
void CreateBiTree(BiTree &T){	
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

void InOrderTraverse(BiTree T){  
	//�������������T�ĵݹ��㷨
	if(T){
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}
//**************************************************** �������ͺ���ĵݹ��㷨ʵ��*********************************************

void FirstOrderTraverse(BiTree T){  
	//���������������T�ĵݹ��㷨
	if(T){
		cout << T->data;
		FirstOrderTraverse(T->lchild);
		FirstOrderTraverse(T->rchild);
	}
}

void lastOrderTraverse(BiTree T){  
	//���������������T�ĵݹ��㷨
	if(T){
		lastOrderTraverse(T->lchild);
		lastOrderTraverse(T->rchild);
		cout << T->data;
	}
}

int main(){
	BiTree tree;
	cout<<"�����뽨��������������У�\n";
	//12#4##35##6##
	CreateBiTree(tree);
	cout<<"��������Ľ��Ϊ��\n";
	InOrderTraverse(tree);
	cout<<endl;
	//*************���������㷨������������Ľ��************
	cout<<"��������Ľ��Ϊ��\n";
	FirstOrderTraverse(tree);
	cout<<endl;
	//*************���ú����㷨������������Ľ��************
	cout<<"��������Ľ��Ϊ��\n";
	lastOrderTraverse(tree);
	cout<<endl;
	return 0;
}
