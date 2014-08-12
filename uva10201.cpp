#include <stdio.h>
#include <string.h>
#define INF 100000000
int cost[111][222],visit[111][222];
int dist,gas[111],price[111],n;
int min(int a,int b){
	if (a>b) return b;
	return a;
}
int dp(int cur,int left){
	int i,add,tmp,remain;
	if (visit[cur][left]) return cost[cur][left];
	visit[cur][left]=1;
	//边界条件
	if (dist-gas[cur]<=left-100){
		cost[cur][left]=0;
		return 0;
	}
	for (i=cur+1;i<n;i++){
		remain=left-(gas[i]-gas[cur]);
		//其它加油站都去不了了,就不要搜索了
		if (remain<0) break;
		//for (add=0;add+left<=200;add++){
		for (add=0;add+remain<=200;add++){
			//if (add+remain<=gas[i]-gas[cur]) continue;
			tmp=dp(i,add+remain);
			if (tmp>INF) continue;
			cost[cur][left]=min(cost[cur][left],tmp+add*price[i]);
		}
	}
	return cost[cur][left];
}
int main(){
	int tmp,T;
	char str[1010];
	scanf("%d",&T);
	gas[0]=0;
	while (T--){
		//因为要求最少费用, 所以初始化为INF
		memset(cost,333,sizeof(cost));
		memset(visit,0,sizeof(visit));
		scanf("%d%*c",&dist);
		//从1开始才是加油站
		n=1;
		while (gets(str)){
			if (str[0]==0) break;
			sscanf(str,"%d%d",&gas[n],&price[n]);
			n++;
		}
		//0是起点, 带有100升油
		tmp=dp(0,100);
		if (tmp<INF) printf("%d\n",tmp);
		else printf("Impossible\n");
		if (T) printf("\n");
	}
	return 0;
}