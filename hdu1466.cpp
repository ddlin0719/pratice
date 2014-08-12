#include <stdio.h>
int main(){
	//n条直线互不平行且无三线共点的最多交点数max=1+2+……(n-1)=n(n-1)/2,
	//所以n=20的话，最大的交点数是190
	int i,j,k,f[22][200];
	int n,m;
	//初始化
	for (i=0;i<22;i++)
		for (j=0;j<200;j++)
			if (j==0) f[i][j]=1;
			else f[i][j]=0;
	for (i=1;i<22;i++)//枚举边的总数
		for (j=0;j<i;j++)//枚举非平行边数目,都是平行边上面已经算过了,不要枚举了
			for (k=0;k<200;k++)//枚举定点总数
				if (f[j][k]&&j*(i-j)+k<200)
					f[i][j*(i-j)+k]=1;
	while (~scanf("%d",&n)){
		m=n*(n-1)/2;
		for (i=0;i<m;i++)
			if (f[n][i]) printf("%d ",i);
		printf("%d\n",i);
	}
	return 0;
}