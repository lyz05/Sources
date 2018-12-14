#include"main.h" 0
int main()
{
	int n;
	printf("************************************************\n");
	printf("1. 原始文件读取\n");
	printf("2. 按姓名排序并输出\n");
	printf("3. 按平均成绩排序并输出\n");
	printf("4. 输出给定学院学生\n");
	printf("5. 修改给定学生成绩信息\n");
	printf("6. 按姓名查询学生并输出\n");
	printf("7. 修改系统密码\n");
	printf("8. 结束系统\n");
    printf("************************************************\n");
    scanf("%d",&n);
    switch (n)
    {
    	case 1:inputStu(stu,5,"data\\Stu_Info3.txt");break;
	}
	return 0; 
 } 
