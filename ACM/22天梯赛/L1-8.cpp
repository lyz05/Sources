#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
struct Node{
    int score,PAT;
    bool flag;
} a[N];
int tot=0,ans=0;

void print() {
    cout << endl;
    for (int i=0;i<tot;i ++){
        cout << a[i].score << " "<< a[i].PAT << endl;
    }
}

bool cmp(Node A,Node B) {
    return A.score<B.score;
}

void work(){
    for (int i=0;i<tot;i ++) {
        if(!a[i].flag) {
            a[i].flag = 1
            ans ++;
        }
    }
}

int main() {
    int n,k,s;
    cin >> n >> k >> s;
    for (int i=0;i<n;i ++) {
        int score,PAT;
        cin >> score >> PAT;
        if (score>=175){
            a[tot].score = score;
            a[tot].PAT = PAT;
            tot ++;
        }
    }
    sort(a,a+tot,cmp);
    work();
    print();
    return 0;
}