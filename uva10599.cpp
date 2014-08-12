#include <stdio.h>
#include <string.h>
int map[111][111],id[11111],r,c;
int len[11111],tot[11111],pre[11111];
int n;
//这题目解答第一次看不懂, 第二天才能理解... 
//第一次想用个二维数组递推的, 最长路径是求出来了, 但路径数目发现被卡住了
//这个看了题解发现是转化为LIS 
void print_path(int cur){
	if (pre[cur]!=-1) print_path(pre[cur]);
	if (!map[r][c]&&cur==n-1) return;
	printf(" %d",id[cur]+1);
}
int main(){
	int T=0;
	int i,j,x,y;

	while (scanf("%d%d",&r,&c),r+c!=-2){
		memset(map,0,sizeof(map));
		n=0;
		while (scanf("%d%d",&x,&y),x|y) map[x][y]=1;
		for (i=1;i<=r;i++)
			for (j=1;j<=c;j++)
				if (map[i][j]) id[n++]=(i-1)*c+j-1;	//必须-1,不然取余时右边界出错 
		//这种边界处理条件也很坑好不好... 
		if (!map[r][c]) id[n++]=r*c-1;
		
		for (i=0;i<n;i++) len[i]=1,tot[i]=1,pre[i]=-1;
		
		for (i=1;i<n;i++)
			for (j=0;j<i;j++)
				if (id[j]%c<=id[i]%c){
					//这种状态转移条件还是第一次见.. 
					if (len[j]+1==len[i]) tot[i]+=tot[j];
					if (len[j]+1>len[i]) tot[i]=tot[j],len[i]=len[j]+1,pre[i]=j;
				}
		if (!map[r][c]) len[n-1]--;
//		for (i=0;i<n;i++) printf("%d ",len[i]);printf("\n");
		printf("CASE#%d: %d %d",++T,len[n-1],tot[n-1]);
		print_path(n-1);
		printf("\n");
	}
	return 0;
}
