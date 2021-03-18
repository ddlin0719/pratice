/*
The GeoSurvComp geologic survey company is responsible for
 detecting underground oil deposits. GeoSurvComp works with
 one large rectangular region of land at a time, and creates
 a grid that divides the land into numerous square plots. It
 then analyzes each plot separately, using sensing equipment
 to determine whether or not the plot contains oil. 
*/
#include <stdio.h>
int a,b;
int dx[]={0,0,-1,1,-1,-1,1,1};
int dy[]={-1,1,0,0,1,-1,-1,1};
char map[101][101];
void dfs(int x,int y){
	int _x,_y;
	map[x][y]='*';
	for (int i=0;i<8;i++){
		_x=x+dx[i],_y=y+dy[i];
		if (_x<0||_x>=a||_y<0||_y>=b) continue;
		if (map[_x][_y]!='@') continue;
		dfs(_x,_y);
	}
}
int main(){
	int i,j,ans;
	while (scanf("%d%d",&a,&b),a+b){
		for (i=0;i<a;i++) scanf("%s",map[i]);
		ans=0;
		for (i=0;i<a;i++)
			for (j=0;j<b;j++)
				if (map[i][j]=='@')
					ans++,dfs(i,j);
		printf("%d\n",ans);
	}
	return 0;
}