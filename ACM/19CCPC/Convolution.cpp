#include <iostream>
#include <cstring>
#include <map>
#include <cstdio>

const int N = 50+5;
int T;
using namespace std;
int A[N][N],C[2][N][N],K[4][4];


int main() {
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);

    cin >> T;
    while (T --)
    {
        memset(C,0,sizeof C);
        int n,KK = 0;
        cin >> n;
        for (int i=1;i<=n;i ++)
            for (int j=1;j<=n;j ++)
                cin >> A[i][j];

        for (int i=1;i<=3;i ++)
            for (int j=1;j<=3;j ++) {
                cin >> K[i][j];
                KK += K[i][j];
            }

        for (int x=1;x<=n;x ++)
            for (int y=1;y<=n;y ++) {
                for (int i=1;i<=min(n-x+1,3);i ++)
                    for (int j=1;j<=min(n-y+1,3);j ++)
                        C[0][x][y] += A[x+i-1][y+j-1]*(K[i][j]/KK);
            }
        for (int k=1;;k=k^1){
            bool flag = 1;
            for (int x=1;x<=n;x ++)
                for (int y=1;y<=n;y ++) {
                    if (C[0][x][y]!=C[1][x][y]) {
                        flag = 0;
                    }
                }
            if (flag) break;
            for (int x=1;x<=n;x ++)
                for (int y=1;y<=n;y ++) {
                    for (int i=1;i<=min(n-x+1,3);i ++)
                        for (int j=1;j<=min(n-y+1,3);j ++)
                            C[k^1][x][y] += C[k][x+i-1][y+j-1]*(K[i][j]/KK);
                }
        }
        for (int x=1;x<=n;x ++) {
            for (int y = 1; y < n; y++) {
                cout << C[0][x][y] << " ";
            }
            cout << C[0][x][n] << endl;
        }
    }



    return 0;
}
