#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *_p, const void *_q)
{
	int *p = (int *)_p;
    int *q = (int *)_q;
	return p[1]-q[1];
}
inline int max(int a,int b){
	if (a<b) return b;
	return a;
}
inline int min(int a,int b){
	if (a<b) return a;
	return b;
}
int main(){
	int i,j,f[6000];
	int arr[6000][2],n=0,ans=1;
	memset(f,10,sizeof(f));
	f[0]=0;
	while (scanf("%d%d",&arr[n][0],&arr[n][1])!=EOF) n++;
	//要排序的01背包
	//按载重能力从小到大排
	qsort(arr,n,sizeof(arr[0]),cmp);
	for (i=0;i<n;i++)
		for (j=n;j;j--)
			if (f[j-1]+arr[i][0]<=arr[i][1])
				f[j]=min(f[j],f[j-1]+arr[i][0]),
				ans=max(ans,j);
	printf("%d\n",ans);
	return 0;
}
