/**
 * 此文件包含主程序所用到各同学所写的所有函数头 
 */

//yrf
void menu1();
void menu3();
int inputStu(STU stu[], int *num, char filename[]);    
//从文件名filename读num个学生信息到数组stu，并同时计算平均成绩,成功返回真，失败返回假 
int inputCinfo(Cinfo x[], int *num, char filename[]);   
//从文件名filename读num个学院信息到数组x,成功返回真，失败返回假
int inputSinfo(Sinfo x[], int *num, char filename[]);
//从文件名filename读num个性别信息到数组x,成功返回真，失败返回假
void sortStudents(STU *s, int *para, int num,CompareMethod cm);
//对num个学生按照指定比较方式排序
int sortByAve(STU x, STU y);
//根据平均成绩排序

//hyh
void menu2();
void menu6();
int sortByName(STU x, STU y);
//根据姓名排序
int findName(STU x[], int num, char name[], STU re[]); 
//根据给定的name，从num个x中找出同名，并依次存放到re中，函数返回找到的人数

//lyz
void menu5();
void menu7();
int ModifyStuinfo(STU x[], int num, int id, char filename[]);
//根据给定的学生学号修改该学生的信息
int JudgePsd(char psd[],char filename[]);
//判断密码正确性
int ModifyPsd(char psd[],char filename[]);
//修改密码，返回修改是否成功
char* encodeInp(char *input);
//对密码进行加密 

//xhn
void menu4();
void menu8();								//菜单显示
void menu0();
