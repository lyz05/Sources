#include<cstdio>
#include<cstring>
using namespace std;
const char keyStr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
int map[1<<8+5];

char* encodeInp(char *input)
{
	static char output[100]="";
	int chr1,chr2,chr3;
	int enc1,enc2,enc3,enc4;
	int i=0,tot = 0;
	do{
		chr1 = input[i++];
		chr2 = input[i++];
		chr3 = input[i++];
		enc1 = chr1 >> 2;
		enc2 = ((chr1 & 3) << 4) | (chr2 >> 4);
		enc3 = ((chr2 & 15) << 2) | (chr3 >> 6);
		enc4 = chr3 & 63;
		if(chr2==0)
		{
			enc3 = enc4 = 64;
		} else if (chr3==0)
		{
			enc4 = 64;
		}
		output[tot ++]=keyStr[enc1];
		output[tot ++]=keyStr[enc2];
		output[tot ++]=keyStr[enc3];
		output[tot ++]=keyStr[enc4];
		
		chr1 = chr2 = chr3 = 0;
		enc1 = enc2 = enc3 = enc4 = 0;
		
	}while (i < strlen(input));
	return output;
}

//180021104890
//MTgwMDIxMTA0ODkw

char* decodeInp(char *input)
{
	for (int i=0;i<strlen(keyStr);i ++) map[keyStr[i]]=i;
	static char output[100]="";
	int enc1,enc2,enc3,enc4;
	int chr1,chr2,chr3;
	int i=0,tot=0;
	do
	{
		enc1 = map[input[i ++]],enc2 = map[input[i ++]],enc3 = map[input[i ++]],enc4 = map[input[i ++]];
		chr1 = (enc1<<2) | ((enc2>>4)&3);
		chr2 = ((enc2&15)<<4)|(enc3>>2);
		chr3 = ((enc3&3)<<6)|(enc4&63);
		
		if (enc3==enc4 && enc4==64)
			chr2=0;
		if (enc4==64)
			chr3=0;
		output[tot ++]=chr1;
		output[tot ++]=chr2;
		output[tot ++]=chr3;
		
		chr1 = chr2 = chr3 = 0;
		enc1 = enc2 = enc3 = enc4 = 0;
	} while (i < strlen(input));
	return output;
}

int main()
{
	int *pi = new int[10];
	int val; const int *pi = new int(val);
	char xh[100],*encode,*decode,res[100]="encoded=";
	scanf("%s",xh);
	encode = encodeInp(xh);
	strcat(res,encode);
	strcat(res,"%25%25%25");
	scanf("%s",xh);
	encode = encodeInp(xh);
	strcat(res,encode);
	printf("%s\n",res);
	//decode = decodeInp(xh);
	//printf("%s\n",encode);
	//printf("%s\n",decode);
}
