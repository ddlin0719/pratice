#include <stdio.h>
#include <string.h>
char path[2012],str[1010];
int sum[1010][1010];
int dp(int a,int b){
	if (sum[a][b]!=-1) return sum[a][b];
	if (a>=b){
		sum[a][b]=0;
		return 0;
	}
	if (str[a]==str[b])
		sum[a][b]=dp(a+1,b-1);
	else{
		int tmp1=dp(a+1,b)+1;
		int tmp2=dp(a,b-1)+1;
		if (tmp1<tmp2)	sum[a][b]=tmp1;
		else	sum[a][b]=tmp2;
	}
	return sum[a][b];
}
void print(int a,int b){
	if (a>b) return;
	if (a==b){
		putchar(str[a]);
		return;
	}
	if (str[a]==str[b]){
		putchar(str[a]);
		print(a+1,b-1);
		putchar(str[b]);
	}
	else{
		if (sum[a][b-1]<sum[a+1][b]){
			putchar(str[b]);
			print(a,b-1);
			putchar(str[b]);
		}
		else{
			putchar(str[a]);
			print(a+1,b);
			putchar(str[a]);
		}
	}
}
int main(){
	while (gets(str)){
		memset(sum,-1,sizeof(sum));
		int len=strlen(str);	
		printf("%d ",dp(0,len-1));
		//路径输出这里很经典
		print(0,len-1);
		putchar(10);
	}
	return 0;
}