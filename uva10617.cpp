#include <stdio.h>
#include <string.h>
char str[66];
long long f[66][66];
long long dp(int le,int ri){
	if (f[le][ri]!=-1){
	}
	else if (le==ri){
		f[le][ri]=1;
	}
	else if (le>ri){
		f[le][ri]=0;
	}
	else if (str[le]==str[ri]){
		f[le][ri]=dp(le,ri-1)+dp(le+1,ri)+1;
	}
	else {
		f[le][ri]=dp(le,ri-1)+dp(le+1,ri)-dp(le+1,ri-1);
	}
	return f[le][ri];
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		memset(f,-1,sizeof(f));
		scanf("%s",str);
		printf("%lld\n",dp(0,strlen(str)-1));
	}
	return 0;
}