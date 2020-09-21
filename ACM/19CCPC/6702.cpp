#include <cstdio>
#include <algorithm>
#include <iostream>

typedef long long LL;
using namespace std;
int T;

int main() {
    int T;
    cin >> T;
    while (T--) {
        LL A, B;
        cin >> A >> B;
        LL C = A & B;
        if (C == 0) printf("1\n");
        else cout << C << endl;
    }
    return 0;
}