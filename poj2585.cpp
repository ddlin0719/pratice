#include<stdio.h>
#include<string.h>
#include<vector>
int ru[11],g[11][11];
std::vector<int> map[11][11];
void init(){
	int x=0,y=0,i;
	for (i=1;i<=9;i++){
		map[x][y].push_back(i);
		map[x+1][y].push_back(i);
		map[x][y+1].push_back(i);
		map[x+1][y+1].push_back(i);
		y++;
		if (y%3==0) x++;
		y%=3;
	}
	/*
	for (i=0;i<4;i++)
		for (j=0;j<4;j++){
			for (k=0;k<map[i][j].size();k++) printf("%d ",map[i][j][k]);
			printf("\n");
		}
	*/
}
void build(int a,int x,int y){
	int i,tmp;
	for (i=0;i<map[x][y].size();i++){
		tmp=map[x][y][i];
		//²»ÒªÖØ±ß
		//if (a!=tmp){
		if (a!=tmp&&!g[a][tmp]){
			ru[tmp]++;
			g[a][tmp]=1;
		}
	}
}
int topoSort(){
	int i,j,k;
	for (i=1;i<=9;i++){
		for (j=1;j<=9;j++)
			if (ru[j]==0) break;
		if (j==10) return 0;
		for (k=1;k<=9;k++)
			if (g[j][k]) ru[k]--;
		ru[j]=-1;
	}
	return 1;
}
int main(){
	char ans[2][44]={"THESE WINDOWS ARE BROKEN","THESE WINDOWS ARE CLEAN"};
	char str[22];
	int screen[4][4];
	int i,j;
	init();
	while (scanf("%s",str),str[0]!='E'){
		memset(ru,0,sizeof(ru));
		memset(g,0,sizeof(g));
		for (i=0;i<4;i++)
			for (j=0;j<4;j++){
				scanf("%d",&screen[i][j]);
				build(screen[i][j],i,j);
			}
		scanf("%s",str);
		puts(ans[topoSort()]);
	}
	return 0;
}