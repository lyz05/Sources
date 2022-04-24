#include<stdio.h>
#include<string.h>
/**
 * Note: 类名、方法名、参数名已经指定，请勿修改
 *
 * 
 * 
 * @param s string字符串  
 * @return string字符串
 */

int judge(char *s,int st,int length){
    int i,j;
    for (i=st,j=st+length-1;i<j;i++,j--)
    {
        if (s[i]!=s[j]) return 0;
    }
    return 1;
}

char ans[100];
char* longestPalindrome(char* s) {
    // write code here
    int length,i;
    s[0]='a';
    for (length=strlen(s);length>=0;length --)
    {
        for (i=0;i+length<=strlen(s);i ++) {
            if (judge(s,i,length)) {
                int k;
                for (k=i;k<i+length;k ++){
                    ans[k-i] = s[k];
                }
                return ans;
            }
        }
    }
        // for length in range(len(s),-1,-1):
        //     for i in range(0,len(s)-length):
        //         if judge(s[i:i+length+1]):
        //             return s[i:i+length+1]
    return "";
}

int main(){
    char* n;
    n = longestPalindrome("abcbacdcabba");
    printf("%s\n",n);
    return 0;
}