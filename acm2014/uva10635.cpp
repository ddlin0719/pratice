#include <stdio.h>
#include <string.h>
int min(int a,int b){
	if (a>b) return b;
	return a;
}
int upper_bound(int *d,int le,int ri,int x){
	int mid;
	while (le<ri){
		mid=(le+ri)/2;
		if (d[mid]<=x) le=mid+1;
		else ri=mid;
	}
	return le;
}
int main(){
	int T,x,n1,n2,id[66666],arr[66666];
	int d[66666];
	int i,j;
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++){
		scanf("%*d%d%d",&n1,&n2);
		memset(id,-333,sizeof(id));
		for (i=0;i<=n1;i++){
			scanf("%d",&x);
			id[x]=i;
		}
		for (i=0;i<=n2;i++){
			scanf("%d",&x);
			arr[i]=id[x];
		}
		//for (i=0;i<=n2;i++) printf("%d ",arr[i]);printf("\n");
		memset(d,333,sizeof(d));
		int ans=1;
		d[1]=arr[0];
		for (i=1;i<=n2;i++){
			j=upper_bound(d,1,i+1,arr[i]);
			//printf("%d ",j);
			if (ans<j) ans=j;
			d[j]=min(d[j],arr[i]);
		}	
		printf("Case %d: %d\n",TT,ans);
	}
	return 0;
}
		
			
