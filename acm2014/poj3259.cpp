#include <stdio.h>
#include <string.h>
int queue[505000],head,tail;
int main(){
	int T,h,i,j,n,m,mm;
	int flag,a,b,c,cur;
	int dist[505],inq[505],count[505];
	char str[2][10]={"NO","YES"};
	int first[6000],next[6000],e[6000],v[6000];
	scanf("%d",&T);
	for (h=1;h<=T;h++){
		memset(next,-1,sizeof(next));
		memset(first,-1,sizeof(first));
		scanf("%d%d%d",&n,&m,&mm);
		for (i=0;i<m*2;i++){
			scanf("%d%d%d",&a,&b,&c);
			next[i]=first[a];
			first[a]=i;
			v[i]=b;
			e[i]=c;
			
			i++;
			next[i]=first[b];
			first[b]=i;
			v[i]=a;
			e[i]=c;
		}
		for (;i<m*2+mm;i++){
			scanf("%d%d%d",&a,&b,&c);
			next[i]=first[a];
			first[a]=i;
			v[i]=b;
			e[i]=-c;
		}
		flag=0;
		memset(count,0,sizeof(count));
		memset(dist,10,sizeof(dist));
		memset(inq,0,sizeof(inq));
		head=-1,tail=0,queue[0]=1,inq[1]=0,count[1]=1;
		dist[1]=0;
		while (head<tail){
			cur=queue[++head];
			inq[cur]=0;
			if (count[cur]>=n){
				flag=1;
				break;
			}
			for (i=first[cur];i!=-1;i=next[i])
				if (dist[v[i]]>dist[cur]+e[i]){
					dist[v[i]]=dist[cur]+e[i];
					if (!inq[v[i]]){
						inq[v[i]]=1;
						queue[++tail]=v[i];
						count[v[i]]++;
					}
				}
		}
		puts(str[flag]);
	}
	return 0;
} 
