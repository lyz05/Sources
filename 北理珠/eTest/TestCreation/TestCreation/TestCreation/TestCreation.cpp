/*****************************
@ FileName : TestCreation
@ Author ��lyz05
@ email��294068487@qq.com
@ date��2019-02-27 
@ version��0.2 
@ problem�� 
class		ÿ����������ĸ��д
function	�׵�������ĸСд�����൥������ĸ��д����һ������Ϊ����
variable	����ȫСд 
constant	����������ĸ��д 
******************************/
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib> 
#define GEN 1
using namespace std;

const char EXECFILENAME[] = "TestCreation";
const char QUESTIONTYPE[3][10] = {"�ж���","ѡ����","������"};

class Random								//�����ȡһ������Ϊlen������
{
	private:
		vector <bool> p;					//���ÿ��������Ƿ����
		int len;							//�������еĳ���
		vector <int> a;						//������е�����
		int getRandNum()					//��0~len-1���һ�����ظ������
		{
			int num = rand()%len;
			while (p[num]) num ++,num %= len;
			p[num] = 1;
			return num;
		}
	public:
		
		Random(int len)
		{
			input(len);
		}
		Random()
		{
			clear();
		}
		//���캯��
		void clear()
		{
			srand((unsigned int)time(NULL));
			p.clear();
			len = 0;
		}
		void input(int len)
		{
			this -> len = len;
			this -> p.clear();
			this -> p.resize(len,0);
		}
		
		vector <int> getRand()				//����һ���������
		{
			a.clear();
			for (int i=0;i<len;i ++)
			{
				if (GEN) a.push_back(getRandNum()); else a.push_back(i);
			}
			return a;
		}
};


class TOFProblem							//true or false question�ж���
{
	public:
		bool selection;						//ѡ��״̬
		string content;						//����
		int pid;							//Problem ID
		TOFProblem(string content,bool correct,int pid)
		{
			input(content,correct,pid);
		}
		TOFProblem()
		{
			clear();
		}
		//���캯��
		void clear()
		{
			content = "";
			selection = false;
			pid = 0;
		}
		void input(string content,bool correct,int pid)
		{
			clear();
			this->content = content;
			this->selection = correct;
			this->pid = pid;
		}
		void print(ofstream &outfile)
		{
			outfile << "��ţ�" << pid << endl;
			outfile << content.c_str() << endl;
			outfile << "�𰸣�";
			if (selection) outfile << "��ȷ"; else outfile << "����";
			outfile << endl;
		}
};
class ChoiceProblem										//ѡ����
{
	public:
		int pid;
		string content;									//����
		vector <TOFProblem> option;						//ѡ����ѡ��
		vector <int> optionorder;
		bool lock;										//�������һ��ѡ��
		
		ChoiceProblem(string s,vector <TOFProblem> opt,int pid,bool lock)
		{
			input(s,opt,pid,lock);
		}
		ChoiceProblem()
		{
			clear();
		}
		//���캯��
		void input(string s,vector <TOFProblem> opt,int pid,bool lock)
		{
			clear();
			this->content = s;
			this->option = opt;
			this->pid = pid;
			this->lock = lock;
		}
		void clear()
		{
			content = "";
			lock = 0;
			option.clear();
			optionorder.clear();
		}
		void print(ofstream &outfile)
		{
			generate();
			
			string answer;
			outfile << "��ţ�" << pid << endl;
			outfile << content.c_str() << endl;
			for (int i=0;i<(int)option.size();i ++)
			{
				outfile << (char)('A'+i) << '.'; 
				outfile << option[optionorder[i]].content.c_str() << endl;
				if (option[optionorder[i]].selection) 
					answer += (char)('A'+i);
				
			}
			outfile << "�𰸣�" << answer.c_str() << endl;
		}
		void generate()												//�������ѡ��
		{
			Random rand;
			
			if (!lock) rand.input(option.size());
			else rand.input(option.size()-1);
			optionorder = rand.getRand();
			if (lock) optionorder.push_back(option.size()-1);
		}
};

class MatchProblem
{
	public:
		int pid;
		string content;
		vector <ChoiceProblem> option;
		vector <int> optionorder;
		
