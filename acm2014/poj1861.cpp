#include <stdio.h>
#include <stdlib.h>
struct Edge{
	int x,y,v;
}edge[15005];
int fa[1001];
int cmp(const void* a,const void* b){
	Edge * aa=(Edge *)a;
	Edge * bb=(Edge *)b;
	return aa->v-bb->v;
}
int find(int cur){
	if (cur==fa[cur]) return cur;
	return fa[cur]=find(fa[cur]);
}
int main(){
	int i,j,fa1,fa2;
	int n,m;
	int max,sum,tot,ans[1001][2];
	while (~scanf("%d%d",&n,&m)){
		for (i=0;i<m;i++) scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].v);
		qsort(edge,m,sizeof(Edge),cmp);
		max=0,sum=0,tot=0;
		for (i=0;i<n;i++) fa[i]=i;
		for (i=0;i<m;i++){
			fa1=find(edge[i].x);
			fa2=find(edge[i].y);
			if (fa1!=fa2){
				if (max<edge[i].v) max=edge[i].v;
				fa[fa1]=fa2;
				ans[tot][0]=edge[i].x,ans[tot][1]=edge[i].y;
				tot++;
				if (tot==n-1) break;
			}
		}
		printf("%d\n%d\n",max,tot);
		for (i=0;i<tot;i++) printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	return 0;
}
