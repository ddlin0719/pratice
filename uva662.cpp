#include <stdio.h>
#include <string.h>
int arr[202],f[202][33],dist[202][202];
int pos[33][2];
int abs(int a){
	if (a<0) return -a;
	return a;
}
int dp(int n,int m){
	int i,tmp;
	if (f[n][m]!=-1) return f[n][m];
	if (m==1){
//		pos[m][0]=0;
//		pos[m][1]=n;
//		printf("%d : %d %d: %d\n",m,pos[m][0],pos[m][1],dist[0][n]);
		return f[n][m]=dist[0][n];
	}
	f[n][m]=1<<30;
	for (i=m-2;i<n;i++){
		tmp=dp(i,m-1)+dist[i+1][n];
		if (f[n][m]>tmp){
//			这些pos没用的,打印出来的路径是错误的.... 
//			pos[m][0]=i+1;
//			pos[m][1]=n;
			f[n][m]=tmp;
//			printf("%d : %d %d :%d\n",m,pos[m][0],pos[m][1],tmp);
		}
	}
//	printf("%d\n",f[n][m]);
	return f[n][m];
}
void print(int a,int b,int m){
		if (a!=b)
				printf("Depot %d at restaurant %d serves restaurants %d to %d\n",
						m,(a+b)/2,a,b);
			else printf("Depot %d at restaurant %d serves restaurant %d\n",
						m,a,a);
}
void print_path(int m,int n){
	if (m==1){
		print(1,n+1,m);
		return ;
	}
	for (int i=m-2;i<n;i++)
		if (f[n][m]==f[i][m-1]+dist[i+1][n]){
			print_path(m-1,i);
			print(i+2,n+1,m);
			break;
		}
}
int main(){
	int n,m,i,j,k,T=0;
	while(scanf("%d%d",&n,&m),n|m){
		for (i=0;i<n;i++) scanf("%d",&arr[i]);
		memset(f,-1,sizeof(f));
		memset(dist,0,sizeof(dist));
		for (i=0;i<n;i++)
			for (j=i;j<n;j++)
				for (k=i;k<=j;k++) dist[i][j]+=(abs(arr[k]-arr[(i+j)/2]));
//		printf("%d\n",dist[0][2]);
		int tot=dp(n-1,m);
		
//		epos[1][1]=pos[2][0]-1;
//		pos[1][0]=0;
//		
		printf("Chain %d\n",++T);
//		for (i=m-1;i>1;i--){
//			for (j=0;j<pos[i+1][0]-1;j++)
//				if (f[0][j]+dist[j+1][pos[i+1][0]-1]==f[0][pos[i+1][0]-1]) break;
//			pos[i][0]=j+1;
//			pos[i][1]=pos[i+1][0]-1;
//		}

//		if(m==1) pos[1][1]=n-1;else pos[1][1]=pos[2][0]-1;
//		pos[1][0]=0; 
//		for (i=1;i<=m;i++){
//			if (pos[i][0]!=pos[i][1])
//				printf("Depot %d at restaurant %d serves restaurants %d to %d\n",
//						i,(pos[i][0]+pos[i][1])/2+1,pos[i][0]+1,pos[i][1]+1);
//			else printf("Depot %d at restaurant %d serves restaurant %d\n",
//						i,pos[i][0]+1,pos[i][0]+1);
//		}
		print_path(m,n-1);
		printf("Total distance sum = %d\n\n",tot);
	}
	return 0;
}
