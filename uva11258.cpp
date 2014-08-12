#include <stdio.h>
#include <string.h>
#define maxn 0x7fffffff
long long max(long long x,long long y){
	if (x>y) return x;
	return y;
}
int main(){
	int T,i,j;
	int n;
	long long num[222][222],f[222];
	char str[222];
	scanf("%d%*c",&T);
	memset(num,0,sizeof(num));
	while (T--){
		scanf("%s",str);
		n=strlen(str);
		for (i=0;i<n;i++)
			for (j=i;j<n;j++){
				num[i][j]=num[i][j-1]*10+str[j]-'0';
				if (num[i][j]>maxn)
					while (j<n) num[i][j]=-1,j++;
			}
		f[0]=str[0]-'0';
		for (i=1;i<n;i++){
			f[i]=0;
			for (j=i;j>0;j--){
				if (num[j][i]==-1) break;
				f[i]=max(f[i],f[j-1]+num[j][i]);
			}
			f[i]=max(f[i],num[j][i]);
		}
		printf("%lld\n",f[n-1]);
	}
	return 0;
}
		
