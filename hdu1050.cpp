/*
The floor has 200 rooms each on the north side and south side
 along the corridor. Recently the Company made a plan to reform 
 its system. The reform includes moving a lot of tables between 
 rooms. Because the corridor is narrow and all the tables are big
 , only one table can pass through the corridor.
 */
#include <stdio.h>
#include <string.h>

int main(){
	int T,n,i,j,max,maxn,tmp,a,b,f[222];
	scanf("%d",&T);
	while (T--){
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		maxn=0;
		for (i=0;i<n;i++){
			scanf("%d%d",&a,&b);
			if (a>b) tmp=a,a=b,b=tmp;
			a=a/2+a%2;
			b=b/2+b%2;
			if (b>maxn) maxn=b;
			for (j=a;j<=b;j++) f[j]++;
		}
		max=f[0];
		for (i=1;i<maxn;i++)
			if (f[i]>max) max=f[i];
		printf("%d\n",max*10);
		
	}
	return 0;
}