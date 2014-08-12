#include <stdio.h>
#include <string.h>
int map[1001][1001],len[1001],t[1001];
char str[1001][2001];
void match(int a,int b){
	int i;
	for (i=0;i<4;i++)
		if (str[a][i]!=str[b][len[b]-4+i]) break;
	//printf("%d\n",i);   
	if (i==4)  map[b][a]=t[b];
}
int main(){
	int n,i,j,jj,f[1001];
	int min,visit[1001];
	while (scanf("%d",&n),n){
		memset(map,333,sizeof(map));
		for (i=0;i<n;i++){
			scanf("%d%s",&t[i],&str[i]);
			len[i]=strlen(str[i]);
			for (j=0;j<i;j++)
				//ÎðÍüÁËÁ½¸ömatch
				match(i,j),match(j,i);
		}
		memset(f,333,sizeof(f)); 
		memset(visit,0,sizeof(visit));
		f[0]=0;
		for (i=0;i<n;i++){
			min=100000000;
			jj=-1;
			for (j=0;j<n;j++)
				if (!visit[j]&&f[j]<min)
					min=f[j],jj=j;
			//printf("%d\n",jj);
			if (jj==-1||jj==n-1) break;
			visit[jj]=1;
			for (j=0;j<n;j++)
				if (!visit[j]&&f[j]>f[jj]+map[jj][j])
					f[j]=f[jj]+map[jj][j];
		}
		if (f[n-1]<100000000) printf("%d\n",f[n-1]);
		else printf("-1\n");
	}
	return 0;
}
