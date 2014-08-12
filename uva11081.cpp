#include <stdio.h>
#include <string.h>
//我们选择用f1[i][j][k]、f2[i][j][k]分别表示拼到第k个字符时的结尾是第一串的、第二串的
int f1[66][66][66],f2[66][66][66],f[66][66][66];
int main(){
	int T,i,j,k;

	int l1,l2,l3;
	char str1[66],str2[66],str3[66];
	scanf("%d",&T);
	while (T--){
		scanf("%s %s %s",str1+1,str2+1,str3+1);
//		printf("%s %s %s\n",str1,str2,str3);
		l1=strlen(str1+1),l2=strlen(str2+1),l3=strlen(str3+1);
		memset(f,0,sizeof(f));
		memset(f1,0,sizeof(f1));
		memset(f2,0,sizeof(f2));
		for (i=0;i<=l1;i++)
			for (j=0;j<=l2;j++)
				f[i][j][0]=1,f1[i][j][0]=1,f2[i][j][0]=1;
//		for (k=0;k<=l3;k++) f[0][0][k]=0;
		for (k=1;k<=l3;k++)
			for (i=0;i<=l1;i++)
				for (j=0;j<=l2;j++){
//					f[i][j][k]=f1[i][j][k]=f2[i][j][k]=0;
					if (i){
						f1[i][j][k]=f1[i-1][j][k];
						if (str1[i]==str3[k])
//							f1[i][j][k]+=f1[i-1][j][k-1],
							f1[i][j][k]+=f[i-1][j][k-1],
							f1[i][j][k]%=10007;
					}
					if (j){
						f2[i][j][k]=f2[i][j-1][k];
						if (str2[j]==str3[k])
//							f2[i][j][k]+=f2[i][j-1][k-1],
							f2[i][j][k]+=f[i][j-1][k-1],
							f2[i][j][k]%=10007;
					}
					f[i][j][k]=(f1[i][j][k]+f2[i][j][k])%10007;
				}
		printf("%d\n",f[l1][l2][l3]);
	}
	return 0;
}
		
