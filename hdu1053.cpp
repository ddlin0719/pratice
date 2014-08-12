/*AAAAABCD
THE_CAT_IN_THE_HAT
END
*/
#include <queue>
#include <vector>
#include <stdio.h>
#include <string.h>
int main(){
	char str[10010];
	int count[260],i,j,a,b,sum;
	std::priority_queue<int,std::vector<int>,std::greater<int> > queue;
	while (gets(str)){
		if (strcmp(str,"END")==0) break;
		memset(count,0,sizeof(count));
		for (i=0;str[i];i++) count[str[i]]++;
		a=i*8;
		for (i=0;i<260;i++)
			if (count[i]) queue.push(count[i]);
		sum=0;
		while (queue.size()>1){
			i=queue.top(),queue.pop();
			j=queue.top(),queue.pop();
			sum+=i+j;
			queue.push(i+j);
			//printf("%d\n",queue.size()); 
		}
		b=queue.top(),queue.pop();
		//sum+=b;
		if(sum==0) sum=b;
		b=sum; 
		printf("%d %d %.1lf\n",a,b,(a+0.0)/b);
	}
	return 0;
}
