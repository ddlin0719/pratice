#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 1000100
int arr[n+1],_arr[n+1];
int partition(int * arr,int le,int ri){
	int x=arr[le],l=le+1,r=ri,tmp;
	while (1){
		//printf("%d %d %d %d %d\n",l,r,arr[l],arr[r]);
		while (arr[l]<x&&l<ri) l++;
		while (arr[r]>x&&r>le) r--;
		if (l>=r) break;
		tmp=arr[l],arr[l]=arr[r],arr[r]=tmp;
		//勿漏了这一句
		//不然死循环
		l++,r--;
	}
	arr[le]=arr[r],arr[r]=x;
	return r;
}
void quickSort(int * arr,int beg,int end){
	if (beg>=end) return ;
	int p=partition(arr,beg,end);
	quickSort(arr,beg,p-1);
	quickSort(arr,p+1,end);
}
int cmp(const void * a,const void * b){
	int * aa=(int *)a;
	int * bb=(int *)b;
	return *aa-*bb;
}	
void init(){
	int i;
	srand(time(NULL));
	for (i=0;i<n;i++)
		arr[i]=rand()+rand()-rand(),_arr[i]=arr[i];
}
int check(){
	for (int i=0;i<n;i++)
		if (arr[i]!=_arr[i]) return 0;
	return 1;
}
void run(){
	int tot=50;
	while (tot--){
		init();
		quickSort(arr,0,n-1);
		qsort(_arr,n,sizeof(_arr[0]),cmp);
		if (!check()) break;
		else puts("ok");
	}
	if (tot!=-1) puts("error!");
}
int main(){
	run();
	return 0;
}