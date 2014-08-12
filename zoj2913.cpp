#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
int nz,nr,mz[10001],adj[10001][11],ans[10001],reach[10001];
int cur;
int max(int a,int b){
	if (a>b) return a;
	return b;
}
void update(int stop){
	int tmp,tmpv,i;
	queue<int> q,qv;
	//if (reach[stop]<cur){
	reach[stop]=cur;
	q.push(stop);
	qv.push(1);
	ans[stop]=max(1,ans[stop]);
	//}
	while (!q.empty()){
		tmp=q.front();
		tmpv=qv.front();
		q.pop();
		qv.pop();
		for (i=0;i<mz[tmp];i++)
			if (reach[adj[tmp][i]]<cur){
				q.push(adj[tmp][i]);
				qv.push(tmpv+1);
				//ans[tmp]=max(ans[tmp],dist);
				ans[adj[tmp][i]]=max(ans[adj[tmp][i]],tmpv+1);
				reach[adj[tmp][i]]=cur;
			}
	}

		
}

int main(){
	int T,i,j,id,stop;
	int min,cen;
	scanf("%d",&T);
	while (T--){
		cur=0;
		scanf("%d%d",&nz,&nr);
		memset(ans,0,sizeof(ans));
		memset(reach,-1,sizeof(reach));
		for (i=0;i<nz;i++){
			scanf("%d",&id);
			scanf("%d",&mz[id]);
			for (j=0;j<mz[id];j++) scanf("%d",&adj[id][j]);
		}
		for (i=0;i<nr;i++){
			scanf("%d",&j);
			while (j--){
				scanf("%d",&stop);
				update(stop);
				cur++;
			}
		}
		min=1e30,cen=0;
		for (i=0;i<10001;i++)
			if (reach[i]!=-1&&min>ans[i]){
				min=ans[i];
				cen=i;
			}
		printf("%d %d\n",min,cen);
	}
	return 0;
}

