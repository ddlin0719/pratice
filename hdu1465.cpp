#include <stdio.h>
int main(){
	__int64 f[21]={0,0,1,2};
	int i,n;
	for (i=4;i<21;i++) f[i]=(i-1)*(f[i-1]+f[i-2]);
	while (scanf("%d",&n)!=EOF)
		printf("%I64d\n",f[n]);
	return 0;
};