#include <stdio.h>
#include <string.h>
int n,m,num[1000],flag[5000],ans[5000];
void sort(int* num){
	int i,j,tmp;
	for (i=0;i<m;i++)
		for (j=i+1;j<m;j++)
			if (num[i]>num[j])
				tmp=num[i],num[i]=num[j],num[j]=tmp;
}
void print(int cur){
	for (int i=0;i<=cur;i++)
		printf("%d",ans[cur]);
	printf("\n");
}
int dfs(int cur){
	int i,tmp;
	for (i=0;i<m;i++){
		tmp=num[i];
		if (cur==0&&tmp==0) continue;
		if (cur) tmp=tmp*10+ans[cur-1];
		if (flag[tmp%n]) continue;
		flag[tmp%n]=1;
		ans[cur]=num[i];
		if (tmp%n==0&&ans[0]!=0){
			print(cur);
			return 1;
		}
		
		dfs(cur+1);
	}
	return 0;
}

int main(){
	int i;
	while (~scanf("%d",&n)){
		memset(flag,0,sizeof(flag));
		scanf("%d",&m);
		for (i=0;i<m;i++) scanf("%d",&num[i]);
		sort(num);
		if (!dfs(0)) printf("0\n");
	}
	return 0;
}

		