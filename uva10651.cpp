#include <stdio.h>
#include <string.h>
int main(){
	int T,i,j,ans,tot;
	int head,tail;
	char state[10001][13],*cur;
	scanf("%d%*c",&T);
	while (T--){
		gets(state[0]);
		ans=12;
		head=-1,tail=0;
		while (head<tail){
			head++;
			cur=state[head];
			tot=0;
			for (i=0;i<12;i++) tot+=(cur[i]=='o');
			if (tot<ans) ans=tot;
			for (i=0;i<12;i++){
				if (i>=2&&cur[i]=='o'&&cur[i-1]=='o'&&cur[i-2]=='-'){
					tail++;
					strncpy(state[tail],cur,12);
					state[tail][i]=state[tail][i-1]='-';
					state[tail][i-2]='o';
				}
				if (i<=9&&cur[i]=='o'&&cur[i+1]=='o'&&cur[i+2]=='-'){
					tail++;
					strncpy(state[tail],cur,12);
					state[tail][i]=state[tail][i+1]='-';
					state[tail][i+2]='o';
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}