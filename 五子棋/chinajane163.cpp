#include <vector>
#include <utility>

int max_noalphabeta(int depth,int i1,int i2);//�ֵ������߲�ʱ����������ѡ�� 
int min_noalphabeta(int depth,int i1,int i2);//�ֵ����߲�ʱ��������ѡ�� 
void generatepoint(vector< pair<int,int> > &v);//������������ 
int scoretable(int number,int empty1);//���ֱ� 
int countscore(vector<int> n,int turn);	//�㵥������� 
bool hasne(int x,int y);//��Χ�Ƿ����Ӵ��ڣ����ӵľͼӿ��� 
 
bool hasne(int x,int y)//����ֻ���Ա����ӵ�
{
	int i,j;
	for(i=(x-3>0?x-3:0);i<=x+3&&i<16;++i)
		for(j=(y-3>0?y-3:0);j<=y+3&&j<16;++j)
			if(i!=0||j!=0)
				if(pos[i][j]!=0)
					return true;
	return false;
} 
void generatepoint(vector< pair<int,int> > &v)//������������		
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
//���ճ���100000������10000������1000�����100����һ10������1000������100������10�Ĺ��� 
//�������ϵ��������Ӵ�֣�֮��Ϊ���Եĵ�����÷�scorecomputer��Ȼ�����ҵ�����ͬ����֣�֮��Ϊscorehumber
//scoreComputer-scorehumber��Ϊ��ǰ���Ƶ��ܷ��� 
int scoretable(int number,int empty1)//�Ʒְ�
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
int countscore(vector<int> n,int turn)//��б�ߡ���б�ߡ��ᡢ������ת��һά���������� 
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
int evaluate_minmax_noalphabeta()//������������������
{
	int scorecomputer=0;
	int scorehumber=0;
	//������ 
	for(int i=0;i<16;++i)
	{
		vector<int> n;
		for(int j=0;j<16;++j)
			n.push_back(pos[i][j]);
		scorecomputer+=countscore(n,2);
		scorehumber+=countscore(n,1);
		n.clear();
	}
	//������
	for(int j=0;j<16;++j)
	{
		vector<int> n;
		for(int i=0;i<16;++i)
			n.push_back(pos[i][j]);
		scorecomputer+=countscore(n,2);
		scorehumber+=countscore(n,1);
		n.clear();
	} 
	//�ϰ���б���� 
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
	//�°���б����
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
	//�ϰ뷴б����
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
	//�°뷴б����
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
int min_noalphabeta(int depth,int i1,int i2)//�������ʱ													//��min���ˣ��߲�ʱ���˵������� 
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
		if(tmp<best)	best=tmp;//�������ʱѡ���������Լ��ľ��棬���Ƴ٣�Ҷ�ӽڵ�����ѡ��󣬲��������	
		pos[v[i].first][v[i].second]=0;
	} 
	return best;
}
int max_noalphabeta(int depth,int i1,int i2)													//��max�����ԣ��߲�ʱ��max�����ԣ�Ӧ�ÿ�����õ���� 
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
		if(tmp>best)	best=tmp;//��������ʱ��ѡ�����������Լ��ľ��棬���Ƴ�	
		pos[v[i].first][v[i].second]=0;
	} 
	return best;
}
void Chess::chess_ai_minmax_noalphabeta(int &x,int &y,int depth)//����Сֵ�㷨����n��������Ž� 
{
	vector< pair<int,int> > v;
	generatepoint(v);
	int best=INT_MIN;
	int len=v.size();
	vector< pair<int,int> > v2; 
	for(int i=0;i<len;++i)
	{
		pos[v[i].first][v[i].second]=2;	//ѡ���ӣ��������ðף���ֹ����ݹ�ʱ���ٵݹ鵽 
		int tmp=min_noalphabeta(depth-1,v[i].first,v[i].second);
		if(tmp==best)
			v2.push_back(v[i]);
		if(tmp>best)
		{
			best=tmp;
			v2.clear();
			v2.push_back(v[i]);
		}
		pos[v[i].first][v[i].second]=0;	//������֮�󣬸�����Ҫ�����ÿգ��ָ�ԭ�������� 
	}
	len=v2.size();
	int i=(int)(rand()%len);
	x=v2[i].first;
	y=v2[i].second; 
}