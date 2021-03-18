#include <stdio.h>
#include <string.h>
void swap(int &a,int &b){
	int tmp;
	tmp=a,a=b,b=tmp;
}
int main(){
	//front, back, left, right, top, bottom
	//4:top 5:bottom
	char dir[][7]={"top","front", "back", "left", "right", "bottom"};
	int T=0;
	int n,i,j,k,cube[3003][6],pre[3003],f[3003];
	int ans[3003];
	while (scanf("%d",&n),n){
		for (i=0;i<n*6;i+=6){
			for (j=0;j<6;j++) scanf("%d",&cube[i][j]);
			k=i;
			for (j=0;j<6;j++)
				if (j!=4){
					k++;
					memcpy(cube[k],cube[i],sizeof(cube[i]));
					swap(cube[k][4],cube[k][j]);
					if (j==5) break;
					if (j%2==0) swap(cube[k][j+1],cube[k][5]);
					else swap(cube[k][j-1],cube[k][5]);
				}
		}
		/*
		for (i=0;i<n*6;i++){
			for (j=0;j<6;j++) printf("%d ",cube[i][j]);
			printf("\n");
		}
		*/
		//0-5都要初始化
		//f[0]=1
		for (i=0;i<6;i++) f[i]=1;
		memset(pre,-1,sizeof(pre));
		for (i=6;i<n*6;i++){
			int inum=i/6;
			int max=-1;
			for (j=0;j<i;j++){
				int jnum=j/6;
				if (inum>jnum&&cube[i][4]==cube[j][5]&&f[j]>max)
					max=f[j],k=j;
			}
			if (max!=-1){
				f[i]=max+1;
				pre[i]=k;
			}else{
				//勿漏这句
				f[i]=1;
			}
		}
		if (T) printf("\n");
		printf("Case #%d\n",++T);
		int max=f[0],k=0;
		//for (i=0;i<n*6;i++) printf("%d ",f[i]); printf("\n");
		for (i=1;i<n*6;i++)
			if (f[i]>max) max=f[i],k=i;
		printf("%d\n",max);
		i=0;
		ans[0]=k;
		while (pre[k]!=-1){
			ans[++i]=pre[k];
			k=pre[k];
		}
		while (i>=0){
			printf("%d %s\n",ans[i]/6+1,dir[ans[i]%6]);
			i--;
		}
	}
	return 0;
}

