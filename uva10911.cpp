#include <stdio.h>
#include <math.h>
#include <string.h>
int n,point[22][2];
double dist[22][22],f[1<<16+10];
double min(double a,double b){
	if (a-b>(1e-8)) return b;
	return a;
}
int main(){
	int T=0;
	int i,j,a,b;
	while (scanf("%d",&n),n){
		n<<=1;
		for (i=0;i<n;i++)
			scanf("%*s%d%d",&point[i][0],&point[i][1]);
		for (i=0;i<n;i++)
			for (j=i;j<n;j++)
				dist[j][i]=dist[i][j]=sqrt(pow(point[i][0]-point[j][0],2)
								+pow(point[i][1]-point[j][1],2));
		//下面这个比较慢 
		//memset(f,333,sizeof(f));
		f[0]=0;
		for (i=1;i<(1<<n);i++){
			f[i]=1<<29;
			for (a=0;a<n;a++){
				if ((i&(1<<a))==0) continue;
				for (b=a+1;b<n;b++){
					if ((i&(1<<b))==0) continue;
					f[i]=min(f[i],f[i^(1<<a)^(1<<b)]+dist[a][b]);
				}
			}
		}
		printf("Case %d: %.2lf\n",++T,f[(1<<n)-1]);
		
	}
	return 0;
}
