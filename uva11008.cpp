#include <stdio.h>
#include <string.h>
#define INF 10000000
//第一次完全自主设计ac的题目....
//好激动好高兴... 
//不过用递推, 居然比答案那个递归的还慢了一倍, 无语... 
int n,m,pos[20][2],f[200000],g[200000];
int ok(int a,int b,int c){
	return (pos[a][0]-pos[b][0])*(pos[b][1]-pos[c][1])==
		   (pos[b][0]-pos[c][0])*(pos[a][1]-pos[b][1]);

}
int min(int a,int b){
	if (a>b) return b;
	return a;
}
int main(){
	int T,t;
	int i,j,k,s,ans;
	scanf("%d",&T);
	for (t=1;t<=T;t++){
		scanf("%d%d",&n,&m);
		for (i=0;i<n;i++) scanf("%d%d",&pos[i][0],&pos[i][1]);
		for (i=0;i<n;i++) f[1<<i]=1,g[1<<i]=1;
		f[0]=0; g[0]=0; 
		ans=INF;
//		for (i=1;i<(1<<n);i++) printf("%d ",g[i]); printf("\n");
//		理解题意就好办了
//		任意选定两个点, 与这两个点同一直线的都得删掉, 而不是部分删掉 
		for (s=1;s<(1<<n);s++){
			for (i=0;i<n;i++)
				for (j=i+1;j<n;j++)
					if ( (s&(1<<i)) && (s&(1<<j)) ){
						int ss=s^(1<<i)^(1<<j);
						int tot=2;
//						for (k=i+1;k<n;k++) 
						for (k=0;k<n;k++) 
							if ( (ss&(1<<k)) && (ok(i,j,k)) ) 
								ss^=(1<<k),tot++;
						f[s]=f[ss]+1;
						g[s]=g[ss]+tot;
						if (g[s]==m) ans=min(ans,f[s]);
					}
			}
		if (t>1) printf("\n");
//		for (i=1;i<(1<<n);i++) printf("%d ",f[i]); printf("\n");
		if (m==1) ans=1;
		if (m==0) ans=0;
		printf("Case #%d:\n%d\n",t,ans);
	}
	return 0;
}
