/**
 * ���ļ��������������õ���ͬѧ��д�����к���ͷ 
 */

//yrf
void menu1();
void menu3();
int inputStu(STU stu[], int *num, char filename[]);    
//���ļ���filename��num��ѧ����Ϣ������stu����ͬʱ����ƽ���ɼ�,�ɹ������棬ʧ�ܷ��ؼ� 
int inputCinfo(Cinfo x[], int *num, char filename[]);   
//���ļ���filename��num��ѧԺ��Ϣ������x,�ɹ������棬ʧ�ܷ��ؼ�
int inputSinfo(Sinfo x[], int *num, char filename[]);
//���ļ���filename��num���Ա���Ϣ������x,�ɹ������棬ʧ�ܷ��ؼ�
void sortStudents(STU *s, int *para, int num,CompareMethod cm);
//��num��ѧ������ָ���ȽϷ�ʽ����
int sortByAve(STU x, STU y);
//����ƽ���ɼ�����

//hyh
void menu2();
void menu6();
int sortByName(STU x, STU y);
//������������
int findName(STU x[], int num, char name[], STU re[]); 
//���ݸ�����name����num��x���ҳ�ͬ���������δ�ŵ�re�У����������ҵ�������

//lyz
void menu5();
void menu7();
int ModifyStuinfo(STU x[], int num, int id, char filename[]);
//���ݸ�����ѧ��ѧ���޸ĸ�ѧ������Ϣ
int JudgePsd(char psd[],char filename[]);
//�ж�������ȷ��
int ModifyPsd(char psd[],char filename[]);
//�޸����룬�����޸��Ƿ�ɹ�
char* encodeInp(char *input);
//��������м��� 

//xhn
void menu4();
void menu8();								//�˵���ʾ
void menu0();
