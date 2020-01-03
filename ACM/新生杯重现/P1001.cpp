#include<stdio.h>
#include<string.h>
const int N = 1000+5;
int main()
{
    //freopen("0.in","r",stdin);freopen("0.out","w",stdout);
    char s1[N],s2[N];
    int s3[N];
    int T,Case;
    scanf("%d",&T);
    for (Case=1;Case<=T;Case ++)
    {
        memset(s3,0,sizeof s3);
        scanf("%s %s",s1,s2);
        printf("Case %d:\n",Case);
        printf("%s + %s = ",s1,s2);
        int i,j,k,now,next = 0;
        for (i=strlen(s1)-1,j=strlen(s2)-1,k=0;i>=0 || j>=0;i--,j--,k++)
        {
            if (i<0) now = s2[j]-'0';
            else if (j<0) now = s1[i]-'0';
            else now = s1[i]-'0'+s2[j]-'0';
            now += next;
            s3[k] = now%10;
            next = now/10;
        }
        if (next) s3[k] = next; else k--;
        for (;k>=0;k--) printf("%d",s3[k]);
        if (Case!=T) printf("\n\n"); else printf("\n");
    }
    return 0;
} 
// 12
// 1234