#include <stdio.h>
#include <string.h>
int ru[222],child[222],next[222][222],n;
int ans[222];
void print(){
	for (int i=0;i<n;i++){
		if (i) printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
}
int toposort(int cur){
	int i,j;
	if (cur==n){
		return 1;
	}
	for (i=1;i<=n;i++)
		if (ru[i]==0){
			ru[i]=-1;
			for (j=0;j<child[i];j++)
				ru[next[i][j]]--;
			ans[cur]=i;
			if (toposort(cur+1)) return 1;
			ru[i]=0;
			for (j=0;j<child[i];j++)
				ru[next[i][j]]++;
		}
	return 0;
}
int main(){
	int T;
	int i,m,a,b;
	scanf("%d",&T);
	while (T--){
		memset(ru,0,sizeof(ru));
		memset(child,0,sizeof(child));
		scanf("%d%d",&n,&m);
		while (m--){
			scanf("%d%d",&a,&b);
			ru[b]++;
			next[a][child[a]++]=b;
		}
		if (toposort(0)) print();
		else printf("-1\n");
	}
	return 0;
}
