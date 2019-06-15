//算法5.5 计算二叉树的深度
#include<iostream>
using namespace std;

//二叉树的二叉链表存储表示
typedef struct BiNode
{				
	char data;						//结点数据域
	struct BiNode *lchild,*rchild;	//左右孩子指针
}BiTNode,*BiTree;

//用算法5.3建立二叉链表
void CreateBiTree(BiTree &T)
{	
	//按先序次序输入二叉树中结点的值（一个字符），创建二叉链表表示的二叉树T
	char ch;
	cin >> ch;
	if(ch=='#')  T=NULL;			//递归结束，建空树
	else{							
		T=new BiTNode;
		T->data=ch;					//生成根结点
		CreateBiTree(T->lchild);	//递归创建左子树
		CreateBiTree(T->rchild);	//递归创建右子树
	}								//else
}									//CreateBiTree

//************** 完成算法5.5 计算二叉树的深度 算法实现*******************************
int Depth(BiTree T)
{
	int i,j;
	if(T==NULL)
		return 0;
	if(T->lchild)
		i=Depth(T->lchild); // 左子树深度
	else
		i=0;
	if(T->rchild)
		j=Depth(T->rchild);  // 右子树深度
	else
		j=0;
	
	return i>j?i+1:j+1;
}



int main()
{
	BiTree tree;
	cout<<"请输入建立二叉链表的序列：\n";
	//12#4##35##6##
	CreateBiTree(tree);
	cout<<"树的深度为："<<Depth(tree)<<endl;

	return 0;
}
