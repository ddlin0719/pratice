/*�����ACM���ڼ�ѵ��һ����18�ˣ���Ϊ6֧���顣������һ������EOF�Ķ���
����04���İ�ţ��XC�Լ�05����COY��ɡ��ڹ�ͬ�ļ�ѵ�����У���ҽ�����
�������꣬*/
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