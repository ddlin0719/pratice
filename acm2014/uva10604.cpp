#include <stdio.h>
#include <string.h>
#define INF 1<<30
int val[7][7],des[7][7],tot[7],n,m;
int dp[11][11][11][11][11][11],vis[11][11][11][11][11][11];
int min(int a,int b){
	if (a>b) return b;
	return a;
}
int dfs(int a,int b,int c,int d,int e,int f){
	int &res=dp[a][b][c][d][e][f];
	int &flag=vis[a][b][c][d][e][f];
	int i,j,tmp;
	if (flag) return res;
	flag=1;
	res=INF;
	for (i=1;i<=6;i++)
		for (j=1;j<=6;j++)
			if (i!=j&&tot[i]>0&&tot[j]>0||i==j&&tot[i]>=2){
				tot[i]--,tot[j]--,tot[des[i][j]]++;
				res=min(res,dfs(tot[1],tot[2],tot[3],tot[4],tot[5],tot[6])+val[i][j]);
//				tmp=dfs(tot[1],tot[2],tot[3],tot[4],tot[5],tot[6]);
//				if (tmp!=INF) res=min(res,tmp+val[i][j]);
				tot[i]++,tot[j]++,tot[des[i][j]]--;
			}
	//剩下一个化学物质, 说明合成结束了 
	if (res==INF) res=0;
	return res;
}
int main(){
	int i,j,T;
	char str[1111];
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				scanf("%d%d",&des[i][j],&val[i][j]);
		scanf("%d",&m);
		memset(tot,0,sizeof(tot));
		for (i=0;i<m;i++) scanf("%d",&j),tot[j]++;
		memset(vis,0,sizeof(vis));
		dp[0][0][0][0][0][0]=0,vis[0][0][0][0][0][0]=1;
		printf("%d\n",dfs(tot[1],tot[2],tot[3],tot[4],tot[5],tot[6]));
		gets(str);gets(str);
	}
	return 0;
}
