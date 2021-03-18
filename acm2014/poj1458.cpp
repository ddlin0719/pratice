/*
A subsequence of a given sequence is the given sequence with
 some elements (possible none) left out. Given a sequence X 
 = <x1, x2, ..., xm> another sequence Z = <z1, z2, ..., zk> 
 is a subsequence of X if there exists a strictly increasing
 sequence <i1, i2, ..., ik> of indices of X such that for all 
 j = 1,2,...,k, xij = zj. For example, Z = <a, b, f, c> is a 
 subsequence of X = <a, b, c, f, b, c> with index sequence 
 <1, 2, 4, 6>. Given two sequences X and Y the problem is to 
 find the length of the maximum-length common subsequence of X and Y. 
 */
#include <stdio.h>
#include <string.h>
int f[1001][1001];
int max(int a,int b){
	if (a>b) return a;
	return b;
}
int main(){
	char a[401],b[401];
	int i,j;
	while (scanf("%s%s",a,b)!=EOF){
		memset(f,0,sizeof(f));
		for (i=0;a[i];i++)
			for (j=0;b[j];j++)
				if (a[i]==b[j]) f[i+1][j+1]=f[i][j]+1;
				else f[i+1][j+1]=max(f[i+1][j],f[i][j+1]);
		printf("%d\n",f[i][j]);
	}
	return 0;
}