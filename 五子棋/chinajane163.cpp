#include <vector>
#include <utility>

int max_noalphabeta(int depth,int i1,int i2);//轮到电脑走步时，电脑作的选择 
int min_noalphabeta(int depth,int i1,int i2);//轮到人走步时，人作的选择 
void generatepoint(vector< pair<int,int> > &v);//产生空子序列 
int scoretable(int number,int empty1);//积分表 
int countscore(vector<int> n,int turn);	//算单个数组分 
bool hasne(int x,int y);//周围是否有子存在，无子的就加考虑 
 
bool hasne(int x,int y)//空子只算旁边有子的
{
	int i,j;
	for(i=(x-3>0?x-3:0);i<=x+3&&i<16;++i)
		for(j=(y-3>0?y-3:0);j<=y+3&&j<16;++j)
			if(i!=0||j!=0)
				if(pos[i][j]!=0)
					return true;
	return false;
} 
void generatepoint(vector< pair<int,int> > &v)//产生空子序列		
{
	for(int i=0;i<16;++i)
		for(int j=0;j<16;++j)
			if(pos[i][j]==0&&hasne(i,j))
			{
				pair<int,int> p;
				p.first=i;
				p.second=j;
				v.push_back(p);
			} 
}
//按照成五100000、活四10000、活三1000、活二100、活一10、死四1000、死三100、死二10的规则 
//给棋盘上的所有棋子打分，之和为电脑的单方面得分scorecomputer，然后对玩家的棋子同样打分，之和为scorehumber
//scoreComputer-scorehumber即为当前局势的总分数 
int scoretable(int number,int empty1)//计分板
{
	if(number>=5)	return 100000;
	else if(number==4)
	{
		if(empty1==2)	return 10000;
		else if(empty1==1)	return 1000;
	}
	else if(number==3)	
	{
		if(empty1==2)	return 1000;
		else if(empty1==1)	return 100;
	}
	else if(number==2)
	{
		if(empty1==2)	return 100;
		else if(empty1==1)	return 10;
	}
	else if(number==1&&empty1==2)	return 10;
	return 0;
}
int countscore(vector<int> n,int turn)//正斜线、反斜线、横、竖，均转成一维数组来计算 
{
	int scoretmp=0;
	int len=n.size();
	int empty1=0;
	int number=0;
	if(n[0]==0)	++empty1;
	else if(n[0]==turn)	++number;
	int i=1;
	while(i<len)
	{
		if(n[i]==turn)	++number;
		else if(n[i]==0)
		{
			if(number==0)	empty1=1;
			else
			{
				scoretmp+=scoretable(number,empty1+1);
				empty1=1;
				number=0;
			}
		}
		else
		{
			scoretmp+=scoretable(number,empty1);
			empty1=0;
			number=0;
		}
		++i;
	}
	scoretmp+=scoretable(number,empty1);
	return scoretmp;
}
int evaluate_minmax_noalphabeta()//评估函数，评估局势
{
	int scorecomputer=0;
	int scorehumber=0;
	//横排们 
	for(int i=0;i<16;++i)
	{
		vector<int> n;
		for(int j=0;j<16;++j)
			n.push_back(pos[i][j]);
		scorecomputer+=countscore(n,2);
		scorehumber+=countscore(n,1);
		n.clear();
	}
	//竖排们
	for(int j=0;j<16;++j)
	{
		vector<int> n;
		for(int i=0;i<16;++i)
			n.push_back(pos[i][j]);
		scorecomputer+=countscore(n,2);
		scorehumber+=countscore(n,1);
		n.clear();
	} 
	//上半正斜线们 
	for(int i=0;i<16;++i)
	{
		int x,y;
		vector<int> n;
		for(x=i,y=0;x<16&&y<16;++x,++y)
			n.push_back(pos[y][x]);
		scorecomputer+=countscore(n,2);
		scorehumber+=countscore(n,1);
		n.clear();
	} 
	//下半正斜线们
	for(int j=1;j<16;++j)
	{
		int x,y;
		vector<int> n;
		for(x=0,y=j;y<16&&x<16;++x,++y)
			n.push_back(pos[y][x]);
	 	scorecomputer+=countscore(n,2);
		scorehumber+=countscore(n,1);
		n.clear();
	} 
	//上半反斜线们
	for(int i=0;i<16;++i)
	{
		vector<int> n;
		int x,y;
		for(y=i,x=0;y>=0&&x<16;--y,++x)
			n.push_back(pos[y][x]);
		scorecomputer+=countscore(n,2);
		scorehumber+=countscore(n,1);
		n.clear();
	} 
	//下半反斜线们
	for(int j=1;j<16;++j)
	{
		vector<int> n;
		int x,y;
		for(y=j,x=15;y<16&&x>=0;++y,--x)
			n.push_back(pos[x][y]);
		scorecomputer+=countscore(n,2);
		scorehumber+=countscore(n,1);
		n.clear();
	} 
	return scorecomputer-scorehumber;
} 
int min_noalphabeta(int depth,int i1,int i2)//玩家落子时													//当min（人）走步时，人的最好情况 
{
	int res=evaluate_minmax_noalphabeta();
	Chess cc;
	cc.chess_isover(i1,i2,2);
	if(isover!=0||depth<=0)
	{
		isover=0;
		return res;
	}
	vector< pair<int,int> > v;
	generatepoint(v);
	int len=v.size();
	int best=INT_MAX;
	for(int i=0;i<len;++i)
	{
		pos[v[i].first][v[i].second]=1;
		int tmp=max_noalphabeta(depth-1,v[i].first,v[i].second);
		if(tmp<best)	best=tmp;//玩家落子时选择最有利自己的局面，将推迟，叶子节点做出选择后，层层往上推	
		pos[v[i].first][v[i].second]=0;
	} 
	return best;
}
int max_noalphabeta(int depth,int i1,int i2)													//当max（电脑）走步时，max（电脑）应该考虑最好的情况 
{
	int res=evaluate_minmax_noalphabeta();
	Chess cc;
	cc.chess_isover(i1,i2,1);
	if(isover!=0||depth<=0)
	{
		isover=0;
		return res;
	}
	vector< pair<int,int> > v;
	generatepoint(v);
	int len=v.size();
	int best=INT_MIN;
	for(int i=0;i<len;++i)
	{
		pos[v[i].first][v[i].second]=2;
		int tmp=min_noalphabeta(depth-1,v[i].first,v[i].second);
		if(tmp>best)	best=tmp;//电脑落子时，选择最有利于自己的局面，将推迟	
		pos[v[i].first][v[i].second]=0;
	} 
	return best;
}
void Chess::chess_ai_minmax_noalphabeta(int &x,int &y,int depth)//极大极小值算法搜索n步后的最优解 
{
	vector< pair<int,int> > v;
	generatepoint(v);
	int best=INT_MIN;
	int len=v.size();
	vector< pair<int,int> > v2; 
	for(int i=0;i<len;++i)
	{
		pos[v[i].first][v[i].second]=2;	//选该子，将该子置白，防止后面递归时，再递归到 
		int tmp=min_noalphabeta(depth-1,v[i].first,v[i].second);
		if(tmp==best)
			v2.push_back(v[i]);
		if(tmp>best)
		{
			best=tmp;
			v2.clear();
			v2.push_back(v[i]);
		}
		pos[v[i].first][v[i].second]=0;	//假设完之后，该子需要重新置空，恢复原来的样子 
	}
	len=v2.size();
	int i=(int)(rand()%len);
	x=v2[i].first;
	y=v2[i].second; 
}