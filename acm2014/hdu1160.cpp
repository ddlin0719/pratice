/*FatMouse believes that the fatter a mouse is, the faster it 
runs. To disprove this, you want to take the data on a collection 
of mice and put as large a subset of this data 
as possible into a sequence so that the weights are increasing
, but the speeds are decreasing.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node{
	int a,b,id;
}mice[1001];
int cmp(const void * a, const void * b){
	Node * aa=(Node *)a;
	Node * bb=(Node *)b;
	return bb->a-aa->a;
}
int main(){
	int i,j,k,n=0;
	int pre[1001],f[1001],max;
	while (scanf("%d%d",&mice[n].a,&mice[n].b)!=EOF) 
		mice[n].id=n+1, n++;
	memset(pre,-1,sizeof(pre));
	memset(f,0,sizeof(f));
	qsort(mice,n,sizeof(Node),cmp);
	//for (i=0;i<n;i++) printf("(%d %d)\n",mice[i].a,mice[i].b);
	for (i=0;i<n;i++){
		max=0;
		k=-1;
		for (j=0;j<i;j++)
			//a必须不能相等
			if (mice[i].a<mice[j].a&&mice[i].b>mice[j].b&&f[j]>max)
				max=f[j],k=j;
		pre[i]=k;
		f[i]=max+1;
	}
	max=-1;
	for (i=0;i<n;i++){
	//	printf("%d ",f[i]);
		if (max<f[i])
			max=f[i],k=i;
	}
	//printf("----------------\n");
	//for (i=0;i<n;i++) printf("%d ",pre[i]); printf("\n");
	printf("%d\n",max);
	while (k!=-1){
		printf("%d\n",mice[k].id);
		k=pre[k];
	}
	return 0;
}