		MatchProblem()
		{
			clear();
		}
		MatchProblem(string content,vector <ChoiceProblem> opt,int pid)
		{
			input(content,opt,pid);
		}
		//���캯��
		void clear()
		{
			pid = 0;
			content = "";
			option.clear();
			optionorder.clear();
		}
		void input(string content,vector <ChoiceProblem> opt,int pid)
		{
			this->pid = pid;
			this->content = content;
			this->option = opt;
		}
		void print(ofstream &outfile)
		{
			generate();

			outfile << "��ţ�" << pid << endl;
			outfile << content.c_str() << endl;
			outfile << "����A" << endl; 
			for (int i=0;i<(int)option.size();i ++)
			{
				outfile << i+1 << '.'; 
				outfile << option[optionorder[i]].content.c_str() << endl;
			}
			outfile << "����B" << endl; 
			ChoiceProblem now = option[0];
			for (int i=0;i<(int)now.option.size();i ++)
			{
				outfile << (char)('A'+i) << '.'; 
				outfile << now.option[now.optionorder[i]].content.c_str() << endl;
			}
			outfile << "�𰸣�" << endl;
			
			for (int i=0;i<(int)option.size();i ++)
			{
				ChoiceProblem now = option[optionorder[i]];
				string answer = "";
				for (int j=0;j<(int)now.option.size();j ++)
				{ 
					if (now.option[now.optionorder[j]].selection) 
						answer += (char)('A'+j);
				}
				outfile << i+1 << '.' << answer.c_str() << endl;
			}
			
		}
		void generate()
		{
			Random rand;
			rand.input(option.size());
			optionorder = rand.getRand();
			option[0].generate();
			for (int i=1;i<(int)option.size();i ++)
				option[i].optionorder = option[0].optionorder;
		}
};

class Problems														//���
{
	public:
		vector <TOFProblem> tofproblems;
		vector <ChoiceProblem> choiceproblems;
		vector <MatchProblem> matchproblems;
		vector <int> toforder,choiceorder,matchorder;
		
		void clear()
		{
			tofproblems.clear();
			choiceproblems.clear();
			toforder.clear();
			choiceorder.clear();
		}
		Problems()
		{
			clear();
		}
		void print(ofstream &outfile)
		{
			generate();
			int len;
			len = tofproblems.size();
			if (len) outfile << QUESTIONTYPE[0] << endl;
			for (int i=0;i<len;i ++)
			{
				tofproblems[toforder[i]].print(outfile);
				outfile << endl << endl;
			}
			// 
			len = choiceproblems.size();
			if (len) outfile << QUESTIONTYPE[1] << endl;
			for (int i=0;i<len;i ++)
			{
				choiceproblems[choiceorder[i]].print(outfile);
				outfile << endl << endl;
			}
			//
			len = matchproblems.size();
			if (len) outfile << QUESTIONTYPE[2] << endl;
			for (int i=0;i<len;i ++)
			{
				matchproblems[matchorder[i]].print(outfile);
				outfile << endl << endl;
			}	
		}
		bool generate()				//�����������
		{
			Random rand;
			
			rand.input(tofproblems.size());
			toforder = rand.getRand();
			//�ж���
			rand.input(choiceproblems.size());
			choiceorder = rand.getRand();
			//ѡ����
			rand.input(matchproblems.size());
			matchorder = rand.getRand();
			//������ 
			/*
			for (int i=0;i<(int)toforder.size();i ++) 
				cout << toforder[i] << " ";
			*/
			return 1;
		}
};

Problems test;						//���

void outputInfo(char *filename);

