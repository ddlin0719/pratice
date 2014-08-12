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
	//�߽�����
	if (dist-gas[cur]<=left-100){
		cost[cur][left]=0;
		return 0;
	}
	for (i=cur+1;i<n;i++){
		remain=left-(gas[i]-gas[cur]);
		//��������վ��ȥ������,�Ͳ�Ҫ������
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
		//��ΪҪ�����ٷ���, ���Գ�ʼ��ΪINF
		memset(cost,333,sizeof(cost));
		memset(visit,0,sizeof(visit));
		scanf("%d%*c",&dist);
		//��1��ʼ���Ǽ���վ
		n=1;
		while (gets(str)){
			if (str[0]==0) break;
			sscanf(str,"%d%d",&gas[n],&price[n]);
			n++;
		}
		//0�����, ����100����
		tmp=dp(0,100);
		if (tmp<INF) printf("%d\n",tmp);
		else printf("Impossible\n");
		if (T) printf("\n");
	}
	return 0;
}