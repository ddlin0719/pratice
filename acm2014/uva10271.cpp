#include <stdio.h>
#include <string.h>
int f[5005];
int min(int a,int b){
	if (a>b) a=b;
	return a;
}
int main(){
	int T,n,m,i,j;
	int cho[5005],c[5005];
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		n+=8;
		//�㰴˳����һ�ξ�֪��Ϊʲô����...
		//��ᷢ�����c����ȷ��
		//for (i=1;i<=m;i++) scanf("%d",&cho[i]);
		for (i=m;i>=1;i--) scanf("%d",&cho[i]);
		for (i=2;i<=m;i++) c[i]=(cho[i]-cho[i-1])*(cho[i]-cho[i-1]);
		memset(f,0,sizeof(f));
		for (i=1;i<=n;i++){
			for (j=m;j>=3*i;j--)
			//��Ϊ���Ӳ����ظ�ʹ��
			//for (j=3*i;j<=m;j++)
				//f[j]=min(f[j-2]+c[j],f[j-1];
				//�����ǲ���ѡ����һ����, �������һ��
				f[j]=f[j-2]+c[j];
			for (j=3*i+1;j<=m;j++)
				if (f[j]>f[j-1]) f[j]=f[j-1];
		}
		printf("%d\n",f[m]);
	}
	return 0;
}