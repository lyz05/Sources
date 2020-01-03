
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=102;
inline int aabs(int a){
    return a<0?-a:a;
}
int a[maxn],st,ed;
int main(){
	freopen("J.in","r",stdin);
    int loop;
    scanf("%d",&loop);
    while(loop--){
        int num,pos;
        scanf("%d %d",&num,&pos);
        for(int i=0;i<num;++i)scanf("%d",&a[i]);
        a[pos]=-a[pos];
        st=0;
        ed=num;
        int cns=0;
        while((ed+1)%maxn!=st){
            int k=a[st];
            st=(st+1)%maxn;
            bool flag=true;
           	for(int i=st;i!=ed;i=(i+1)%maxn)
                if(aabs(a[i])>aabs(k)){
                    flag=false;
                    a[ed]=k;
                    ed=(ed+1)%maxn;
                    break;
                }
            if(flag){
                    cns++;
                    if(k<0){
                        printf("%d\n",cns);
                        break;
                    }
        	}
        }
    }
    return 0;

}
