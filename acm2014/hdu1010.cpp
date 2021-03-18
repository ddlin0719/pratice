/*
The doggie found a bone in an ancient maze, which fascinated 
him a lot. However, when he picked it up, the maze began to 
shake, and the doggie could feel the ground sinking. He 
realized that the bone was a trap, and he tried desperately 
to get out of this maze.
*/
#include <stdio.h>
#include <string.h>
char map[8][8];
int a,b,m;
int begx,begy,endx,endy;
int dx[]={0,0,-1,1},dy[]={1,-1,0,0};
int abs(int a){
	if (a<0) a=-a;
	return a;
}
int dfs(int x,int y,int step){
	int _x,_y;
	//¼Ó¶àÕâ¾ä
	if ((step-abs(x-endx)-abs(y-endy))%2) return 0;
	if (step==0) return (x==endx&&y==endy);
	for (int i=0;i<4;i++){
		_x=x+dx[i],_y=y+dy[i];
		if (_x>=a||_x<0||_y>=b||_y<0) continue;
		if (map[_x][_y]=='X') continue;
		map[_x][_y]='X';
		if (dfs(_x,_y,step-1)) return 1;
		map[_x][_y]='.';
	}
	return 0;
}
int main(){
	char ans[2][6]={"NO","YES"};
	int i,j;
	while (scanf("%d%d%d",&a,&b,&m),a+b+m){
		for (i=0;i<a;i++) scanf("%s",map[i]);
		for (i=0;i<a;i++)
			for (j=0;j<b;j++)
				if (map[i][j]=='S'){
					begx=i,begy=j;
				}
				else if (map[i][j]=='D'){
					endx=i,endy=j;
				}
		map[begx][begy]='X';
		printf("%s\n",ans[dfs(begx,begy,m)]);
	}
	return 0;
}
