//题意很难懂...
#include <stdio.h>
#include <string.h>
#define INF 10000000
int map[505][505];
int main(){
	int T=0;
	int n,m,i,j;
	int f[505],visit[505],ii,min ;
	int key,a,b,c;
	double max1,max2;
	while (scanf("%d%d",&n,&m),n+m){
		memset(map,333,sizeof(map));
		while (m--)
			scanf("%d%d%d",&a,&b,&c),
			a--,b--, 
			map[a][b]=map[b][a]=c;
		memset(f,333,sizeof(f));
		memset(visit,0,sizeof(visit));
		f[0]=0;
		for (i=0 ;i<n;i++){
			min=INF;
			for (j=0;j<n;j++)
				if (!visit[j]&&f[j]<min)
					min=f[j],ii=j;
			visit[ii]=1;
			//printf("%d\n",f[ii]); 
			for (j=0;j<n;j++)
				if (!visit[j]&&f[j]>f[ii]+map[ii][j])
					f[j]=f[ii]+map[ii][j];
		}
		max1=-1;
		for (i=0;i<n;i++) 
			if (f[i]<INF&&max1<f[i]) max1=f[i],key=i;
		max2=0;
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				if (map[i][j]<INF&&max2<f[i]+f[j]+map[i][j])
					max2=f[i]+f[j]+map[i][j],
					a=i,b=j;
		max2/=2;
		printf("System #%d\n",++T);
		//printf("%d %d\n",max1,max2);
		if (max1<max2)
			printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n\n",max2,a+1,b+1);
		else
			printf("The last domino falls after %.1lf seconds, at key domino %d.\n\n",max1,key+1);
	}
	return 0;
}
