//TL
#include<stdio.h>
#include<string.h>
#define INF 1<<10
int n,num[256],sum[256][256],f[256][256];
int min(int a,int b){
	if (a>b) return b;
	return a;
}
int dp(int a,int b){
	int i;
	if (f[a][b]<INF) return f[a][b];
	if (a==b||a-1==b) return f[a][b]=0;
	for (i=a;i<=b;i++)
		f[a][b]=min(f[a][b],dp(a,i-1)+dp(i+1,b)+sum[a][b]-num[i]);
	return f[a][b];
}
int main(){
	int i,j;
	while (~scanf("%d",&n)){
		for (i=0;i<n;i++) scanf("%d",&num[i]);
		memset(f,333,sizeof(f));
		memset(sum,0,sizeof(sum));
		for (i=0;i<n;i++)
			for (j=i;j<n;j++) sum[i][j]=sum[i][j-1]+num[j];
		printf("%d\n",dp(0,n-1));
	}
	return 0;
}
