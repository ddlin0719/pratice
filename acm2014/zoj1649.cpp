#include <stdio.h>
#include <string.h>
struct Point{
	int x,y,val;
};
int a,b,m[222][222];
int dx[]={0,0,-1,1},dy[]={1,-1,0,0};
int head,tail;
//¿ª³É44444,WA
Point q[4444444];
char map[222][222];
int main(){
	int i,j;
	int x,y,_x,_y,val,_val;
	while (~scanf("%d%d",&a,&b)){
		memset(m,333,sizeof(m));
		//printf("%d\n",m[0][0]);
		for (i=0;i<a;i++) scanf("%s",map[i]);
		for (i=0;i<a;i++){
			for (j=0;j<b;j++)
				if (map[i][j]=='a') break;
			if (map[i][j]=='a') break;
		}
		q[0].x=i,q[0].y=j,q[0].val=0;
		m[i][j]=0;
		head=-1,tail=0;
		while (head<tail){
			head++;
			x=q[head].x,y=q[head].y,val=q[head].val;
			//if (map[x][y]=='r') break;
			for (i=0;i<4;i++){
				_x=x+dx[i],_y=y+dy[i];
				if (_x<0||_x>=a||_y<0||_y>=b) continue;
				if (map[_x][_y]=='#') continue;
				_val=val+1;
				if (map[_x][_y]=='x') _val++;
				if (_val<m[_x][_y]){
					tail++;
					q[tail].x=_x,q[tail].y=_y,q[tail].val=_val;
					m[_x][_y]=_val;
				}
			
			}
		}
		for (i=0;i<a;i++){
			for (j=0;j<b;j++)
				if (map[i][j]=='r') break;
			if (map[i][j]=='r') break;
		}
		if (m[i][j]>44444444) printf("Poor ANGEL has to stay in the prison all his life.\n");
		else printf("%d\n",m[i][j]);
	}
	return 0;
}
