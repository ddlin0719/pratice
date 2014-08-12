#include <stdio.h>
#include <string.h>
#define INF 1e9
int f[111][111],visit[111][111];
int sum[111],num[111],n;
int min(int a,int b){
	if (a>b) return b;
	return a;
}
int dp(int l,int r){
	if (visit[l][r]) return f[l][r];
	if (l==r){
		visit[l][r]=1;
		return f[l][r]=num[l];
	}
	int ans=0,i;
	//mid[l][r]=l;
	for (i=l;i<r;i++) 
		if (dp(l,i)<ans){
			ans=dp(l,i);
			//mid[l][r]=i;
		}
	for (i=l+1;i<=r;i++)
		if (dp(i,r)<ans){
			ans=dp(i,r);
			//mid[l][r]=i;
		}
	visit[l][r]=1;
	return f[l][r]=sum[r]-sum[l-1]-ans;
}
int main(){
	int i,j;
	while (scanf("%d",&n),n){
		memset(visit,0,sizeof(visit));
		for (i=0;i<n;i++) scanf("%d",&num[i]);
		sum[0]=num[0];
		for (i=1;i<n;i++) sum[i]=sum[i-1]+num[i];
		printf("%d\n",dp(0,n-1)*2-sum[n-1]);
		for (i=0;i<4;i++){
			for (j=0;j<4;j++) printf("%3d ",f[i][j]);
			printf("\n");
		}
	}
	return 0;
}
