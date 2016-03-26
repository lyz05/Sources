#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits><F11>
#include <cmath>
using namespace std;

const int aimax = 1000010;

int s[100010],d[100010][21][3],d0[100010][3],a[aimax][5];
bool b[aimax];
int ans1,ans2,n,tt,s0;

int ss(){
	s0 = 0;
	memset(s,0,sizeof(s));
	memset(b,1,sizeof(b));
	for (int i = 2; i <= aimax; i++){
		if (b[i]){
			s0++;
			s[s0] = i;
		}
		for (int j = 1; j <= s0; j++){
			if (s[j] * i > aimax) break;
			b[s[j] * i] = 0;
			if (i % s[j] == 0) break;
		}
	}

	return 0;
}

int update_a(int x, int ii, int p,int num){
	int t1 = d0[x][2] - num, t2 = x, t;
	if (a[p][1] > t1){
		t = a[p][1]; a[p][1] = t1; t1 = t;
		t = a[p][2]; a[p][2] = t2; t2 = t;
	}
	if ((a[p][3] > t1) || ((a[p][3] == t1) && (a[p][4] > t2))){
		a[p][3] = t1; a[p][4] = t2;
	}

	return 0;
}

int answer(int x, int p, int num){
	int t1 = 0, t2 = 0;
	if ((a[p][2] != tt) && (a[p][2] != x)) {
		t1 = a[p][1] + d0[x][2] - num;
		t2 = a[p][2];
	}
	else if ((a[p][2] == x) && (a[p][4] != tt)) {
		t1 = a[p][3] + d0[x][2] - num;
		t2 = a[p][4];
	}
	if ((t2 != 0) && ((t1 < ans1) || ((t1 == ans1) && (t2 < ans2)))){
		ans1 = t1;
		ans2 = t2;
	}
	
	return 0;
}

int dfs(int x, int ii, int p, int num, int ty){
	if (ii > d0[x][1]){
		if (ty == 1) update_a(x,ii,p,num);
		else answer(x,p,num);
		
		return 0;
	}
	int t = 1;
	for (int i = 0; i <= d[x][ii][2]; i++) {
		dfs(x,ii + 1,p * t,num + i,ty);
		t = t * d[x][ii][1];
	}
	
	return 0;
}

int half(int i, int x){
	int l = 1, r = s0;
	int mid = 0;
	while (l <= r){
		mid = (l + r) / 2;
		if (s[mid] <= x) l = mid + 1;
		else r = mid - 1;
	}
	d0[i][1]++;
	d0[i][2]++;
	d[i][d0[i][1]][1] = s[r];
	d[i][d0[i][1]][2] = 1;
	
	return 0;
}

int main(){
	
	ss();
	scanf("%d",&n);
	memset(d0,0,sizeof(d0));
	int t;
	for (int i = 1; i <= n; i++){
		scanf("%d",&t);
		int tt = t;
		int j = 1;
		bool bb;
		while (t != 1){
			bb = 0;
			if (s[j] > floor(sqrt(tt))) break;
			if (t % s[j] == 0){
				d0[i][1]++;
				d[i][d0[i][1]][1] = s[j];
				d[i][d0[i][1]][2] = 0;
				bb = 1;
			}
			while (t % s[j] == 0) {
				t = t / s[j];
				d[i][d0[i][1]][2]++;
			}
			if (bb) d0[i][2] += d[i][d0[i][1]][2];
			j++;
		}
		if (t != 1) half(i,t);
	}
	
	memset(a,60,sizeof(a));
	tt = a[1][1];
	for (int i = 1; i <= n; i++) {
		dfs(i,1,1,0,1);
	}
	
	for (int i = 1; i <= n; i++){
		ans1 = INT_MAX;
		ans2 = 0;
		dfs(i,1,1,0,2);
		printf("%d\n",ans2);
	}
	
	return 0;
}
