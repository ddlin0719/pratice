#include <stdio.h>
#include <string.h>
int f[101][101],map[101][101];
int max3(int a,int b,int c){
	if (a<b) a=b;
	if (a<c) a=c;
	return a;
}
int main(){
	int T,i,j;
	int n;
	int max;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		memset(map,-1,sizeof(map));
		memset(f,0,sizeof(f));
		for (i=1;i<=n;i++)
			for (j=1;j<=i;j++) scanf("%d",&map[i][j]);
		f[1][1]=map[1][1];
		for (i=2;i<=n;i++)
			for (j=1;j<=i;j++)
				f[i][j]=max3(f[i][j],f[i-1][j],f[i-1][j-1])+map[i][j];
		max=-1;
		for (i=1;i<=n;i++)
			if (max<f[n][i]) max=f[n][i];
		printf("%d\n",max);
	}
	return 0;
}