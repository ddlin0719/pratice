#include <stdio.h>
int main(){
	//n��ֱ�߻���ƽ���������߹������ཻ����max=1+2+����(n-1)=n(n-1)/2,
	//����n=20�Ļ������Ľ�������190
	int i,j,k,f[22][200];
	int n,m;
	//��ʼ��
	for (i=0;i<22;i++)
		for (j=0;j<200;j++)
			if (j==0) f[i][j]=1;
			else f[i][j]=0;
	for (i=1;i<22;i++)//ö�ٱߵ�����
		for (j=0;j<i;j++)//ö�ٷ�ƽ�б���Ŀ,����ƽ�б������Ѿ������,��Ҫö����
			for (k=0;k<200;k++)//ö�ٶ�������
				if (f[j][k]&&j*(i-j)+k<200)
					f[i][j*(i-j)+k]=1;
	while (~scanf("%d",&n)){
		m=n*(n-1)/2;
		for (i=0;i<m;i++)
			if (f[n][i]) printf("%d ",i);
		printf("%d\n",i);
	}
	return 0;
}