#include <stdio.h>
int main(){
	int i,j,n;
	__int64 f[51]={0,3,6,6};
	//要初始化到3
	//for (i=3;i<=50;i++)
	for (i=4;i<=50;i++)
		f[i]=f[i-1]+f[i-2]*2;
	while (scanf("%d",&n)!=EOF)
		printf("%I64d\n",f[n]);
	return 0;
} 