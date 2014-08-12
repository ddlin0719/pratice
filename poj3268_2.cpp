#include <stdio.h>
#include <string.h>
int n,m,x,e[100100];
int first1[1001],first2[1001],dist1[1001],dist2[1001];
int next1[100100],next2[100100],v[100100],u[100100];
//int queue[1001],head,tail;
int queue[100100],head,tail;
void spfa(int * first,int * next,int * dist,int * o){
	int inq[1001]={0},i,cur;
	queue[0]=x;
	head=-1,tail=0,inq[x]=1;
	while (head<tail){
		cur=queue[++head];
		inq[cur]=0;
		for (i=first[cur];i!=-1;i=next[i]){
			if (dist[o[i]]>dist[cur]+e[i]){
				dist[o[i]]=dist[cur]+e[i];
				if (!inq[o[i]]) 
					inq[o[i]]=1,
					queue[++tail]=o[i];
			}
		}
	}
}
int main(){
	int i,max,a,b,c;
	
	while (scanf("%d%d%d",&n,&m,&x)!=EOF){
		memset(first1,-1,sizeof(first1));
		memset(first2,-1,sizeof(first2));
		memset(next1,-1,sizeof(next1));
		memset(next2,-1,sizeof(next2));
		memset(dist1,10,sizeof(dist1));
		memset(dist2,10,sizeof(dist2));
		dist1[x]=dist2[x]=0;
		for (i=0;i<m;i++){
			scanf("%d%d%d",&a,&b,&c);
			next1[i]=first1[a];
			first1[a]=i;
			next2[i]=first2[b];
			first2[b]=i;
			e[i]=c;
			v[i]=b;
			u[i]=a;
		}
		spfa(first1,next1,dist1,v);
		spfa(first2,next2,dist2,u);
		max=dist1[1]+dist2[1];
		for (i=2;i<=n;i++)
			if (max<dist1[i]+dist2[i])
				max=dist1[i]+dist2[i];
		printf("%d\n",max);
	}
	return 0;
}