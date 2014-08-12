/*
Nowadays, a kind of chess game called ¡°Super Jumping! 
Jumping! Jumping!¡± is very popular in HDU. 
Maybe you are a good boy, and know little about this 
game, so I introduce it to you now.
*/
#include <stdio.h>

int main(){
	int arr[1111],f[1111],n;
	int i,j,max;
	while (scanf("%d",&n),n){
		for (i=0;i<n;i++) scanf("%d",&arr[i]);
		f[0]=arr[0];
		for (i=1;i<n;i++){
			max=0;
			for (j=0;j<i;j++)
				if (arr[i]>arr[j]&&f[j]>max)
					max=f[j];
			f[i]=max+arr[i];
		}
		max=f[0];
		for (i=1;i<n;i++)
			if (max<f[i]) max=f[i];
		printf("%d\n",max);
	}
	return 0;
}