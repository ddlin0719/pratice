#include <stdio.h>
#include <string.h>
int var[22],n;
int ru[30],next[30][30],child[30],ans[30];
void update(int id,int flag){
	if (flag==-1) ru[id]=-1;
	if (flag==1)  ru[id]=0;
	for (int i=0;i<child[id];i++)
		ru[next[id][i]]+=flag;
}

void toposort(int cur){
	int i;
	if (cur==n){
		for (i=0;i<cur;i++) printf("%c",ans[i]+'a');
		printf("\n");
		return ;
	}
	for (i=0;i<n;i++)
		if (ru[var[i]]==0){
			ans[cur]=var[i];
			update(var[i],-1);
			toposort(cur+1);
			update(var[i],1);
		}
}
void sort(){
	int i,j,tmp;
	for (i=0;i<n;i++)
		for (j=i+1;j<n;j++)
			if (var[i]>var[j])
				tmp=var[i],var[i]=var[j],var[j]=tmp;
}
int main(){
	char str[128],tmp,a,b;
	int i;
	while (gets(str)){
		n=0;
		while (sscanf(str+n*2,"%c",&tmp)){
			var[n++]=tmp-'a';
			if (str[n*2-1]==0) break;
		}
		//ÎğÂ©ÁËÅÅĞò
		sort();
	//	for (i=0;i<n;i++) printf("%c ",var[i]+'a'); printf("\n");
		memset(ru,0,sizeof(ru));
		memset(child,0,sizeof(child));
		gets(str);
		i=0;
		while (sscanf(str+i*4,"%c %c",&a,&b)){
			//printf("%c %c\n",a,b);
			ru[b-'a']++;
			next[a-'a'][child[a-'a']++]=b-'a';
			if (str[i*4+3]==0) break;
			i++;
		}
		toposort(0);
		puts("");
	}
	return 0;
}