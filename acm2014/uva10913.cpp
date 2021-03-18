#include <stdio.h>
#include <string.h>
#define INF -200000000000
//#define INF (1<<18)
int dx[3]={0,0,1},dy[3]={-1,1,0};
int map[77][77],vis[77][77],n,s;
long long ans,f[77][77][7][3];
long long max(long long a,long long b){
	if (a>b) return a;
	return b;
}
void dp(int r,int c,int ss,long long sum){
	int rr,cc,i;
	if (ss>s) return ;
	if (r==n-1&&c==n-1){
		ans=max(sum,ans);
		return ;
	}
	for (i=0;i<3;i++){
		rr=r+dx[i],cc=c+dy[i];
		if (rr>=n||rr<0||cc>=n||cc<0||vis[rr][cc]) continue;
		vis[rr][cc]=1;
		if (f[rr][cc][ss+1][i]<sum+map[rr][cc]&&map[rr][cc]<0){
			f[rr][cc][ss+1][i]=sum+map[rr][cc];
			dp(rr,cc,ss+1,sum+map[rr][cc]);
		}
		if (f[rr][cc][ss][i]<sum+map[rr][cc]&&map[rr][cc]>=0){
			f[rr][cc][ss][i]=sum+map[rr][cc];
			dp(rr,cc,ss,sum+map[rr][cc]);
		}
		vis[rr][cc]=0;
	}
}
int main(){
	int i,j,k,h,T=0;
	memset(map,0,sizeof(map));
	long long x=INF;
	printf("%lld\n",x);
	while (scanf("%d%d",&n,&s),n|s){
		for (i=0;i<n;i++)
			for (j=0;j<n;j++) scanf("%d",&map[i][j]);
		
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				for (k=0;k<7;k++)
					for (h=0;h<3;h++) f[i][j][k][h]=INF;
		memset(vis,0,sizeof(vis));
		ans=INF;
		vis[0][0]=1;
		if (map[0][0]>=0) dp(0,0,0,map[0][0]);
		else dp(0,0,1,map[0][0]);
		
		printf("Case %d: ",++T);
		if (ans!=INF) printf("%lld\n",ans);else printf("impossible\n");
	}
	return 0;
}
