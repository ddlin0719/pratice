#include <stdio.h>
#include <string.h>
#define INF 1000010000
int digit(char c){
	return (c>='0'&&c<='9');
}
int min(int a,int b){
	if (a>b) return b;
	return a;
}
int main(){
	int i,j,k,s,n,m;
	int cost[122],tea[122],cnt[10];
	char str[1010];
	int f[260][260];
	int st1,st2;
	while (scanf("%d%d%d",&s,&m,&n),n|m|s){
		memset(tea,0,sizeof(tea));
		memset(cnt,0,sizeof(cnt));
		for (i=0;i<m+n;i++){
			scanf("%d",&cost[i]);
			gets(str);
			for (j=0;str[j];j++){
				if (!digit(str[j])) continue;
				if (i<m) cnt[str[j]-'0'-1]++;
				tea[i]|=(1<<(str[j]-'0'-1));
			}
		}
		st1=st2=0;
		for (i=0;i<8;i++){
			if (cnt[i]>=1) st1|=1<<i;
			if (cnt[i]>=2) st2|=1<<i;
		}
		int maxs=(1<<s)-1;
		for (i=0;i<=maxs;i++)
			for (j=0;j<=maxs;j++) f[i][j]=INF;
		f[st1][st2]=0;
		for (i=0;i<m;i++) f[st1][st2]+=cost[i];
		for (i=m;i<n+m;i++){
//			for (int s1=0;s1<=maxs;s1++)
//				for (int s2=0;s2<=maxs;s2++){
			for (int s1=maxs;s1>=0;s1--)
				for (int s2=maxs;s2>=0;s2--){
					if (f[s1][s2]==INF) continue;
					st1=(s1|tea[i]);
					st2=(s2|(s1&tea[i]));
					f[st1][st2]=min(f[st1][st2],f[s1][s2]+cost[i]);
				}
		
		}
		printf("%d\n",f[maxs][maxs]);
	}
}
			
