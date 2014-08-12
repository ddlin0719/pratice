#include <stdio.h>
#include <stdlib.h>
struct Edge{
	int a,b,v;
}edge[999];
int fa[27];
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
	int n,i,j,m,_m;
	char a,b;
	int pa1,pa2;
	int cost;
	while (scanf("%d%*c",&n),n){
		for (i=0;i<=26;i++) fa[i]=i;
		cost=0;
		m=0;
		for (i=1;i<n;i++){
			scanf("%c %d%*c",&a,&_m);
			a-='A';
			while (_m--)
				scanf("%c %d%*c",&edge[m].b,&edge[m].v),
				edge[m].b-='A',
				edge[m].a=a,
				m++;		
		}
		qsort(edge,m,sizeof(Edge),cmp);
		for (i=0;i<m;i++){
			pa1=find(edge[i].a);
			pa2=find(edge[i].b);
			if (pa1==pa2) continue;
			fa[pa1]=pa2;
			cost+=edge[i].v;
		}
		printf("%d\n",cost);
	}
	return 0;
}
