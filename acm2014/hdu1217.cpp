#include <stdio.h>
#include <string.h>
int n;
char name[33][111];
double f[33][33];
int locate(char *str){
	int i;
	for (i=0;i<n;i++)
		if (strcmp(str,name[i])==0) break;
	return i;
}
double max(double a,double b){
	if (a<b) a=b;
	return a;
}
int main(){
	int T=0;
	char a[111],b[111];
	double c;
	int m,i,j,k;
	while (scanf("%d",&n),n){
		for (i=0;i<n;i++) scanf("%s",name[i]);
		scanf("%d",&m);
		memset(f,0,sizeof(f));
		for (i=0;i<n;i++) f[i][i]=1;
		while (m--){
			scanf("%s %lf %s",a,&c,b);
			f[locate(a)][locate(b)]=c;
		}
		//memset(f,0,sizeof(f));
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				for (k=0;k<n;k++)
					f[i][j]=max(f[i][j],f[i][k]*f[k][j]);
		for (i=0;i<n;i++)
			if (f[i][i]>1){
				//printf("%d %lf\n",i,f[i][i]);
				break;
			}
		if (i!=n) printf("Case %d: Yes\n",++T);
		else printf("Case %d: No\n",++T);
	}
	return 0;
}