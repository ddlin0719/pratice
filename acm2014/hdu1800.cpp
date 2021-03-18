/*
In the year 8888, the Earth is ruled by the PPF Empire . As the population growing , PPF needs to
 find more land for the newborns . Finally , PPF decides to attack Kscinow who ruling the Mars .
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void * a,const void * b){
	char *aa=(char *)a;
	char *bb=(char *)b;
	return strcmp(aa,bb);
}
int main(){
	int n,i,j;
	char arr[3001][33];
	int tot,max;
	//8
	//printf("%d\n",sizeof(__int64));
	while (scanf("%d%*c",&n)!=EOF){
		for (i=0;i<n;i++){
			while (1){
				arr[i][0]=getchar();
				if (arr[i][0]=='\n'||arr[i][0]!='0') break;
			}
			if (arr[i][0]=='\n'){
				arr[i][0]='0';
				arr[i][1]=0;
				continue;
			}
			for (j=1;(arr[i][j]=getchar())!='\n';j++);
			arr[i][j]=0;
		}
		qsort(arr,n,sizeof(arr[0]),cmp);
		//一开始写的算法, 发现不太好, 看答案去了
		//其实也不一定要有序
		//for (i=0;i<n;i++) printf("%d\n",strlen(arr[i]));
		/*
		while (1){
			pre=-1;
			for (i=0;i<n;i++)
				if (arr[i]>pre)	pre=arr[i],arr[i]=-1;
			if (pre==-1) break;
			tot++;
		}
		*/
		tot=1,max=0;
		for (i=1;i<n;i++)
			if (strcmp(arr[i],arr[i-1])==0) tot++;
			else{
				if (max<tot) max=tot;
				tot=1;
			}
		//这句话, 泪奔了...
		if (max<tot) max=tot;
		printf("%d\n",max);
	}
	return 0;
}
