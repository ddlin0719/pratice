#include <stdio.h>
#include <string.h>
int a,b,firstx[300],firsty[300];
char map[33][33];
int get_end(char flag,int para){
	int i,j;
	if (para==0){
		for (i=a-1;i>=0;i--)
			for (j=0;j<b;j++)
				if (map[i][j]==flag) return i;
	}
	if (para==1){
		for (j=b-1;j>=0;j--)
			for (i=0;i<a;i++)
				if (map[i][j]==flag) return j;
	}
	return 0;
}
void get_first(){
	memset(firstx,-1,sizeof(firstx));
	memset(firsty,-1,sizeof(firsty));
	for (int i=0;i<a;i++)
		for (int j=0;j<b;j++)
			if (map[i][j]!='.'&&firstx[map[i][j]]==-1)
				firstx[map[i][j]]=i,firsty[map[i][j]]=j;
}

int top(int x,int y,char flag){
	int x1,y1,x2,y2;
	int endx,endy;
	if (x>firstx[flag]||y>firsty[flag]) return 0;
	x2=x1=x,y2=y1=y;
	endx=get_end(flag,0),endy=get_end(flag,1);
	while (x1<=endx&&(map[x1][y1]==flag||map[x1][y1]=='.')) x1++;
	x1--;
	while (y1<=endy&&(map[x1][y1]==flag||map[x1][y1]=='.')) y1++;
	y1--;

	while (y2<=endy&&(map[x2][y2]==flag||map[x2][y2]=='.')) y2++;
	y2--;
	while (x2<=endx&&(map[x2][y2]==flag||map[x2][y2]=='.')) x2++;
	x2--;

	return (x1==x2&&y1==y2);
}
void del(int x,int y,char flag){
	int x1,y1,x2,y2;
	int endx,endy;
	x2=x1=x,y2=y1=y;
	endx=get_end(flag,0),endy=get_end(flag,1);
	while (x1<=endx){
		if (map[x1][y1]==flag) map[x1][y1]='.';
		x1++;
	}
	x1--;
	while (y1<=endy){
		if (map[x1][y1]==flag) map[x1][y1]='.';
		y1++;
	}

	while (y2<=endy){
		if (map[x2][y2]==flag) map[x2][y2]='.';
		y2++;
	}
	y2--;
	while (x2<=endx){
		if (map[x2][y2]==flag) map[x2][y2]='.';
		x2++;
	}
}
void print(int x,int y){
	printf("%d %d\n",x,y);
	for (int i=0;i<a;i++)
		puts(map[i]);
	getchar();
}
int main(){
	int i,j; 
	char ans[33],po;
	while (~scanf("%d%d",&a,&b)){
		for (i=0;i<a;i++) scanf("%s",map[i]);
		po=-1;
		get_first();
		//print();
		for (i=0;i<a;i++)
			for (j=0;j<b;j++)
				if (map[i][j]!='.'&&top(i,j,map[i][j])){
					//printf("%c",map[i][j]);
					ans[++po]=map[i][j];
					del(i,j,map[i][j]);
					//print(i,j);
					i=-1;
					break;
				}
		while (po>=0) putchar(ans[po--]);
		printf("\n");
	}
	return 0;
}