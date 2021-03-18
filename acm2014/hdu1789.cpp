/*Ignatius has just come back school from the 30th ACM/ICPC.
 Now he has a lot of homework to do. Every teacher gives him
  a deadline of handing in the homework. If Ignatius hands in
   the homework after the deadline, the teacher will reduce 
   his score of the final test. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b){
	int * aa=(int *)a;
	int * bb=(int *)b;
	if (aa[1]==bb[1]) return aa[0]-bb[0];
	return bb[1]-aa[1];
}
int main(){
	int T,n,i,j,arr[1010][2];
	int visit[1010],ans;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		memset(visit,0,sizeof(visit));
		for (i=0;i<n;i++) scanf("%d",&arr[i][0]);
		for (i=0;i<n;i++) scanf("%d",&arr[i][1]);
		qsort(arr,n,sizeof(arr[0]),cmp);
		ans=0;
		/*
		beg=0;
		for (i=1;;i++){
			for (j=beg;j<n;j++)
				if (!visit[j]&&arr[j][0]>=i) break;
			if (j==n) break;
			visit[j]=1;
			beg=j+1;
		}
		*/
		for (i=0;i<n;i++){
			for (j=arr[i][0];j;j--)
				if (!visit[j]) break;
			if (j) visit[j]=1;
			else ans+=arr[i][1];
		}
		/*
		ans=0;
		for (i=0;i<n;i++)
			if (!visit[i]) ans+=arr[i][1];
		*/
		printf("%d\n",ans);
	}
	return 0;
}

