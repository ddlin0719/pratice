#include <stdio.h>
#include <string.h>
int n=-1,f[25010];
char str[25010][20],newstr[22];
int find(){
	int le=0,ri=n,mid;
	int res;
	while (le<ri){
		//if (strcmp(newstr,"wine")==0) printf("%d %d\n",le,ri);
		mid=(le+ri)/2;
		res=strcmp(str[mid],newstr);
		if (res==0) return mid;
		if (res>0) ri=mid;
		else le=mid+1;
	}
	return -1;
		
}
void solve(){
	//if (strcmp(newstr,"wine")==0) printf("(((%d\n",n);
	if (strcmp(newstr,str[n])>0) return;
	int loc=find();
	
	if (loc==-1) return;
	//printf("%s : %d\n",newstr,loc);
	if (f[loc]+1>f[n]) f[n]=f[loc]+1;
	//putchar('s');
}
void del(char *str,int loc){
	int j=0;
	for (int i=0;str[i];i++)
		if (i!=loc) newstr[j++]=str[i];
	newstr[j]=0;
}
void change(char *str,int loc,char c){
	int i;
	for (i=0;str[i];i++)
		if (i==loc) newstr[i]=c;
		else newstr[i]=str[i];
	newstr[i]=0;
}
void add(char *str,int loc,char c){
	int i,j=0;
	for (i=0;i<loc;i++) newstr[j++]=str[i];
	newstr[j++]=c;
	for (i=loc;str[i];i++) newstr[j++]=str[i];
	newstr[j]=0;
}
int main(){
	int i;
	char j;
	//memset(f,0,sizeof(f));
	f[0]=1;
	while (gets(str[++n])){
		if (n==0) continue;
		f[n]=1;
		for (i=0;str[n][i];i++){
			//printf("%d\n",i);
			del(str[n],i);
			solve();
			for (j='a';j<='z';j++){
				change(str[n],i,j);
				solve();
				add(str[n],i,j);
				solve();
				//putchar(j);
			}
			add(str[n],i,j);
			solve();
		}
	}
	int ans=f[0];
	for (i=1;i<=n;i++)
		if (ans<f[i]) ans=f[i];
	printf("%d\n",ans);
	return 0;
}
	
