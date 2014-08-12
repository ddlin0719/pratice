#include <stdio.h>
int main(){
	__int64 f[51]={0,1,2,3};
	int i,j,n;
	//int m;
	for (i=4;i<51;i++) f[i]=f[i-1]+f[i-2];

	//scanf("%d",&m);
	while (scanf("%d",&n)!=EOF) printf("%I64d\n",f[n]);
	return 0;
}