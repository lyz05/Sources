#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstring>
using namespace std;


const int N = 1024;

struct Node
{
	int x,y;
} src[N];
vector < vector<int> > ans;
vector <int> tmp;
int vis[N];
bool cmp(Node A,Node B)
{
	return A.y < B.y;
}

void dfs(int dep,int n,int sum)
{
	if (sum<0) return;
	if (sum==0)
	{
		ans.push_back(tmp);
		//for (int i=0;i<tmp.size();i ++) cout << tmp[i] << " ";
		//cout << endl; 
	}
	int m;
	for (m=0;m<n && src[m].y<=sum;m ++);
	
	for (int i=0;i<m;i ++)
	{
		if (vis[i] || (dep-2>=0 && tmp[dep-2]>src[i].x)) continue;
		vis[i] = 1;
		if ((int)tmp.size()<dep) tmp.push_back(src[i].x);
		else tmp[dep-1] = src[i].x;
			dfs(dep+1,n,sum-src[i].y);
		vis[i] = 0;
		tmp[dep-1] = 0;
	}
}

void randomSelect(int sum, int result[], int source[][2])
{
	srand(time(NULL));
	int n;
	for (n=0;source[n][0]!=0;n ++)
	{
		src[n].x = source[n][0];
		src[n].y = source[n][1];
	}
	
	sort(src,src+n,cmp);
	dfs(1,n,sum);
	
	if (ans.size()!=0)
	{
		int i;
		int randNum = rand()%ans.size();
		for (i=0;i<(int)ans[randNum].size() && ans[randNum][i]!=0;i ++)
			result[i] = ans[randNum][i];
		result[i] = 0;
	}
}


int main()
{
	
	int result[N];
	//int src[][2] = {{1,1},{2,2},{3,2},{4,3},{5,3},{6,1},{7,5},{8,6},{9,8},{10,12},{11,1},{12,2},{13,2},{14,3},{15,3},{16,1},{17,1},{18,2},{19,4},{20,3},{0,0}};
	int src[][2] = {{1,1},{2,2},{3,2},{4,3},{5,3},{6,1},{7,1},{8,2},{9,4},{10,3},{0,0}};
	
	randomSelect(6,result,src);
	
	for (int i=0;result[i]!=0;i ++) cout << result[i] << " ";
	/* 
	for (int i=0;i<(int)ans.size();i ++)
	{
		//cout <<ans[i].size();
		for (int j=0;j<(int)ans[i].size() && ans[i][j]!=0;j ++) cout << ans[i][j] << " ";
		cout << endl;
	}
	*/ 
	return 0;
} 
