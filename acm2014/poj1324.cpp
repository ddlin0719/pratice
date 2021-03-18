#include <stdio.h>
#include <string.h>
struct State{
	int x[8],y[8],val;
};
State queue[100010];
int map[22][22],a,b,len,f[22][22];
int ok(int x,int y,State& cur){
	int i;
	if (x>a||x<1||y>b||y<1) return 0;
	if (!map[x][y]) return 0;
	for (i=0;i<len;i++)
		if (x==cur.x[i]&&y==cur.y[i]) return 0;
	if (f[x][y]<cur.val+1) return 0;
	return 1;
}
int main(){
	State cur,tmp;
	int dx[]={0,0,-1,1},dy[]={1,-1,0,0},_x,_y,x,y;
	int head,tail;
	int i,j,k,step;
	int T=0;
	while (scanf("%d%d%d",&a,&b,&len),a+b+len){
		memset(map,1,sizeof(map));
		memset(f,333,sizeof(f));
		for (i=0;i<len;i++)
			scanf("%d%d",&queue[0].x[i],&queue[0].y[i]);
		queue[0].val=0;
		scanf("%d",&k);
		while (k--){
			scanf("%d%d",&i,&j);
			map[i][j]=0;
		}
		head=-1,tail=0,step=-1;
		f[queue[0].x[0]][queue[0].y[0]]=0;
		while (head!=tail){
			head++;
			cur=queue[head];
			x=cur.x[0],y=cur.y[0];
			//printf("%d %d %d\n",x,y,cur.val);
			//for (j=0;j<len;j++) printf("(%d %d) ",cur.x[j],cur.y[j]);
			//printf("\n");
			if (x==1&&y==1){
				step=cur.val;
				break;
			}
			for (i=0;i<4;i++){
				_x=x+dx[i],_y=y+dy[i];
				if (!ok(_x,_y,cur)) continue;
				tail++;
				f[_x][_y]=cur.val+1;
				State state;
				state.x[0]=_x,state.y[0]=_y,state.val=cur.val+1;
				for (j=1;j<len;j++) 
					state.x[j]=cur.x[j-1],state.y[j]=cur.y[j-1];
				queue[tail]=state;
			}
		}
		printf("Case %d: %d\n",++T,step);
	}
	return 0;
}
				

	