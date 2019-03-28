/*****************************
@ FileName : TestCreation
@ Author ：lyz05
@ email：294068487@qq.com
@ date：2019-01-19
@ version：0.1

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
const char QUESTIONTYPE[3][10] = {"判断题","选择题","连线题"};
const char VERSION[] = "0.1";

class random								//随机获取一个长度为len的排列
{
	private:
		vector <int> a;						//存放排列的数组
		int getRandNum()					//从0~len-1获得一个不重复随机数
		{
			int num = rand()%len;
			while (p[num]) num = (++ num)%len;
			p[num] = 1;
			return num;
		}
	public:
		vector <bool> p;					//标记每个随机数是否出现
		int len;							//整个排列的长度
		
		random(int len)
		{
			input(len);
		}
		random()
		{
			clear();
		}
		//构造函数
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
		
		vector <int> getRand()				//返回一个随机排列
		{
			a.clear();
			for (int i=0;i<len;i ++)
			{
				a.push_back(getRandNum());
			}
			return a;
		}
};


class TOFProblem							//true or false question判断题
{
	protected:

	public:
		bool selection;						//选择状态
		string content;						//题面
		int pid;							//Problem ID
		TOFProblem(string content,bool correct,int pid)
		{
			input(content,correct,pid);
		}
		TOFProblem()
		{
			clear();
		}
		//构造函数
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
			for (int i=0;i<(int)strlen("题号：");i ++) 
			{
				if (dataStream.get()=='\n')
					i --;
			}
			dataStream >> pid;
			//提取题号
			while (!dataStream.eof())
			{
				getline(dataStream,line);
				if (line.find("答案：") != string::npos) break;
				content += line;
				content += '\n';
			}
			//提取题面
			selection = (line.find("正确") != string::npos);
			//提取选择状态
		}
		void print(ofstream &outfile)
		{
			outfile << "题号：" << pid;
			outfile << content;
			outfile << "答案：";
			if (selection) outfile << "正确"; else outfile << "错误";
			outfile << endl;
		}
};
class ChoiceProblem										//选择题
{
	public:
		int pid;
		string content;									//题面
		vector <TOFProblem> option;						//选择题选项
		bool lock;										//锁定最后一个选项
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
		//构造函数
		void clear()
		{
			content = "";
			lock = 1;
			option.clear();
		}
		void inputFromTXT(stringstream &dataStream)
		{
			string line;
			for (int i=0;i<(int)strlen("题号：");i ++) 
			{
				if (dataStream.get()=='\n')
					i --;
			}
			//dataStream.getline(tmp,);
			dataStream >> pid;
			//cout << this->pid << endl;
			
			//提取题号
			
			while (!dataStream.eof())
			{
				getline(dataStream,line);
				if (line.find("、") == 1 || line.find(".") == 1)			//寻找选项位置 
				{
					TOFProblem problem;
					problem.input(line,0,0);
					option.push_back(problem);
					break;
				}
				
				//if (strstr(line,"答案：")!=NULL) break;
				content += line;
				content += '\n';
			}
			
			//提取题面
			while (!dataStream.eof())
			{
				//dataStream >> line;
				getline(dataStream,line);
				string find = "答案：";
				if (line.find(find) != string::npos) break;
				//if (strstr(line,"答案：")!=NULL) break;
				TOFProblem problem;
				problem.input(line,0,0);
				option.push_back(problem);
			}
			//提取选项
			for (int i=0;i<(int)option.size();i ++)
			{
				for (int j=(int)strlen("答案：");j<(int)line.size();j ++)
				{
					if (option[i].content[0]==line[j])
					{
						option[i].selection = 1;
					}
				}
			}
			//提取选择状态
			
		}
		void print(ofstream &outfile)
		{
			string answer;
			outfile << "题号：" << pid;
			outfile << content;
			for (int i=0;i<(int)option.size();i ++)
			{
				outfile << option[i].content << endl;
				if (option[i].selection) answer += option[i].content[0];
				
			}
			outfile << "答案：" << answer << endl;
		}
		void generate()												//随机生成选项
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
			for (int i=0;i<len;i ++) option[i].content[0] = 'A'+i;	//更换编号
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
		//构造函数
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
class Problems														//题库
{
	protected:

	public:
		vector <TOFProblem> tofproblems;
		vector <ChoiceProblem> choiceproblems;

		void inputFromTXT(stringstream &srcDataStream,int type)		//追加方式输入
		{
			string line;
			stringstream newDataStream;

			if (type==1)								//判断题
			{
				//srcDataStream.str(torstream.str());
				//cout << dataStream.str() << endl;
				while (!srcDataStream.eof())
				{
					getline(srcDataStream,line);
					newDataStream << line << endl;
					if (srcDataStream.eof()) break;
					string find = "答案：";
					if (line.find(find) != string::npos)
					{
						TOFProblem question;
						question.inputFromTXT(newDataStream);
						tofproblems.push_back(question);
						newDataStream.str("");
					}
				}
			}
			if (type==2)								//选择题
			{
				//srcDataStream.str(choicestream.str());
				//cout << dataStream.str() << endl;
				while (!srcDataStream.eof())
				{
					getline(srcDataStream,line);
					newDataStream << line << endl;
					if (srcDataStream.eof()) break;
					string find = "答案：";
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
			if (len) outfile << "判断题：" << endl;
			for (int i=0;i<len;i ++)
			{
				tofproblems[i].print(outfile);
				outfile << endl << endl;
			}
			len = choiceproblems.size();
			if (len) outfile << "选择题：" << endl;
			for (int i=0;i<len;i ++)
			{
				choiceproblems[i].print(outfile);
				outfile << endl << endl;
			}
		}
		bool generate(Problems &src,int TOFnum,int Choicenum)				//随机生成试题
		{
			clear();
			random rand;
			vector <int> a;
			
			if (TOFnum>(int)src.tofproblems.size()) return 0;				//出题题目超过题库数量
			rand.input(src.tofproblems.size());
			a = rand.getRand();
			for (int i=0;i<TOFnum;i ++)										//随机题目生成(不重复)
			{
				//int randNum = rand.getrand();
				tofproblems.push_back(src.tofproblems[a[i]]);
			}
			//判断题
			if (Choicenum>(int)src.choiceproblems.size()) return 0;				//出题题目超过题库数量	
			rand.input(src.choiceproblems.size());
			a = rand.getRand();
			for (int i=0;i<Choicenum;i ++)										//随机题目生成(不重复)
			{
				//int randNum = rand.getrand();
				ChoiceProblem problem = src.choiceproblems[a[i]];
				problem.generate();
				choiceproblems.push_back(problem);
			}
			//选择题
			return 1;
		}
};

Problems test,newtest;															//根题库，生成题库

int eoq(string s)																//End of questions 1判断题2选择题3连线题
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
		cout << "打开文件" << filename << "失败" << endl;
		exit(0);
	}
	cout << "正在从" << filename << "中读取题目" << endl;
	infile.seekg(infile.beg);
	while (!infile.eof())
	{
		for(;
			!eoq(line) && !infile.eof();
			getline(infile,line));
		//找到某一题型开头
		int type = eoq(line);				//记录当前题目类型
		dataStream.str("");
		dataStream.clear();
		do 
		{
				getline(infile,line);
				if (!eoq(line))
					dataStream << line << endl;
		} while (!infile.eof() && !eoq(line));
		//将整个提型导入dataStream
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
	cout << "成功读入" << test.tofproblems.size() << "道判断题" << endl;
	cout << "成功读入" << test.choiceproblems.size() << "道选择题" << endl;
}

void outputInfo(char *filename)
{
	ofstream outfile(filename);
	if (!outfile.is_open())
	{
		cout << "打开文件" << filename << "失败" << endl;
		exit(0);
	}
	int num[3];
	cout << "请分别输入待生成的（判断题，选择题，连线题）题目个数:" << endl;
	for (int i=0;i<3;i ++) cin >> num[i];
	newtest.generate(test,num[0],num[1]);
	newtest.print(outfile);
	cout << "输出到文件" << filename;
	outfile.good()?cout << "成功":cout << "失败";
	cout << endl;
	outfile.close();
}

void help()
{
	cout << "用法：" << EXECFILENAME << " [help] [input \"filename1\" output \"filename2\"] [version]" << endl;
	cout << endl;
	cout << "没有参数:\t\t\t\t显示帮助" << endl;
	cout << "[help]\t\t\t\t\t显示帮助,这与不键入任何选项是一样的" << endl;
	cout << "[input \"filename1\" output \"filename2\"]\t从filename1中读入试题，并生成试题到filename2,试题格式请参照\"试题格式.md\""<<endl;
	cout << "[version]\t\t\t\t返回程序版本信息" << endl;
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
