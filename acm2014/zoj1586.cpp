#include <stdio.h>
#include <string.h>
struct Edge{
	int x,y,v;
}edge[1000001];
int map[1001][1001],adp[1001],visit[1001],f[1001];
int main(){
	int T,i,j,_j,min;
	int n;
	int ans;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (i=0;i<n;i++) scanf("%d",&adp[i]);
		for (i=0;i<n;i++)
			for (j=0;j<n;j++){
				scanf("%d",&map[i][j]);
				if (i!=j) map[i][j]+=adp[i]+adp[j];
			}
		memset(visit,0,sizeof(visit));
		//memset(f,333,sizeof(f));
		ans=0;
		for (i=0;i<n;i++) f[i]=map[i][0];
		for (i=0;i<n;i++){
			min=1e9;
			for (j=0;j<n;j++)
				if (!visit[j]&&f[j]<min) min=f[j],_j=j;
			visit[_j]=1;
			//for (i=0;i<n;i++) printf("%d ",f[i]); printf("\n");
			ans+=min;
			for (j=0;j<n;j++)
				if(!visit[j]&&f[j]>map[_j][j])
					f[j]=map[_j][j];
		}
		printf("%d\n",ans);
	}
	return 0;
}