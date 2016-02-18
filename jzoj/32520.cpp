#include <vector>
#include <fstream> 
#include <iostream>
 
using namespace std;
ifstream fin("3252.in");
ofstream fout("3252.out");

vector<string> f;
int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
 
int D[55][55], V[55][55], Q[55][55];
 
void doit(int x, int y, int pd)
{
  if (!(x >= 0  && y >= 0 && x < n && y < m) || f[x][y] == '#')
  {
    D[x + 1][y + 1] = V[x + 1][y + 1] = 0;
    Q[x + 1][y + 1] = 100000000;
    return;
  }
  D[x + 1][y + 1] = Q[x + 1][y + 1] = 1;
  V[x + 1][y + 1] = 0;
  //D[x],Q[x]所属子树已经炸完,Q[x]中x放炸弹,V[x]中所属父亲链未炸完,其他炸完
  int dd[3], qq[3], vv[3];
 
  for (int i = 0; i <= 2; ++ i)
  {
    int dir = (i + pd + 1) % 4;
    int xx = x + dx[dir];
    int yy = y + dy[dir];
    doit(xx, yy, (2 + dir) % 4);
    dd[i] = D[xx + 1][yy + 1];
    vv[i] = V[xx + 1][yy + 1];
    qq[i] = Q[xx + 1][yy + 1];
  }
  
  int hor = min(dd[0] + dd[2], min(vv[0] + qq[2], vv[2] + qq[0]));
  
  D[1 + x][1 + y] = min(min(vv[0] + qq[2] + dd[1], 1 + vv[0] + vv[1] + vv[2]), min(vv[2] + qq[0] + dd[1], dd[0] + dd[2] + qq[1]));
  Q[x + 1][y + 1] = min(1 + vv[0] + vv[1] + vv[2], hor + qq[1]);
  V[x + 1][y + 1] = hor + vv[1];
}
 
int main() 
{
  fin>>n>>m;
  for(int i = 1; i <= n; i++)
  {
      string s;
      fin>>s;
      f.push_back(s);
  }

  for (int i = 0; i < n; ++ i)
  {
    for (int j = 0; j < m; ++ j)
    {
      if (f[i][j] == '.')
      {
        doit(i, j, 1);
        cout<<D[i + 1][j + 1]<<endl;
        return 0;
      }
    }
  }
  return 0;
}
