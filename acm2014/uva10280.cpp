#include <stdio.h>
#include <string.h>
int min(int a,int b){
	if (a>b) return b;
	return a;
}
int bag[22700],vis[4555],f[501000];
int main(){
	int T,i,j,L,n,m,a[101],b[101];
	int ll,ans;

	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&L,&n);
		ll=1000010000;
		L*=1000;
		for (i=0;i<n;i++) 
			scanf("%d%d",&a[i],&b[i]),ll=min(ll,a[i]*a[i]/(b[i]-a[i]));
		if (L>=ll) ans=0;
		else{
			m=0;
			memset(vis,0,sizeof(vis));
			memset(f,0,sizeof(f));
			for (i=0;i<n;i++)
				for (j=a[i];j<=b[i];j++)
					if (!vis[j]) bag[m++]=j,vis[j]=1;
			f[0]=1;
			for (i=0;i<m;i++)
				for (j=bag[i];j<=L;j++)
					if (f[j-bag[i]]) f[j]=1;
			for (j=L;j>=0;j--)
				if (f[j]) break;
			ans=L-j;
		}
		printf("%d\n",ans);
		if (T) printf("\n");
	}
}

