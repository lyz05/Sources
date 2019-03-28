/*****************************
@ FileName : TestCreation
@ Author ��lyz05
@ email��294068487@qq.com
@ date��2019-01-19
@ version��0.1

******************************/
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <cstdlib> 
using namespace std;

const char EXECFILENAME[] = "TestCreation";
const char QUESTIONTYPE[3][10] = {"�ж���","ѡ����","������"};
const char VERSION[] = "0.1";

class random								//�����ȡһ������Ϊlen������
{
	private:
		vector <int> a;						//������е�����
		int getRandNum()					//��0~len-1���һ�����ظ������
		{
			int num = rand()%len;
			while (p[num]) num = (++ num)%len;
			p[num] = 1;
			return num;
		}
	public:
		vector <bool> p;					//���ÿ��������Ƿ����
		int len;							//�������еĳ���
		
		random(int len)
		{
			input(len);
		}
		random()
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
				a.push_back(getRandNum());
			}
			return a;
		}
};


class TOFProblem							//true or false question�ж���
{
	protected:

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
			this->content = "";
			this->selection = false;
			this->pid = 0;
		}
		void input(string content,bool correct,int pid)
		{
			this->content = content;
			this->selection = correct;
			this->pid = pid;
		}
		void inputFromTXT(stringstream &dataStream)
		{
			string line;
			for (int i=0;i<(int)strlen("��ţ�");i ++) 
			{
				if (dataStream.get()=='\n')
					i --;
			}
			dataStream >> pid;
			//��ȡ���
			while (!dataStream.eof())
			{
				getline(dataStream,line);
				if (line.find("�𰸣�") != string::npos) break;
				content += line;
				content += '\n';
			}
			//��ȡ����
			selection = (line.find("��ȷ") != string::npos);
			//��ȡѡ��״̬
		}
		void print(ofstream &outfile)
		{
			outfile << "��ţ�" << pid;
			outfile << content;
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
		bool lock;										//�������һ��ѡ��
		ChoiceProblem(string s,vector <TOFProblem> opt,int pid)
		{
			this->content = s;
			this->option = opt;
			this->pid = pid;
		}
		ChoiceProblem()
		{
			clear();
		}
		//���캯��
		void clear()
		{
			content = "";
			lock = 1;
			option.clear();
		}
		void inputFromTXT(stringstream &dataStream)
		{
			string line;
			for (int i=0;i<(int)strlen("��ţ�");i ++) 
			{
				if (dataStream.get()=='\n')
					i --;
			}
			//dataStream.getline(tmp,);
			dataStream >> pid;
			//cout << this->pid << endl;
			
			//��ȡ���
			
			while (!dataStream.eof())
			{
				getline(dataStream,line);
				if (line.find("��") == 1 || line.find(".") == 1)			//Ѱ��ѡ��λ�� 
				{
					TOFProblem problem;
					problem.input(line,0,0);
					option.push_back(problem);
					break;
				}
				
				//if (strstr(line,"�𰸣�")!=NULL) break;
				content += line;
				content += '\n';
			}
			
			//��ȡ����
			while (!dataStream.eof())
			{
				//dataStream >> line;
				getline(dataStream,line);
				string find = "�𰸣�";
				if (line.find(find) != string::npos) break;
				//if (strstr(line,"�𰸣�")!=NULL) break;
				TOFProblem problem;
				problem.input(line,0,0);
				option.push_back(problem);
			}
			//��ȡѡ��
			for (int i=0;i<(int)option.size();i ++)
			{
				for (int j=(int)strlen("�𰸣�");j<(int)line.size();j ++)
				{
					if (option[i].content[0]==line[j])
					{
						option[i].selection = 1;
					}
				}
			}
			//��ȡѡ��״̬
			
		}
		void print(ofstream &outfile)
		{
			string answer;
			outfile << "��ţ�" << pid;
			outfile << content;
			for (int i=0;i<(int)option.size();i ++)
			{
				outfile << option[i].content << endl;
				if (option[i].selection) answer += option[i].content[0];
				
			}
			outfile << "�𰸣�" << answer << endl;
		}
		void generate()												//�������ѡ��
		{
			int len = option.size();
			if (lock) len --;
			random rand(len);
			TOFProblem tmp;
			vector <int> a;
			a = rand.getRand();
			for (int i=0;i<len;i ++)
			{
				//int randNum = rand.getrand();
				tmp = option[i];
				option[i] = option[a[i]];
				option[a[i]] = tmp;
			}
			for (int i=0;i<len;i ++) option[i].content[0] = 'A'+i;	//�������
		}
};
class MatchProblem
{
	public:
		int pid;
		string content;
		vector <ChoiceProblem> option;
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
			this->pid = 0;
			this->content = "";
			this->option.clear();
		}
		void input(string content,vector <ChoiceProblem> opt,int pid)
		{
			this->pid = pid;
			this->content = content;
			this->option = opt;
		}
};
class Problems														//���
{
	protected:

