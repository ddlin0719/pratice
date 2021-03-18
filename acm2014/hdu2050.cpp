#include <stdio.h>

int main(){
	int n,i;
	__int64 f[10001];
	for (i=1;i<=10000;i++) f[i]=2*i*i-i+1;
	scanf("%d",&n);
	while (scanf("%d",&n)!=EOF)
		printf("%I64d\n",f[n]);
	return 0;
} 