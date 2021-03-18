/*今年的ACM暑期集训队一共有18人，分为6支队伍。其中有一个叫做EOF的队伍
，由04级的阿牛、XC以及05级的COY组成。在共同的集训生活中，大家建立了
深厚的友谊，*/
#include <stdio.h>

int main(){
	int i,j,n;
	__int64 ans[42]={0,3,8};
	for (i=3;i<42;i++)
		ans[i]=2*(ans[i-1]+ans[i-2]);
	while (scanf("%d",&n)!=EOF){
		printf("%I64d\n",ans[n]);
	}
	return 0;
}