	public:
		vector <TOFProblem> tofproblems;
		vector <ChoiceProblem> choiceproblems;

		void inputFromTXT(stringstream &srcDataStream,int type)		//׷�ӷ�ʽ����
		{
			string line;
			stringstream newDataStream;

			if (type==1)								//�ж���
			{
				//srcDataStream.str(torstream.str());
				//cout << dataStream.str() << endl;
				while (!srcDataStream.eof())
				{
					getline(srcDataStream,line);
					newDataStream << line << endl;
					if (srcDataStream.eof()) break;
					string find = "�𰸣�";
					if (line.find(find) != string::npos)
					{
						TOFProblem question;
						question.inputFromTXT(newDataStream);
						tofproblems.push_back(question);
						newDataStream.str("");
					}
				}
			}
			if (type==2)								//ѡ����
			{
				//srcDataStream.str(choicestream.str());
				//cout << dataStream.str() << endl;
				while (!srcDataStream.eof())
				{
					getline(srcDataStream,line);
					newDataStream << line << endl;
					if (srcDataStream.eof()) break;
					string find = "�𰸣�";
					if (line.find(find) != string::npos)
					{
						ChoiceProblem question;
						//cout << newDataStream.str() << endl;
						question.inputFromTXT(newDataStream);
						choiceproblems.push_back(question);
						newDataStream.str("");
						//question.print();
					}
				}
			}
			//cout << "size:" << questions.size() << endl;
		}
		void clear()
		{
			tofproblems.clear();
			choiceproblems.clear();
		}
		Problems()
		{
			clear();
		}
		void print(ofstream &outfile)
		{
			int len;
			len = tofproblems.size();
			if (len) outfile << "�ж��⣺" << endl;
			for (int i=0;i<len;i ++)
			{
				tofproblems[i].print(outfile);
				outfile << endl << endl;
			}
			len = choiceproblems.size();
			if (len) outfile << "ѡ���⣺" << endl;
			for (int i=0;i<len;i ++)
			{
				choiceproblems[i].print(outfile);
				outfile << endl << endl;
			}
		}
		bool generate(Problems &src,int TOFnum,int Choicenum)				//�����������
		{
			clear();
			random rand;
			vector <int> a;
			
			if (TOFnum>(int)src.tofproblems.size()) return 0;				//������Ŀ�����������
			rand.input(src.tofproblems.size());
			a = rand.getRand();
			for (int i=0;i<TOFnum;i ++)										//�����Ŀ����(���ظ�)
			{
				//int randNum = rand.getrand();
				tofproblems.push_back(src.tofproblems[a[i]]);
			}
			//�ж���
			if (Choicenum>(int)src.choiceproblems.size()) return 0;				//������Ŀ�����������	
			rand.input(src.choiceproblems.size());
			a = rand.getRand();
			for (int i=0;i<Choicenum;i ++)										//�����Ŀ����(���ظ�)
			{
				//int randNum = rand.getrand();
				ChoiceProblem problem = src.choiceproblems[a[i]];
				problem.generate();
				choiceproblems.push_back(problem);
			}
			//ѡ����
			return 1;
		}
};

