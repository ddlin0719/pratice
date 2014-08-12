#include <stdio.h>
#include <string.h>
char name[202][33],tot;
int locate(char * str){
	int i;
	for (i=0;i<tot;i++)
		if (strcmp(str,name[i])==0) break;
	if (i==tot){
		tot++;
		strcpy(name[i],str);
	}
	return i;
}
int max(int a,int b){
	if (a<b) a=b; return a;}
int min(int a,int b){
	if (a>b) a=b; return a;} 
int main(){
	int T=0;
	char a[33],b[33];
	int beg,end,_max,visit[222];
	int f[222],n,m,i,j,k;
	int _a,_b,c,map[222][222];
	while (scanf("%d%d",&n,&m),n+m){
		tot=0;
		memset(map,0,sizeof(map));
		while (m--){
			scanf("%s %s %d",a,b,&c);
			_a=locate(a),_b=locate(b);
			map[_a][_b]=map[_b][_a]=c;
		}
		//printf("%d\n",map[0][0]);
		scanf("%s %s",a,b);
		//三个memset是难点
		memset(f,0,sizeof(f));
		memset(visit,0,sizeof(visit));
		beg=locate(a),end=locate(b);
		f[beg]=100000000;
		for (i=0;i<n;i++){
			_max=-1;
			for (j=0;j<n;j++)
				if (!visit[j]&&f[j]>_max)
					_max=f[j],k=j;
			visit[k]=1;
			//printf("%d\n",k);
			if (k==end) break;
			for (j=0;j<n;j++)
				if (!visit[j])
					//f[j]=min(f[j],map[k][j]);
					f[j]=max(min(map[k][j],f[k]),f[j]);
		}
		printf("Scenario #%d\n",++T);
		printf("%d tons\n\n",f[end]);
	}
	return 0;
}
