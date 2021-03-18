/*
You are to find the minimum setup time to process a given
 pile of n wooden sticks. For example, if you have five 
 sticks whose pairs of length and weight are (4,9), (5,2),
 (2,1), (3,5), and (1,4), then the minimum setup time should
 be 2 minutes since there is a sequence of pairs (1,4), (3,5),
 (4,9), (2,1), (5,2).
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b){
	int * aa=(int *)a;
	int * bb=(int *)b;
	if (aa[0]==bb[0]) return aa[1]-bb[1];
	return aa[0]-bb[0];
}
int main(){
	int T,n,i,arr[5005][2];
	int _cur,cur,visit[5005],tot ;
	scanf("%d",&T);
	while (T--){
		memset(visit,0,sizeof(visit));
		scanf("%d",&n);
		for (i=0;i<n;i++) 
			scanf("%d%d",&arr[i][0],&arr[i][1]);
		qsort(arr,n,sizeof(arr[0]),cmp);
		cur=0, tot=0;
		while (1){
			tot++;
			visit[cur]=1;
			_cur=cur;
			for (i=cur+1;i<n&&arr[i][0]>=arr[cur][0];i++)
				if (!visit[i]&&arr[i][1]>=arr[cur][1])
					visit[i]=1,cur=i;
			cur=_cur;
			for (i=cur+1;i<n&&visit[i];i++);
			if (i==n) break;
			cur=i;
		}
		printf("%d\n",tot);
	}
	return 0;
}