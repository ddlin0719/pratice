#include <stdio.h>
#include <string.h>
#define LL long
int tran(char ch){
	if (ch>='0'&&ch<='9') return ch-'0';
	return ch-'A'+10;
}
int main(){
	char str[101];
	int n,i,j,k;
	LL dp[101][101],sum;
	//阴我.....
	//每行字符后面可能有空格....
	//while (gets(str+1)){
	while (scanf("%s",str+1)!=EOF){
		memset(dp,0,sizeof(dp));
		n=strlen(str+1);
		if (str[1]=='?')
			for (i=1;i<=n;i++) dp[i][1]=1;
		else
			dp[tran(str[1])][1]=1;
		for (i=2;i<=n;i++){
			if (str[i]=='?'){
				for (j=1;j<=n;j++)
					for (k=1;k<=n;k++)
						if (k!=j&&k!=j-1&&k!=j+1)
							dp[j][i]+=dp[k][i-1];
			}
			else{
				j=tran(str[i]);
				for (k=1;k<=n;k++)
					if (k!=j&&k!=j-1&&k!=j+1)
						dp[j][i]+=dp[k][i-1];
			}
		}
		sum=0;
		for (i=1;i<=n;i++) sum+=dp[i][n];
		printf("%lld\n",sum);
	}
	return 0;
}