Problems test,newtest;															//����⣬�������

int eoq(string s)																//End of questions 1�ж���2ѡ����3������
{
	for (int i=0;i<3;i ++)
		if (s.find(QUESTIONTYPE[i]) != string::npos) 
			return i+1;
	return 0;
}

void inputInfo(char *filename)
{
	//cout << filename << endl;
	ifstream infile(filename);
	stringstream dataStream;
	string line = "";
	if (!infile.is_open())
	{
		cout << "���ļ�" << filename << "ʧ��" << endl;
		exit(0);
	}
	cout << "���ڴ�" << filename << "�ж�ȡ��Ŀ" << endl;
	infile.seekg(infile.beg);
	while (!infile.eof())
	{
		for(;
			!eoq(line) && !infile.eof();
			getline(infile,line));
		//�ҵ�ĳһ���Ϳ�ͷ
		int type = eoq(line);				//��¼��ǰ��Ŀ����
		dataStream.str("");
		dataStream.clear();
		do 
		{
				getline(infile,line);
				if (!eoq(line))
					dataStream << line << endl;
		} while (!infile.eof() && !eoq(line));
		//���������͵���dataStream
		if (type==1)
		{
			//cout << dataStream.str() << endl;
			test.inputFromTXT(dataStream,type);
		}
		if (type==2)
		{
			//cout << dataStream.str() << endl;
			test.inputFromTXT(dataStream,type);
		}
	}
	infile.close();
	cout << "�ɹ�����" << test.tofproblems.size() << "���ж���" << endl;
	cout << "�ɹ�����" << test.choiceproblems.size() << "��ѡ����" << endl;
}

void outputInfo(char *filename)
{
	ofstream outfile(filename);
	if (!outfile.is_open())
	{
		cout << "���ļ�" << filename << "ʧ��" << endl;
		exit(0);
	}
	int num[3];
	cout << "��ֱ���������ɵģ��ж��⣬ѡ���⣬�����⣩��Ŀ����:" << endl;
	for (int i=0;i<3;i ++) cin >> num[i];
	newtest.generate(test,num[0],num[1]);
	newtest.print(outfile);
	cout << "������ļ�" << filename;
	outfile.good()?cout << "�ɹ�":cout << "ʧ��";
	cout << endl;
	outfile.close();
}

void help()
{
	cout << "�÷���" << EXECFILENAME << " [help] [input \"filename1\" output \"filename2\"] [version]" << endl;
	cout << endl;
	cout << "û�в���:\t\t\t\t��ʾ����" << endl;
	cout << "[help]\t\t\t\t\t��ʾ����,���벻�����κ�ѡ����һ����" << endl;
	cout << "[input \"filename1\" output \"filename2\"]\t��filename1�ж������⣬���������⵽filename2,�����ʽ�����\"�����ʽ.md\""<<endl;
	cout << "[version]\t\t\t\t���س���汾��Ϣ" << endl;
}

void version()
{
	cout << EXECFILENAME << " " << VERSION << endl;
}

int main(int argc,char *argv[])
{
	//for (int i=0;i<argc;i ++) cout << argv[i] << endl;
	if (argc==1) 
	{
		help();
		return 0;
	}
	if (argc==2)
	{
		if (strcmp(argv[1],"help") == 0)
		{
			help();
			return 0;
		}
		if (strcmp(argv[1],"version") == 0)
		{
			version();
			return 0;
		}
	}
	if (argc==5)
	{
		if (strcmp(argv[1],"input") == 0 && strcmp(argv[3],"output") == 0)
		{
			inputInfo(argv[2]);
			outputInfo(argv[4]);
		}
	}

	return 0;
}
