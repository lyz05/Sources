#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int price[100];
int x[400], y[400];
#define swap(a, b) {int t; t = a; a = b; b = t;}
double dis[400][400];
 
double getdis(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
 
void deal(void)
{
    int i, j, k;
    int s, t, a, b, l;
    int tx[4], ty[4];
    int d[3];
    double ans = 10000000;
    scanf("%d%d%d%d", &s, &t, &a, &b);
    for(i = 0; i < 4 * s; i++){
        for(j = 0; j < 4 * s; j++){
            dis[i][j] = 1000000;
        }
    }
    for(i = 0; i < s; i++){
        scanf("%d%d%d%d%d%d%d", &tx[0], &ty[0], &tx[1], &ty[1], &tx[2], &ty[2], &l);
        d[0] = (tx[0] - tx[1]) * (tx[0] - tx[1]) + (ty[0] - ty[1]) * (ty[0] - ty[1]);
        d[1] = (tx[2] - tx[0]) * (tx[2] - tx[0]) + (ty[2] - ty[0]) * (ty[2] - ty[0]);
        d[2] = (tx[2] - tx[1]) * (tx[2] - tx[1]) + (ty[2] - ty[1]) * (ty[2] - ty[1]);
        if(d[0] == d[1] + d[2]){
            swap(tx[0], tx[2]);
            swap(ty[0], ty[2]);
        }else if(d[1] == d[0] + d[2]){
            swap(tx[0], tx[1]);
            swap(ty[0], ty[1]);
        }
        tx[3] = tx[1] + tx[2] - tx[0];
        ty[3] = ty[1] + ty[2] - ty[0];
        for(j = 0; j < 4; j++){
            x[4 * i + j] = tx[j];
            y[4 * i + j] = ty[j];
        }
        for(j = 0; j < 4; j++){
            for(k = j; k < 4; k++){
                dis[4 * i + k][4 * i + j] = dis[4 * i + j][4 * i + k] = getdis(tx[j], ty[j], tx[k], ty[k]) * l;
            }
        }
        for(j = 0; j < i; j++){
            for(k = 0; k < 4; k++){
                for(l = 0; l < 4; l++){
                    dis[4 * j + k][4 * i + l] = getdis(x[4 * j + k], y[4 * j + k], tx[l], ty[l]) * t;
                    dis[4 * i + l][4 * j + k] = dis[4 * j + k][4 * i + l];
                }
            }
        }
    }
    for(k = 0; k < 4 * s; k++){
        for(i = 0; i < 4 * s; i++){
            for(j = i + 1; j < 4 * s; j++){
                if(dis[i][j] > dis[i][k] + dis[k][j]){
                    dis[j][i] = dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(ans > dis[4 * (a - 1) + i][4 * (b - 1) + j]){
                ans = dis[4 * (a - 1) + i][4 * (b - 1) + j];
            }
        }
    }
    printf("%.2lf\n", ans);
}
 
int main(int argc, char **argv)
{
	freopen("11190.in","r",stdin);
    //int n;
    //scanf("%d", &n);
    //while(n--){
        deal();
    
    return 0;
}
