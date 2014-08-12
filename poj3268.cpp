#include <stdio.h>
#include <string.h>
int map[1001][1001];
int main(){
	int dist1[1001],dist2[1001],k1,k2,max,min1,min2;
	int visit1[1001],visit2[1001];
	int n,m,x,i,j,a,b,c,tmp;
	while (scanf("%d%d%d",&n,&m,&x)!=EOF){
		memset(map,10,sizeof(map));
		while (m--){
			scanf("%d%d%d",&a,&b,&c);
			map[a][b]=c;
		}
		memset(dist1,10,sizeof(dist1));
		memset(dist2,10,sizeof(dist2));
		memset(visit1,0,sizeof(visit1));
		memset(visit2,0,sizeof(visit2));
		dist1[x]=dist2[x]=0;
		for (i=0;i<n;i++){
			min1=min2=1000000000;
			for (j=1;j<=n;j++){
				if (!visit1[j]&&min1>dist1[j])
					k1=j,min1=dist1[j];
				if (!visit2[j]&&min2>dist2[j])
					k2=j,min2=dist2[j];
			}
			visit1[k1]=visit2[k2]=1;
			for (j=1;j<=n;j++){
				if (!visit1[j]&&dist1[j]>dist1[k1]+map[k1][j])
					dist1[j]=dist1[k1]+map[k1][j];
				if (!visit2[j]&&dist2[j]>dist2[k2]+map[j][k2])
					dist2[j]=dist2[k2]+map[j][k2];
			}
		}
		max=-1000000000;
		for (i=1;i<=n;i++){
			tmp=dist1[i]+dist2[i];
			//printf("%d\n",dist1[i]);
			if (tmp>max) max=tmp;
		}
		printf("%d\n",max);
	}
	return 0;
}
