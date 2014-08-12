#include <stdio.h>
#include <string.h>
#define LL long
//#define LL __int64
LL f[303][303];
//num个硬币, tot的总钱数
//用1~num个钱币组成价值tot的总个数
//这个dp函数不懂.....
LL dp(int num,int tot){
	if (f[num][tot]!=0) return f[num][tot];
	//for (int i=1;i<num&&tot-i>=num-1;i++)
	for (int i=1;i<=num&&tot-i>=0;i++)
		//f[num][tot]+=dp(num-1,tot-i);
		f[num][tot]+=dp(i,tot-i);
	return f[num][tot];
}
int main(){
	LL ans;
	int n,arr[2],i,j,k;
	memset(f,0,sizeof(f));
	for (i=0;i<=300;i++) f[i][0]=1;
	for (i=1;i<=300;i++)
		//for (j=i;j<=300;j++)
		for (j=1;j<=300;j++)
			f[i][j]=dp(i,j);
	//printf("%lld %lld\n",f[2][6],f[299][100]);
	while (scanf("%d",&n)!=EOF){
		i=0;
		while (getchar()!='\n') scanf("%d",&arr[i++]);
		if (arr[0]>300) arr[0]=300;
		if (arr[1]>300) arr[1]=300;
		if (i==0) ans=f[n][n];
		if (i==1) ans=f[arr[0]][n];
		if (i==2){
			if (arr[0]<=1) ans=f[arr[1]][n];
			else ans=f[arr[1]][n]-f[arr[0]-1][n];
		}
		printf("%lld\n",ans);
		//printf("%I64d\n",ans);
	}
	return 0;
}
