/*
“今年暑假不AC？”
“是的。”
“那你干什么呢？”
“看世界杯呀，笨蛋！”
“@#$%^&*%...”
*/
#include <stdio.h>
#include <stdlib.h> 
int cmp(const void *a,const void *b){
	int * aa=(int *)a;
	int * bb=(int *)b;
	if (aa[1]==bb[1]) return aa[0]-bb[0];
	return aa[1]-bb[1];
}
int main(){
	int i,n,end,cur,tot;
	int arr[111][2];
	while (scanf("%d",&n),n){
		for (i=0;i<n;i++) 
			scanf("%d%d",&arr[i][0],&arr[i][1]);
		qsort(arr,n,sizeof(arr[0]),cmp);
		//for (i=0;i<n;i++) printf("(%d %d)\n",arr[i][0],arr[i][1]);
		end=0,cur=0,tot=0;
		while (1){
			for (i=cur;i<n;i++)
				if (end<=arr[i][0]) break;
			if (i==n) break;
			tot++;
			cur=i+1;
			end=arr[i][1];
		}
		printf("%d\n",tot);
	}
	return 0;
}
