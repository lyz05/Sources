#include<cstdio>
using namespace std;

int main()
{
    char str[] = "Tencent";
    const char *ch=str;
    printf("%d\n%d\n",sizeof(str),sizeof(ch));
    return 0;
}