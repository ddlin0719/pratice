#include <stdio.h>
#include <string.h>
int map[111][111],id[11111],r,c;
int len[11111],tot[11111],pre[11111];
int n;
//����Ŀ����һ�ο�����, �ڶ���������... 
//��һ�����ø���ά������Ƶ�, �·�����������, ��·����Ŀ���ֱ���ס��
//���������ⷢ����ת��ΪLIS 
void print_path(int cur){
	if (pre[cur]!=-1) print_path(pre[cur]);
	if (!map[r][c]&&cur==n-1) return;
	printf(" %d",id[cur]+1);
}
int main(){
	int T=0;
	int i,j,x,y;

	while (scanf("%d%d",&r,&c),r+c!=-2){
		memset(map,0,sizeof(map));
		n=0;
		while (scanf("%d%d",&x,&y),x|y) map[x][y]=1;
		for (i=1;i<=r;i++)
			for (j=1;j<=c;j++)
				if (map[i][j]) id[n++]=(i-1)*c+j-1;	//����-1,��Ȼȡ��ʱ�ұ߽���� 
		//���ֱ߽紦������Ҳ�ܿӺò���... 
		if (!map[r][c]) id[n++]=r*c-1;
		
		for (i=0;i<n;i++) len[i]=1,tot[i]=1,pre[i]=-1;
		
		for (i=1;i<n;i++)
			for (j=0;j<i;j++)
				if (id[j]%c<=id[i]%c){
					//����״̬ת���������ǵ�һ�μ�.. 
					if (len[j]+1==len[i]) tot[i]+=tot[j];
					if (len[j]+1>len[i]) tot[i]=tot[j],len[i]=len[j]+1,pre[i]=j;
				}
		if (!map[r][c]) len[n-1]--;
//		for (i=0;i<n;i++) printf("%d ",len[i]);printf("\n");
		printf("CASE#%d: %d %d",++T,len[n-1],tot[n-1]);
		print_path(n-1);
		printf("\n");
	}
	return 0;
}
