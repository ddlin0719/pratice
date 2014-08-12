#include <stdio.h>
#include <string.h>
char queue[33],map[33][33];
int ru[33],a;

int topsort(){
	int i,j,k,_ru[33];
	for (i=0;i<a;i++) _ru[i]=ru[i];
	for (k=0;k<a;k++){
		for (i=0;i<a;i++)
			if (_ru[i]==0) break;
		if (i==a) return -1;
		queue[k]=i+'A';
		queue[k+1]=0;
		_ru[i]=-1; 
		for (j=i+1;j<a;j++)
			//有环和无法判断, 优先判断有环
			//所以这里不能直接返回,必须弄完所有
			//if (_ru[j]==0) return 0
			if (_ru[j]==0) queue[0]=0;
		for (j=0;j<a;j++)
			if (map[i][j]) _ru[j]--;
	}
	if (queue[0]==0) return 0;
	queue[k]=0;
	return 1;
}

int main(){
	int i,b;
	int ans,stop;
	char x,y;
	while (scanf("%d%d%*c",&a,&b),a+b ){
		memset(ru,0,sizeof(ru));
		memset(map,0,sizeof(map));
		//memset(exist,0,sizeof(exist));
		ans=0;
		for (i=0;i<b;i++){
			scanf("%c<%c%*c",&x,&y);
			ru[y-'A']++;
			map[x-'A'][y-'A']=1;
			if (0==ans){
				ans=topsort();
				//puts(queue);
				stop=i;
			}
		}
		if (ans==0)  printf("Sorted sequence cannot be determined.\n");
		if (ans==-1) printf("Inconsistency found after %d relations.\n",stop+1);
		if (ans==1)  printf("Sorted sequence determined after %d relations: %s.\n",stop+1,queue);
	}
	return 0;
}