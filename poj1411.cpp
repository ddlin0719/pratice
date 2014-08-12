#include <stdio.h>
#include <math.h>
void getPri(int * p,int & tot){
	int i,j,k;
	tot=2;
	p[0]=2,p[1]=3;
	for (i=4;i<10000;i++){
		k=sqrt(double(i));
		for (j=2;j<=k;j++) if (i%j==0) break;
		if (j>k) p[tot++]=i;
	}
}

int main(){
	int pri[10000],tot;
	int n,a,b,i,j,max,sum;
	int p,q;
	getPri(pri,tot);
	while (scanf("%d%d%d",&n,&a,&b),a+b+n){
		max=0;
		for (i=0;i<tot;i++)
			for (j=i;j<tot;j++)
				if (pri[j]*a<=pri[i]*b){
					sum=pri[i]*pri[j];
					if (sum>n) break;
					if (sum<=n&&sum>max)
						p=i,q=j,max=sum;
					
				}
		printf("%d %d\n",pri[p],pri[q]);
	}
	return 0;
}