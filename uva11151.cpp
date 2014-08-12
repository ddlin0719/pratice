#include <stdio.h>
#include <string.h>
char str[1010];
int f[1010][1010];
int max(int a,int b){
	if (a<b) return b;
	return a;
}
int dp(int a,int b){
	if (f[a][b]) return f[a][b];
	if (a>b) return f[a][b]=0;
	if (a==b) return f[a][b]=1;
	if (str[a]==str[b]) f[a][b]=dp(a+1,b-1)+2;
	else f[a][b]=max(dp(a,b-1),dp(a+1,b));
	return f[a][b];
}
int main(){
	int T,i,j;
	scanf("%d%*c",&T);
	while (T--){
		memset(f,0,sizeof(f));
		//又在这里被坑了....
		//scanf("%s",str);
		gets(str);
		printf("%d\n",dp(0,strlen(str)-1));
	}
	return 0;
}