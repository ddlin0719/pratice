#include <stdio.h>
#include <string.h>
#define INF 1000000000
int min(int a,int b){
	if (a<b) return a;
	return b;
}
int main(){
	int T=0;
	int n,m,i,j,k,_k;
	int time[11][11][31],day[11][11],f[11][1001];
	while (scanf("%d%d",&n,&m),n+m){
		memset(f,330,sizeof(f));
		memset(time,0,sizeof(time));
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				if (i!=j){
					scanf("%d",&day[i][j]);
					for (k=1;k<=day[i][j];k++)
						scanf("%d",&time[i][j][k]);
				}
		f[1][0]=0;
		for (k=1;k<=m;k++)
			for (i=1;i<=n;i++)
				for (j=1;j<=n;j++)
					if (i!=j){
						_k=(k-1)%day[j][i]+1;
						if (time[j][i][_k])
							f[i][k]=min(f[i][k],f[j][k-1]+time[j][i][_k]);
					}
		printf("Scenario #%d\n",++T);
		if (f[n][m]<INF) printf("The best flight costs %d.\n\n",f[n][m]);
		else printf("No flight possible.\n\n");
	}
	return 0;
}
