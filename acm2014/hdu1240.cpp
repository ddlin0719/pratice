/*
You're in space.
You want to get home.
There are asteroids.
You don't want to hit them.
*/
#include <stdio.h>
#include <string.h>
#define INF 100000000
struct Node{
	int x,y,z,val;
}queue[100010],cur;
int main(){
	char str[10],map[11][11][11];
	int f[11][11][11]; 
	int n,beg[3],end[3];
	int x,y,z;
	int dx[]={0,0,1,0,0,-1},dy[]={0,1,0,0,-1,0},dz[]={1,0,0,-1,0,0};
	int i,j,k,head,tail;
	while (scanf("%s %d",str,&n)!=EOF){
		memset(f,333,sizeof(f));
		for (i=0;i<n;i++)
			for (j=0;j<n;j++) scanf("%s",map[i][j]);
		//
		//三维数组好坑爹...
		//
		scanf("%d%d%d",&beg[1],&beg[0],&beg[2]);
		scanf("%d%d%d",&end[1],&end[0],&end[2]);
		scanf("%s",str);
		head=-1,tail=0;
		queue[0].x=beg[0],queue[0].y=beg[1],queue[0].z=beg[2];
		f[beg[2]][beg[0]][beg[1]]=0;
		queue[0].val=0;
		//printf("%c\n",map[0][1][1]);
		while (head<tail){
			head++;
			cur=queue[head];
			//printf("(%d %d %d) %d\n",cur.x,cur.y,cur.z,f[cur.z][cur.x][cur.y]);
			for (i=0;i<6;i++){
				x=cur.x+dx[i];
				y=cur.y+dy[i];
				z=cur.z+dz[i];
			
				if (x>=n||x<0||y>=n||y<0||z>=n||z<0) continue;
				if (map[z][x][y]=='X') continue;
				if (cur.val+1>=f[z][x][y]) continue;
				f[z][x][y]=cur.val+1;
				tail++;
				queue[tail].val=cur.val+1;
				queue[tail].x=x,queue[tail].y=y,queue[tail].z=z;
			}
		}
		if (f[end[2]][end[0]][end[1]]>INF) puts("NO ROUTE");
		else printf("%d %d\n",n,f[end[2]][end[0]][end[1]]);
	}
	return 0;
}
