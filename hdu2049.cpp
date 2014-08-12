#include <stdio.h>

int main(){
	int n,m,i,j;
	__int64 c[21][21],sum[21],f[21];
	sum[1]=1;
	for (i=2;i<21;i++) sum[i]=sum[i-1]*i;
	for (i=0;i<21;i++) c[i][0]=c[i][i]=1;
	for (i=1;i<21;i++)
		for (j=1;j<i;j++) 
			c[i][j]=sum[i]/sum[j]/sum[i-j];
	f[2]=1,f[3]=2;
	for (i=4;i<21;i++) f[i]=(i-1)*(f[i-1]+f[i-2]);
	scanf("%d",&n);
	while (scanf("%d%d",&n,&m)!=EOF)
		printf("%I64d\n",c[n][m]*f[m]);
	return 0;
}