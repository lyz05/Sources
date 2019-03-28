/*****************************
@ FileName : TestCreation
@ Author ：lyz05
@ email：294068487@qq.com
@ date：2019-02-27 
@ version：0.2 
@ problem： 
class		每个单词首字母大写
function	首单词首字母小写，其余单词首字母大写，第一个单词为动词
variable	单词全小写 
constant	单词所有字母大写 
******************************/
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib> 
#define GEN 1
using namespace std;

const char EXECFILENAME[] = "TestCreation";
const char QUESTIONTYPE[3][10] = {"判断题","选择题","连线题"};

class Random								//随机获取一个长度为len的排列
{
	private:
		vector <bool> p;					//标记每个随机数是否出现
		int len;							//整个排列的长度
		vector <int> a;						//存放排列的数组
		int getRandNum()					//从0~len-1获得一个不重复随机数
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
				if (GEN) a.push_back(getRandNum()); else a.push_back(i);
			}
			return a;
		}
};


class TOFProblem							//true or false question判断题
{
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
			outfile << "题号：" << pid << endl;
			outfile << content.c_str() << endl;
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
		vector <int> optionorder;
		bool lock;										//锁定最后一个选项
		
		ChoiceProblem(string s,vector <TOFProblem> opt,int pid,bool lock)
		{
			input(s,opt,pid,lock);
		}
		ChoiceProblem()
		{
			clear();
		}
		//构造函数
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
			outfile << "题号：" << pid << endl;
			outfile << content.c_str() << endl;
			for (int i=0;i<(int)option.size();i ++)
			{
				outfile << (char)('A'+i) << '.'; 
				outfile << option[optionorder[i]].content.c_str() << endl;
				if (option[optionorder[i]].selection) 
					answer += (char)('A'+i);
				
			}
			outfile << "答案：" << answer.c_str() << endl;
		}
		void generate()												//随机生成选项
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
		//构造函数
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

			outfile << "题号：" << pid << endl;
			outfile << content.c_str() << endl;
			outfile << "概念A" << endl; 
			for (int i=0;i<(int)option.size();i ++)
			{
				outfile << i+1 << '.'; 
				outfile << option[optionorder[i]].content.c_str() << endl;
			}
			outfile << "概念B" << endl; 
			ChoiceProblem now = option[0];
			for (int i=0;i<(int)now.option.size();i ++)
			{
				outfile << (char)('A'+i) << '.'; 
				outfile << now.option[now.optionorder[i]].content.c_str() << endl;
			}
			outfile << "答案：" << endl;
			
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

class Problems														//题库
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
		bool generate()				//随机生成试题
		{
			Random rand;
			
			rand.input(tofproblems.size());
			toforder = rand.getRand();
			//判断题
			rand.input(choiceproblems.size());
			choiceorder = rand.getRand();
			//选择题
			rand.input(matchproblems.size());
			matchorder = rand.getRand();
			//连线题 
			/*
			for (int i=0;i<(int)toforder.size();i ++) 
				cout << toforder[i] << " ";
			*/
			return 1;
		}
};

Problems test;						//题库

void outputInfo(char *filename);

int main(int argc,char *argv[])		//测试用主函数 
{
	{
		test.tofproblems.push_back(TOFProblem("continue语句对于while和do-while循环来说,意味着转去计算While表达式.",1,12661));
		test.tofproblems.push_back(TOFProblem("条件表达式x?'a':'b'中,若x=0时,表达式的值为b.",1,12670));
		test.tofproblems.push_back(TOFProblem("while循环至少执行一次.",0,12679));
		test.tofproblems.push_back(TOFProblem("循环体如果包含一个以上的语句,应该用圆括号括起来,以复合语句形式出现.",1,12672));
		test.tofproblems.push_back(TOFProblem("已知a=3,b=4,c=5.则逻辑表达式a+b>c && b==c值为0.",1,12673));
	}
	//TOF
	{
		vector <TOFProblem> option;
		{
			option.push_back(TOFProblem("可为任何量或表达式",0,11448));
			option.push_back(TOFProblem("只能为常量或常量表达式",1,11448));
			option.push_back(TOFProblem("可为常量或表达式或有确定值的变量及表达式",0,11448));
			option.push_back(TOFProblem("只能为常量",0,11448));
		}
		test.choiceproblems.push_back(ChoiceProblem("C语言的switch语句中,case 后().",option,11448,0));
		
		option.clear();
		{
			option.push_back(TOFProblem("15",1,11462));
			option.push_back(TOFProblem("10",0,11462));	
			option.push_back(TOFProblem("28",1,11462));
			option.push_back(TOFProblem("9",0,11462));
		}
		test.choiceproblems.push_back(ChoiceProblem("执行下面程序段后,f的值是:()\nint f=5;\nswitch(f)\n{case 5:f+=1;\ncase 6:f--;\ncase 7:f *=3;break;\ncase 8:++f;\n}"
,option,11462,1));
		
	}
	//Choice
	{
		vector <ChoiceProblem> matchoption;
		{
			ChoiceProblem p;			
			vector <TOFProblem> option;
			{				
				option.push_back(TOFProblem("放出光合热",0,20001));
				option.push_back(TOFProblem("在河里游泳",0,20001));
				option.push_back(TOFProblem("很暖和",0,20001));
				option.push_back(TOFProblem("挂在天空中",0,20001));
				option.push_back(TOFProblem("要洗洗手",0,20001));
			}
			p.input("今天的天气",option,20001,0);
			p.option[2].selection = 1;
			matchoption.push_back(p);
			p.input( "天上的太阳",option,20001,0);
			p.option[0].selection = 1;
			matchoption.push_back(p);
			p.input("可爱的鸭子",option,20001,0);
			p.option[1].selection = 1;
			matchoption.push_back(p);
			p.input("我们在饭前",option,20001,0);
			p.option[4].selection = 1;
			matchoption.push_back(p);
			p.input("圆圆的月亮",option,20001,0);
			p.option[3].selection = 1;
			matchoption.push_back(p);
		}
		test.matchproblems.push_back(MatchProblem("这是一道小学语文句子连线题",matchoption,20001));
		
		matchoption.clear();
		{
			ChoiceProblem p;			
			vector <TOFProblem> option;
			{
				option.push_back(TOFProblem("整数",0,20002));
				option.push_back(TOFProblem("实数",0,20002));
				option.push_back(TOFProblem("正数",0,20002));
				option.push_back(TOFProblem("负数",0,20002));
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
		test.matchproblems.push_back(MatchProblem("这是一道简单的分类题目",matchoption,20002));
	}
	//Match
	outputInfo((char *) "newTest.txt");
	return 0;
}

void outputInfo(char *filename)				//将结果输出到文件 
{
	ofstream outfile(filename);
	if (!outfile.is_open())
	{
		cout << "打开文件" << filename << "失败" << endl;
		exit(0);
	}
	test.print(outfile);
	cout << "输出到文件" << filename;
	outfile.good()?cout << "成功":cout << "失败";
	cout << endl;
	outfile.close();
}
