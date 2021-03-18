#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 1e9
struct Node{
	int org,time,ins;
	int path[410];
}res[22];
int cmp(const void *a,const void *b){
	Node *aa=(Node *)a;
	Node *bb=(Node *)b;
	return aa->time-bb->time;
}
int main(){
	int map[22][22],n,fire,org;
	int i,j,k,min,jj;
	int pre[22],dist[22],visit[22];
	char ch;
	while (scanf("%d",&n)!=EOF){
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++){
				scanf("%d",&map[i][j]);
				//if (map[i][j]==-1) map[i][j]=maxn;
			}	
		scanf("%d",&fire);
		k=0;
		while (scanf("%d",&(res[k].org))!=EOF){
			int & org=res[k].org;
			
			/*
			org=0;
			while (1){
				if (ch>='0'&&ch<='9'||ch=='\n') break;
				ch=getchar();
			}
			if (ch=='\n') break;
			while (1){
				org*=10;
				org+=ch-'0';
				ch=getchar();
				if (ch==' '||ch=='\n') break;
			}
//			
*/
			//if (~scanf("%d",&org)) break;
//			printf("%d\n",org);
			for (i=0;i<=n;i++) dist[i]=maxn;
			memset(visit,0,sizeof(visit));
			memset(pre,-1,sizeof(pre));
			dist[org]=0;
			//printf("(%d)\n",dist[fire]);
			for (i=1;i<=n;i++){
				min=maxn;
				for (j=1;j<=n;j++)
					if (!visit[j]&&dist[j]<min)
						min=dist[j],jj=j;
				visit[jj]=1;
				//printf("%d\n",jj);
				for (j=1;j<=n;j++)
					if (!visit[j]&&map[jj][j]!=-1&&dist[j]>dist[jj]+map[jj][j])
						dist[j]=dist[jj]+map[jj][j],
						pre[j]=jj;
			}
			int cur=fire;
			for (j=0;;j++){
				if (cur==-1) break;
				res[k].path[j]=cur;
				cur=pre[cur];
			}
			res[k].time=dist[fire];
//			printf("(%d)\n",dist[fire]);
			res[k].ins=j;
			k++;
		}
		qsort(res,k,sizeof(Node),cmp);
		printf("Org\tDest\tTime\tPath\n");
		for (i=0;i<k;i++){
			printf("%d\t%d\t%d",res[i].org,
			fire,res[i].time);
			for (j=res[i].ins-1;j>=0;j--) printf("\t%d",res[i].path[j]);
			printf("\n");
		}
	}
	return 0;
}
