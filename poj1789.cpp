#include <stdio.h>
#include <string.h>
int dist[2222][2222];
int get_dist(char *a,char *b){
	int i,dist=0;
	for (i=0;i<7;i++)
		dist+=(a[i]!=b[i]);
	return dist;
}
int main(){
	int n,ii,i,j,min;
	int f[2222],ans;
	char truck[2222][8],visit[2222];
	while (scanf("%d",&n),n){
		for (i=0;i<n;i++) scanf("%s",truck[i]);
		for (i=0;i<n;i++)
			for (j=i;j<n;j++)
				dist[j][i]=dist[i][j]=get_dist(truck[i],truck[j]);
		ans=0;
		for (i=0;i<n;i++) f[i]=1<<9;
		f[0]=0;
		memset(visit,0,sizeof(visit));
		for (j=0;j<n;j++){
			min=1<<9;
			for (i=0;i<n;i++)
				if (!visit[i]&&f[i]<min)
					min=f[i],ii=i;
			visit[ii]=1;
			//printf("%d\n",f[ii]);
			ans+=f[ii];
			for (i=0;i<n;i++)
				if (!visit[i]&&f[i]>dist[ii][i])
					f[i]=dist[ii][i];
		}
		printf("The highest possible quality is 1/%d.\n",ans);
	}
	return 0;
}
