#include <stdio.h>
#include <string.h>
//long long 坑了我一个小时@_@ 
long long f[44][44][400];
int n,S,map[44][44],num[44];
/*
记忆化搜索超时了 
void dp1(int r,int c,int s){
	if (s>S) return;
	if (r<n-1)return;
	c-=1;
	if (c>=0)
		f[r][c][s+map[r][c]]+=1, dp1(r-1,c,s+map[r][c]);
	c+=1;
	if (c<num[r]) 
		f[r][c][s+map[r][c]]+=1, dp1(r-1,c,s+map[r][c]);
}
void dp2(int r,int c,int s){
	//printf("(%d %d):%d\n",r+1,c,s);
	if (s>S) return;
	if (r<0){
		//if (s==S) tot++;
		return ;
	}
	f[r][c][s+map[r][c]]+=1, dp2(r-1,c,s+map[r][c]);
	c+=1;
	f[r][c][s+map[r][c]]+=1, dp2(r-1,c,s+map[r][c]);
}
*/
void print_path(int r,int c,int s){
	printf("%d ",c);
	while (r<n-1){
		if (c>0&&f[r+1][c-1][s-map[r][c]]){
			s-=map[r][c];
			putchar('L'); c--;
		}else if (c<num[r+1]&&f[r+1][c][s-map[r][c]]){
			s-=map[r][c];
			putchar('R');
		}
		r++;
	}
	while (r<n+n-2){
		if (f[r+1][c][s-map[r][c]]){
			s-=map[r][c];
			putchar('L');
		}else{
			s-=map[r][c];
			c++;
			putchar('R');
		}
		r++;
	}
}
int main(){
	int i,j,s;
	while (scanf("%d%d",&n,&S),n|S){
		for (i=0;i<n;i++){
			num[i]=n-i;
			for (j=0;j<n-i;j++) scanf("%d",&map[i][j]);
		}
		for (;i<n+n-1;i++){
			num[i]=i-n+2;
			for (j=0;j<i-n+2;j++) scanf("%d",&map[i][j]);
		}
		memset(f,0,sizeof(f));
		for (j=0;j<n;j++) 
			f[n+n-2][j][map[n+n-2][j]]=1;
			
//			dp1(n+n-3,j,map[n+n-2][j]);
//		for (s=0;s<=9*n;s++)
//			//if (f[n-1][0][s]) dp(n-2,0,s);
//			for (i=0;i<f[n-1][0][s];i++) dp2(n-2,0,s);

		for (i=n+n-3;i>=n-1;i--)
			for (j=0;j<num[i];j++)
				for (s=0;s<=S;s++){
					f[i][j][s+map[i][j]]+=f[i+1][j][s]+f[i+1][j+1][s];
				}
		for (;i>=0;i--)
			for (j=0;j<num[i];j++)
				for (s=0;s<=S;s++){
					f[i][j][s+map[i][j]]+=f[i+1][j][s];
					if (j) f[i][j][s+map[i][j]]+=f[i+1][j-1][s];
				}
		long long tot=0;
		for (j=0;j<n;j++){
			if (tot==0) i=j;
			tot+=f[0][j][S];
		}
		printf("%lld\n",tot);
		if (tot) print_path(0,i,S);
		printf("\n");
	}
	return 0;
}
