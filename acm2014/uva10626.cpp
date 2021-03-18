#include <stdio.h>
#include <string.h>
int f[505+303][105+155][55];
int min(int a,int b){
	if (a>b) return b;
	return a;
}
int dp(int n,int n1,int n5,int n10){
	int &ans=f[n1][n5][n10];
	if (n==0) return ans=0;
	if (ans!=-1) return ans;
	ans=1<<30;
	if (n1>=8) ans=min(ans,dp(n-1,n1-8,n5,n10)+8);
	if (n5>=2) ans=min(ans,dp(n-1,n1+2,n5-2,n10)+2);
	if (n10>=1) ans=min(ans,dp(n-1,n1+2,n5,n10-1)+1);
	if (n1>=3&&n5>=1) ans=min(ans,dp(n-1,n1-3,n5-1,n10)+4);
	if (n1>=3&&n10>=1) ans=min(ans,dp(n-1,n1-3,n5+1,n10-1)+4);
	return ans;
}
int main(){
	int T, n,n1,n5,n10;
	scanf("%d",&T);
	while (T--){
		memset(f,-1,sizeof(f));
		scanf("%d%d%d%d",&n,&n1,&n5,&n10);
		printf("%d\n",dp(n,n1,n5,n10));
	}
	return 0;
}
