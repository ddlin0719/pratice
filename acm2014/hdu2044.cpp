/*·ä³²*/
#include <stdio.h>

int main(){
	int T,i,j,k,a,b;
	__int64 f[55];
	f[0]=0; f[1]=1; f[2]=2;
	for (i=3;i<51;i++)
		f[i]=f[i-1]+f[i-2];
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&a,&b);
		printf("%I64d\n",f[b-a]);
	}
	return 0;
}