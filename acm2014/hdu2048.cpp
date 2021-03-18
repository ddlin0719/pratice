#include <stdio.h>
int main(){
	int i,j,n;
	__int64 sum[21],f[21];
	sum[1]=1;
	for (i=2;i<21;i++) sum[i]=i*sum[i-1];
	f[2]=1,f[3]=2;
	for (i=4;i<21;i++) f[i]=(i-1)*(f[i-1]+f[i-2]);
	scanf("%d",&n);
	while (scanf("%d",&n)!=EOF)
		printf("%.2lf%%\n",f[n]*100.0/sum[n]);
	return 0;
} 