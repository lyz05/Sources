#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;
int n,sum;
struct node{
        char English[100],Chinese[100];
}f[10000];
char a;
bool jian(int x,int y){
    for (int i=0;i<100;i++)
        if (f[x].English[i]!=f[y].English[i])return(false);
    return(true);
}
int main(){
        FILE* fp;
        fp=fopen("words.txt","r");
        fscanf(fp,"%d",&n);
        for (int i=1;i<=n;i++)
            fscanf(fp," %s %[^\n]",&f[i].English,&f[i].Chinese);
        fclose(fp);
        printf("Please set in the words:\n");
        scanf(" %s",&f[n+1].English);
        while (f[n+1].English[0]!='.'){
                n++;
                scanf(" %s",&f[n].Chinese);
                for (int i=1;i<n;i++)
                    if (jian(i,n)){
                        printf("There is the same word.\n");
                        printf("%s %s\n",&f[i].English,&f[i].Chinese);
                        printf("Please set in the Chinese means combined:\n");
                        scanf(" %s",&f[i].Chinese);
                        n--;
                        break;
                    }
                printf("OK!\n");
                printf("Please set in the words:\n");
                scanf(" %s",&f[n+1].English);
        }
        fp=fopen("words.txt","w");
        fprintf(fp,"%d\n",n);
        for (int i=1;i<=n;i++)
                fprintf(fp,"%s %s\n",f[i].English,f[i].Chinese);
        return 0;
}
