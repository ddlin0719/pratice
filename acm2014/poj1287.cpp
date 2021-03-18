#include <stdio.h>
#include <stdlib.h>
struct Edge{
	int a,b,v;
}edge[1333];
int fa[55];
int cmp(const void *a,const void *b){
	Edge *aa=(Edge *)a;
	Edge *bb=(Edge *)b;
	return aa->v-bb->v;
}

int find(int cur){
	if (fa[cur]==cur) return cur;
	return (fa[cur]=find(fa[cur]));
}
int main(){
	int n,m,i,j;
	int fa1,fa2;
	int cost;
	while (scanf("%d",&n),n){
		scanf("%d",&m);
		for (i=0;i<=n;i++) fa[i]=i;
		cost=0;
		for (i=0;i<m;i++)
			scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].v);
		qsort(edge,m,sizeof(Edge),cmp);
		for (i=0;i<m;i++){
			fa1=find(edge[i].a);
			fa2=find(edge[i].b);
			if (fa1==fa2) continue;
			fa[fa1]=fa2;
			cost+=edge[i].v;
		}
		printf("%d\n",cost);
	}
	return 0;
}
