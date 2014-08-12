/*
Suppose that we have a square city with straight streets. A map of
 a city is a square board with n rows and n columns, each 
 representing a street or a piece of wall. 
 */
#include <stdio.h>
int n,ans;
int dx[]={0,0,-1,1},dy[]={1,-1,0,0};
char map[5][5];
int ok(int x,int y){
	int _x,_y,i;
	for (i=0;i<4;i++){
		_x=x,_y=y;
		while (1){
			_x+=dx[i],_y+=dy[i];
			if (_x>=n||_x<0||_y>=n||_y<0) break;
			if (map[_x][_y]=='X') break;
			if (map[_x][_y]=='x') return 0;
		}
	}
	return 1;
}
void dfs(int tot){
	int i,j;
	if (tot>ans) ans=tot;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			if (map[i][j]=='.'){
				if (!ok(i,j)) continue;
				map[i][j]='x';
				dfs(tot+1);
				map[i][j]='.';
			}
}
int main(){
	int i,j;
	while (scanf("%d",&n),n){
		for (i=0;i<n;i++) scanf("%s",map[i]);
		ans=0;
		for (i=0;i<n;i++)
			for( j=0;j<n;j++)
				if (map[i][j]=='.'){
					map[i][j]='x';
					dfs(1);
					map[i][j]='.';
				}
		printf("%d\n",ans);
	}
	return 0;
}
