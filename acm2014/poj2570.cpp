#include <stdio.h>
#include <string.h>
int main(){
	int map[202][202],a,b,flag;
	char str[33];
	int n,i,j,k;
	while (scanf("%d",&n),n){
		memset(map,0,sizeof(map));
		while (scanf("%d%d",&a,&b),a+b){
			scanf("%s",str);
			for (i=0;str[i];i++)
				map[a][b]|=1<<(str[i]-'a');
		}
		for (k=1;k<=n;k++)
			for (i=1;i<=n;i++)
				for (j=1;j<=n;j++)
					//for (k=1;k<=n;k++)
					map[i][j]|=(map[i][k]&map[k][j]);
		while (scanf("%d%d",&a,&b),a+b){
			flag=0;
			for (i=0;i<26;i++)
				if ((map[a][b]>>i)&1)
					printf("%c",i+'a'),flag=1;
			if (!flag) printf("-");
			printf("\n"); 
		}
		printf("\n");
	}
	return 0;
}