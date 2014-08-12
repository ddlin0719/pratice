#include <stdio.h>
#include <string.h>
int f[333][333];
struct Coin{
	int a,b;
	//int tot;
}coin[44];
int min(int x,int y){
	if (x>y) return y;
	return x;
}
int main(){
	int T;
	int i,j,k,n,sum,ans;
	scanf("%d",&T);
	while (T--){
		memset(f,333,sizeof(f));
		f[0][0]=0;
		scanf("%d%d",&n,&sum);
		//sum*=sum;
		for (i=0;i<n;i++)
			scanf("%d%d",&coin[i].a,&coin[i].b);
			//coin[i].a*=coin[i].a,coin[i].b*=coin[i].b,
			//coin[i].tot=coin[i].a+coin[i].b;
		for (i=0;i<n;i++)
			for (j=coin[i].a;j<=sum;j++)
				for (k=coin[i].b;k<=sum;k++)
					f[j][k]=min(f[j][k],f[j-coin[i].a][k-coin[i].b]+1);
		ans=1000000000;
		for (i=0;i<=sum;i++)
			for (j=0;j<=sum;j++)
				if (i*i+j*j==sum*sum) ans=min(ans,f[i][j]);
		if (ans>=1000000000) printf("not possible\n");
		else printf("%d\n",ans);
	}
	return 0;
}
	

