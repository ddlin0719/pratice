#include <stdio.h>
#include <string.h>
int topic[1010],sum[1010],l,c;
int f[1010],g[1010];
//ÇáËÉºÁÎÞÑ¹Á¦,¹þ¹þ¹þ¹þ 
int getv(int x){
	if (x==0) return 0;
	if (x>=1&&x<=10) return -c;
	return (x-10)*(x-10);
}
int min(int a,int b){
	if (a>b) return b;
	return a;
}
int main(){
	int T=0,n;
	int i,j;
	while (scanf("%d",&n),n){
		scanf("%d%d",&l,&c);
		for (i=1;i<=n;i++) scanf("%d",&topic[i]);
		sum[0]=0;
		for (i=1;i<=n;i++) sum[i]=sum[i-1]+topic[i];
		f[0]=0; g[0]=0;
		for (i=1;i<=n;i++){
			j=i-1; f[i]=1<<30; g[i]=1<<30;
			while (1){
				if (f[i]>f[j]+1){
					f[i]=f[j]+1;
					g[i]=g[j]+getv(l-sum[i]+sum[j]);
				}
				else if (f[i]==f[j]+1){
					g[i]=min(g[i],g[j]+getv(l-sum[i]+sum[j]));
				}
//				f[i]=min(f[i],f[j]+1);
//				g[i]=min(g[i],g[j]+getv(sum[i]-sum[j]));
				j--;
				if (j<0||sum[i]-sum[j]>l) break;
			}
		}
		if (T) printf("\n");
		printf("Case %d:\n",++T);
		printf("Minimum number of lectures: %d\n",f[n]);
		printf("Total dissatisfaction index: %d\n",g[n]);
		
	}
	return 0;
}
	 
