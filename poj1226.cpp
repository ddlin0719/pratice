#include <stdio.h>
#include <string.h>
char str[101][101];
int n,x,len[101];
int ok(int beg,int end,int id){
	int ii,i,j;
	if (id==x) return 1;
	for (i=0;i<len[id];i++){
			ii=i; 
			
			j=beg;
			while (j<end&&i<len[id]&&str[id][i]==str[x][j]) j++,i++;
			if (j==end) return 1;

			i=ii; j=end-1;
			while (j>=beg&&i<len[id]&&str[id][i]==str[x][j]) j--,i++;
			if (j<beg) return 1;

			i=ii;
		}
	return 0;
}

int main(){
	int T;
	int i,j,k,min;
	scanf("%d",&T);
	while (T--){
		min=111;
		scanf("%d%*c",&n);
		for (i=0;i<n;i++){
			gets(str[i]);
			len[i]=strlen(str[i]);
			if (min>len[i]) min=len[i],x=i;
		}
		for (i=min;i;i--){
			for (j=0;j+i<=min;j++){
				for (k=0;k<n;k++)
					if (!ok(j,i+j,k)) break;
				if (k==n) break;
			}
			if (k==n) break;
		} 
		printf("%d\n",i);
	}
	return 0;
}