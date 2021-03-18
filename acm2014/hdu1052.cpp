#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
	int *aa=(int *)a;
	int *bb=(int *)b;
	return *bb-*aa;
}
/*
Solution�������ж��ֽ���˼·��DP������ͼ���ƥ���㷨�ȣ�����������ǱȽ���������̰���㷨

�Ƚ���ɸ�����������ٶ��������һ��ð������

1�������������������������죬���֮

2����������������������������������������������������� 

3����������������ٶ����������������ٶ����

3.1�������������ı������������Ŀ죬���֮                       

3.2�������������ı����������������������VS������

3.3���������������������������ȣ������VS������

*/
int main(){
	int a[1010],b[1010];
	int i,j,n;
	int bega,enda,begb,endb,tot;
	while (scanf("%d",&n),n){
		for (i=0;i<n;i++) scanf("%d",&a[i]);
		for (i=0;i<n;i++) scanf("%d",&b[i]);
		qsort(a,n,sizeof(a[0]),cmp);
		qsort(b,n,sizeof(b[0]),cmp);
		bega=begb=0,enda=endb=n-1;
		tot=0;
		for (i=0;i<n;i++){
			if (a[bega]>b[begb]){
				bega++,begb++;
				tot++;
				continue;
			}
			if (a[bega]<b[begb]){
				if (a[enda]>b[begb]) tot++;
				else if (a[enda]<b[begb]) tot--;
				enda--,begb++;
				continue;
			}
			if (a[enda]>b[endb]){
				enda--,endb--;
				tot++;
				continue;
			}
			if (a[enda]<b[endb]){
				if (a[enda]>b[begb]) tot++;
				else if (a[enda]<b[begb])  tot--;
				enda--,begb++;
				continue;
			}
			if (a[enda]==b[endb]){
				if (a[enda]>b[begb]) tot++;
				else if (a[enda]<b[begb]) tot--;
				enda--,begb++;
				continue;
			}
		}
		printf("%d\n",tot*200);
	}
	return 0;
}