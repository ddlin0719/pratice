 /*
Yifenfei very like play a number game in the n*n Matrix.
 A positive integer number is put in each area of the Matrix.
Every time yifenfei should to do is that choose a detour 
which frome the top left point to the bottom right point and 
than back to the top left point with the maximal values of sum
 integers that area of Matrix yifenfei choose. But from the top
to the bottom can only choose right and down, from the bottom
 to the top can only choose left and up. And yifenfei can not
pass the same area of the Matrix except the start and end. 
*/
#include <stdio.h>
#include <string.h>
int max(int a,int b,int c=0,int d=0){
	if (a<b) a=b;
	if (a<c) a=c;
	if (a<d) a=d;
	return a;
}
int main(){
	int n,map[33][33],f[66][33][33];
	int i,j,k,m;
	memset(map,0,sizeof(map));
	while (scanf("%d",&n)!=EOF){
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++) scanf("%d",&map[i][j]);
		memset(f,0,sizeof(f));
		m=2*n-2;
		for (k=1;k<m;k++)
			for (i=1;i<=k+1;i++)
				for (j=1;j<=k+1;j++){
					if (i>n||j>n||i==j) continue;
					f[k][i][j]=max(f[k-1][i][j],f[k-1][i-1][j],f[k-1][i][j-1],f[k-1][i-1][j-1]),
					f[k][i][j]+=map[i][2+k-i]+map[j][2+k-j];
				}
		//	printf("%d\n",f[2][2][3]);
		f[k][n][n]=max(f[k-1][n-1][n],f[k-1][n][n-1])+map[1][1]+map[n][n];
		printf("%d\n",f[k][n][n]);
	}
	return 0;
}