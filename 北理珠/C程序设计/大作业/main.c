#include"main.h" 0
int main()
{
	int n;
	printf("************************************************\n");
	printf("1. ԭʼ�ļ���ȡ\n");
	printf("2. �������������\n");
	printf("3. ��ƽ���ɼ��������\n");
	printf("4. �������ѧԺѧ��\n");
	printf("5. �޸ĸ���ѧ���ɼ���Ϣ\n");
	printf("6. ��������ѯѧ�������\n");
	printf("7. �޸�ϵͳ����\n");
	printf("8. ����ϵͳ\n");
    printf("************************************************\n");
    scanf("%d",&n);
    switch (n)
    {
    	case 1:inputStu(stu,5,"data\\Stu_Info3.txt");break;
	}
	return 0; 
 } 
