#include<stdio.h>
#include<math.h>

int main()
{
	int a,b,c;
	printf("��������Ҫ����һԪ���η��̵�ϵ��a,b,c:\n");
	printf("a=");scanf("%d",&a);
	printf("b=");scanf("%d",&b);
	printf("c=");scanf("%d",&c);
	//����ϵ�� 
	double delta = b*b-4*a*c,x1,x2;
	x1 = (-b*1.0-sqrt(delta))/(2*a*1.0);
	x2 = (-b*1.0+sqrt(delta))/(2*a*1.0);
	//������� 
	//printf("��Ҫ��ķ����ǣ�%dx^2+%dx+%d=0\n",a,b,c);
	if (a==0 && b==0)
		if (c==0) {
			printf("��ʽΪ���ʽ\n");
			return 0;	
		}
		else {
			printf("��ʽ������\n");
			return 0;	
		}
	if (delta<0) printf("���̲�����ʵ����\n");else
		if (delta==0) printf("����ֻ��һ��ʵ����:x=%f\n",x1);else
			if (a==0) printf("�ⲻ��һ��һԪ���η���\n"); else 
				printf("���̵��������ǣ�x1=%f,x2=%f\n",x1,x2);
	//�����ж� 
	
	return 0;
}
//scanf("%d%d%d",&a,&b,&c);
//x=(-b+-sart(delta))/(2a)
	
