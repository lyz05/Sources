// Problem#: 1135
// Submission#: 1867544
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 100

struct node{
    int x,y,step,remain;
    node( int a, int b, int c,int r ){
        x = a; y = b; step = c; remain = r;
    }
};

bool _map[MAX][MAX];
bool visit[MAX][MAX][MAX];
int move[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int m,n,d;

inline bool judge( int a, int b ){
    return a>=0 && a<m && b>=0 && b<n;
}

void bfs( int m, int n, int d ){
    memset(visit,false,sizeof(visit));
    queue<node> buffer;
    buffer.push(node(0,0,0,d));
    visit[0][0][d] = true;
    while(!buffer.empty()){
        node tmp = buffer.front();
        buffer.pop();
        if( tmp.x == m-1 && tmp.y == n-1 ){
            cout << tmp.step << endl;
            return ;
        }
        int a,b;
        int c = tmp.step + 1;
        int r = tmp.remain;
        for( int i=0 ; i<4 ; i++ ){
            a = move[i][0] + tmp.x;
            b = move[i][1] + tmp.y;
            if( judge(a,b) && _map[a][b] && !visit[a][b][r] ){
                buffer.push(node(a,b,c,r));
                visit[a][b][r] = true;
            }
            for( int j=2 ; j<=r ; j++ ){
                a += move[i][0];
                b += move[i][1];
                if( judge(a,b) && _map[a][b] && !visit[a][b][r-j] ){
                    buffer.push(node(a,b,c,r-j));
                    visit[a][b][r-j] = true;
                }
            }
        }
    }
    cout << "impossible" << endl;
}

int main(){
    char c;
    cin >> m >> n >> d;
    memset(_map,false,sizeof(_map));
    for( int i=0 ; i<m ; i++ ){
        for( int j=0 ; j<n ; j++ ){
            cin >> c;
            if( c=='P' ) _map[i][j] = true;
        }
    }
    bfs(m,n,d);
    return 0;
}
