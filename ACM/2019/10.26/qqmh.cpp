#include<stdio.h>
#include<queue>
#include<string.h>
 //standard program
using namespace std;
deque<int> iq(10010);
int point[10010];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,i,z,m,first;
	char cmd;
	while(scanf("%d",&n)&&n){
		z=m=0;
		first=1;
		iq.clear();
		for(i=1;i<=n;i++){
			scanf("%d",&point[i]);
		}
		scanf("%c",&cmd);
		for(i=1;i<=2*n;i++){
			scanf("%c",&cmd);
			if(cmd=='m'){//addNumFromRight
				m++;
				while(!iq.empty()&&point[iq.back()]<= point[m]){
					iq.pop_back();
					
				}
				iq.push_back(m);
			}
			else{//removeNumFromLeft
				z++;
				if(z==iq.front()){
					iq.pop_front();
				}
			}
			if(first){
				first=0;
			}
			else{
				printf(" ");
			}
			printf("%d",z==m?0:point[iq.front()]);				
		}
		printf("\n");
		
	}
	return 0;
}
