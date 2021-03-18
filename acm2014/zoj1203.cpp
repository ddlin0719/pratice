#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct Edge{
	int x,y;
	double v;
}edge[5555];
int fa[101];
int cmp(const void *a,const void *b){
	Edge * aa=(Edge *)a;
	Edge * bb=(Edge *)b;
	//return aa->v-bb->v;
	//因为这样涉及浮点转整形
	if ( aa->v>bb->v )return 1;
	else return -1;
}
int find(int cur){
	if (fa[cur]==cur) return cur;
	return fa[cur]=find(fa[cur]);
}
int main(){
	int T=0;
	int n,m,i,j,k,tot;
	double x[111],y[111],ans;
	while (scanf("%d",&n),n){
		m=0;
		for (i=0;i<n;i++) scanf("%lf%lf",&x[i],&y[i]);
		for (i=0;i<n;i++)
			for (j=i+1;j<n;j++)
				edge[m].v=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])),
				edge[m].x=i,edge[m].y=j,
				m++;
		qsort(edge,m,sizeof(Edge),cmp);
		//for (i=0;i<m;i++) printf("%d %d %lf\n",edge[i].x,edge[i].y,edge[i].v);
		for (i=0;i<n;i++) fa[i]=i;
		tot=1;
		ans=0;
		for (i=0;i<m;i++){
			int fa1=find(edge[i].x);
			int fa2=find(edge[i].y);
			if (fa1!=fa2){
				//fa[edge[i].x]=fa[edge[i].y];
				fa[fa1]=fa2;
				tot++;
				ans+=edge[i].v;
			}
			if (tot==n) break;
		}
		if (T) printf("\n");
		printf("Case #%d:\n",++T);
		printf("The minimal distance is: %.2lf\n",ans);
	}
	return 0;
}

