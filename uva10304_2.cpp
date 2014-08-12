#include<stdio.h>
#include<string.h>
#define INF 1000000000
int n,num[256],sum[256][256],f[256][256];
int min(int a,int b){
	if (a>b) return b;
	return a;
}
int main(){
	int i,j,k;
	while (~scanf("%d",&n)){
		for (i=1;i<=n;i++) scanf("%d",&num[i]);
		for (i=1;i<=n;i++){
			sum[i][i]=num[i];
			for (j=i+1;j<=n;j++) sum[i][j]=sum[i][j-1]+num[j];
		}
		for (i=0;i<=n;i++)
			for (j=i+1;j<=n;j++) f[i][j]=INF;
		for (i=1;i<=n+1;i++) f[i][i-1]=f[i][i]=0;
		//大凡是记忆化搜索改递推,都是按长度递增来推
		for (k=0;k<n;k++)
			for (i=1;i+k<=n;i++)
				//for (j=i+1;j<=i+k;j++)
				for (j=i;j<=i+k;j++)
					//这个方程出错了几次,主要是细节不太熟悉
					f[i][i+k]=min(f[i][i+k],f[i][j-1]+f[j+1][i+k]+sum[i][i+k]-num[j]);
		printf("%d\n",f[1][n]);
	}
	return 0;
}
