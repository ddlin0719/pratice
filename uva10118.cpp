#include <stdio.h>
#include <string.h>
int n,f[44][44][44][44],head[4],in[22];
int pile[4][44];
int max(int a,int b){
	if (a>b) return a;
	return b;
}
int dp(int tot){
	int &ans=f[head[0]][head[1]][head[2]][head[3]];
	if (ans!=-1) return ans;
	if (tot==5) return ans=0;
	ans=0;
	int i;
	for (i=0;i<4;i++){
		if (head[i]>=n) continue;
		int color=pile[i][head[i]];
		head[i]++;
		if (in[color]){
			in[color]=0;
			ans=max(ans,dp(tot-1)+1);
			in[color]=1;
		}
		else {
			in[color]=1;
			ans=max(ans,dp(tot+1));
			in[color]=0;
		}
		head[i]--;
	}
	return ans;
}
int main(){
	int i,j;
	while (scanf("%d",&n),n){
		for (i=0;i<n;i++)
			for (j=0;j<4;j++) scanf("%d",&pile[j][i]);
		memset(f,-1,sizeof(f));
		memset(in,0,sizeof(in));
		memset(head,0,sizeof(head));
		printf("%d\n",dp(0));
	}
	return 0;
}
