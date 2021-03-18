#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
	int *aa=(int *)a;
	int *bb=(int *)b;
	return *bb-*aa;
}
/*
Solution：这题有多种解体思路，DP，二分图最大匹配算法等，这里给出的是比较容易理解的贪心算法

先将田忌跟齐王的马的速度数组进行一次冒泡排序

1、如果田忌最快的马比齐王最快的马快，则比之

2、如果田忌最快的马比齐王最快的马慢，则用田最慢的马跟齐最快的马比 

3、如果田忌最快的马的速度与齐威王最快的马速度相等

3.1、如果田忌最慢的比齐威王最慢的快，则比之                       

3.2、如果田忌最慢的比齐威王最慢的慢，田忌慢VS齐王快

3.3、田忌最慢的与齐威王最慢的相等，田忌慢VS齐王快

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