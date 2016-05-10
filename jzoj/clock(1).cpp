#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
    
    clock_t t1, t2;
    t1 = clock();
    system("PAUSE");
    t2 = clock();
    cout << (double)(t2-t1)/CLOCKS_PER_SEC << endl;
    return 0;
}