int main(int argc,char *argv[])		//������������ 
{
	{
		test.tofproblems.push_back(TOFProblem("continue������while��do-whileѭ����˵,��ζ��תȥ����While���ʽ.",1,12661));
		test.tofproblems.push_back(TOFProblem("�������ʽx?'a':'b'��,��x=0ʱ,���ʽ��ֵΪb.",1,12670));
		test.tofproblems.push_back(TOFProblem("whileѭ������ִ��һ��.",0,12679));
		test.tofproblems.push_back(TOFProblem("ѭ�����������һ�����ϵ����,Ӧ����Բ����������,�Ը��������ʽ����.",1,12672));
		test.tofproblems.push_back(TOFProblem("��֪a=3,b=4,c=5.���߼����ʽa+b>c && b==cֵΪ0.",1,12673));
	}
	//TOF
	{
		vector <TOFProblem> option;
		{
			option.push_back(TOFProblem("��Ϊ�κ�������ʽ",0,11448));
			option.push_back(TOFProblem("ֻ��Ϊ�����������ʽ",1,11448));
			option.push_back(TOFProblem("��Ϊ��������ʽ����ȷ��ֵ�ı��������ʽ",0,11448));
			option.push_back(TOFProblem("ֻ��Ϊ����",0,11448));
		}
		test.choiceproblems.push_back(ChoiceProblem("C���Ե�switch�����,case ��().",option,11448,0));
		
		option.clear();
		{
			option.push_back(TOFProblem("15",1,11462));
			option.push_back(TOFProblem("10",0,11462));	
			option.push_back(TOFProblem("28",1,11462));
			option.push_back(TOFProblem("9",0,11462));
		}
		test.choiceproblems.push_back(ChoiceProblem("ִ���������κ�,f��ֵ��:()\nint f=5;\nswitch(f)\n{case 5:f+=1;\ncase 6:f--;\ncase 7:f *=3;break;\ncase 8:++f;\n}"
,option,11462,1));
		
	}
	//Choice
	{
		vector <ChoiceProblem> matchoption;
		{
			ChoiceProblem p;			
			vector <TOFProblem> option;
			{				
				option.push_back(TOFProblem("�ų������",0,20001));
				option.push_back(TOFProblem("�ں�����Ӿ",0,20001));
				option.push_back(TOFProblem("��ů��",0,20001));
				option.push_back(TOFProblem("���������",0,20001));
				option.push_back(TOFProblem("Ҫϴϴ��",0,20001));
			}
			p.input("���������",option,20001,0);
			p.option[2].selection = 1;
			matchoption.push_back(p);
			p.input( "���ϵ�̫��",option,20001,0);
			p.option[0].selection = 1;
			matchoption.push_back(p);
			p.input("�ɰ���Ѽ��",option,20001,0);
			p.option[1].selection = 1;
			matchoption.push_back(p);
			p.input("�����ڷ�ǰ",option,20001,0);
			p.option[4].selection = 1;
			matchoption.push_back(p);
			p.input("ԲԲ������",option,20001,0);
			p.option[3].selection = 1;
			matchoption.push_back(p);
		}
		test.matchproblems.push_back(MatchProblem("����һ��Сѧ���ľ���������",matchoption,20001));
		
		matchoption.clear();
		{
			ChoiceProblem p;			
			vector <TOFProblem> option;
			{
				option.push_back(TOFProblem("����",0,20002));
				option.push_back(TOFProblem("ʵ��",0,20002));
				option.push_back(TOFProblem("����",0,20002));
				option.push_back(TOFProblem("����",0,20002));
			}
			p.input("0",option,20002,0);
			p.option[0].selection = p.option[1].selection = 1;
			matchoption.push_back(p);
			p.input("1",option,20002,0);
			p.option[0].selection = p.option[1].selection = p.option[2].selection = 1;
			matchoption.push_back(p);
			p.input("-1",option,20002,0);
			p.option[0].selection = p.option[1].selection = p.option[3].selection= 1;
			matchoption.push_back(p);
			p.input("-13.12",option,20002,0);
			p.option[1].selection = p.option[3].selection = 1;
			matchoption.push_back(p);
			p.input("12345.12",option,20002,0);
			p.option[1].selection = p.option[2].selection = 1;
			matchoption.push_back(p);
			p.input("222",option,20002,0);
			p.option[0].selection = p.option[1].selection = p.option[2].selection = 1;
			matchoption.push_back(p);
		}
		test.matchproblems.push_back(MatchProblem("����һ���򵥵ķ�����Ŀ",matchoption,20002));
	}
	//Match
	outputInfo((char *) "newTest.txt");
	return 0;
}

void outputInfo(char *filename)				//�����������ļ� 
{
	ofstream outfile(filename);
	if (!outfile.is_open())
	{
		cout << "���ļ�" << filename << "ʧ��" << endl;
		exit(0);
	}
	test.print(outfile);
	cout << "������ļ�" << filename;
	outfile.good()?cout << "�ɹ�":cout << "ʧ��";
	cout << endl;
	outfile.close();
}
