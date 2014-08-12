#include <stdio.h>
#include <string.h>
long long max(long long a,long long b){
	if (a<b) a=b;
	return a;
}
int main(){
	int coin[33],ncoin=21;
	int i,j,n;
	long long f[10010]={1};
	for (i=1;i<=ncoin;i++) coin[i]=i*i*i;
	for (j=1;j<=ncoin;j++)
		for (i=coin[j];i<=10000;i++)
			//f[i]=max(f[i],f[i-coin[j]]+1);
			f[i]+=f[i-coin[j]];
	while (scanf("%d",&n)!=EOF)
		printf("%lld\n",f[n]);
	return 0;
}
