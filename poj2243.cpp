#include <stdio.h>
#include <string.h>
#include <queue>
int main(){
	char begx,begy,endx,endy;
	int map[9][9],x,y,_x,_y,i,j;
	int dx[]={-2,-1,1,2,-2,-1,1,2},dy[]={-1,-2,-2,-1,1,2,2,1};
	std::queue<int> qx,qy;
	while (~scanf("%c%c %c%c%*c",&begy,&begx,&endy,&endx)){
		printf("To get from %c%c to %c%c takes ",begy,begx,endy,endx);
		begy-='a',endy-='a',begx-='1',endx-='1';
		memset(map,-1,sizeof(map));
		//printf("%d %d %d %d\n",begx,begy,endx,endy);
		qx.push(begx),qy.push(begy);
		map[begx][begy]=0;
		while (!qx.empty()){
			x=qx.front(),qx.pop();
			y=qy.front(),qy.pop();
			//printf("%d %d\n",x,y);
			if (x==endx&&y==endy) break;
			for (i=0;i<8;i++){
				_x=x+dx[i],_y=y+dy[i];
				if (_x<0||_x>=8||_y<0||_y>=8) continue;
				if (map[_x][_y]!=-1) continue;
				qx.push(_x),qy.push(_y);
				map[_x][_y]=map[x][y]+1;
			}
		}
		while (!qx.empty()) qx.pop(),qy.pop();
		printf("%d knight moves.\n",map[endx][endy]);
	}
	return 0;
}