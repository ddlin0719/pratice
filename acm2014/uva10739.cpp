#include <stdio.h>
#include <string.h>
char str[1111];
int f[1001][1001];
int min(int a,int b){
	if (a>b) return b;
	return a;
}
int dp(int a,int b){
	if (f[a][b]!=-1) return f[a][b];
	if (a==b||a-1==b) return f[a][b]=0;
	if (str[a]==str[b]){
		f[a][b]=dp(a+1,b-1);
	}else{
		f[a][b]=dp(a,b-1);					//添加
		f[a][b]=min(f[a][b],dp(a+1,b));		//添加
		f[a][b]=min(f[a][b],dp(a+1,b-1));	//删除或更改
		f[a][b]++;
	}
	return f[a][b]; 
}
int main(){
	int T,i;
	scanf("%d%*c",&T);
	for (i=1;i<=T;i++){
		gets(str);
		memset(f,-1,sizeof(f));
		printf("Case %d: ",i);
		printf("%d\n",dp(0,strlen(str)-1));
	}
	return 0;
}