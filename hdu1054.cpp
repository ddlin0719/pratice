/*
Bob enjoys playing computer games, especially strategic games, but
 sometimes he cannot find the solution fast enough and then he is 
 very sad. Now he has the following problem. He must defend a medieval 
 city, the roads of which form a tree. He has to put the minimum number 
 of soldiers on the nodes so that they can observe all the edges. Can you
  help him?
*/
#include <stdio.h>
#include <vector>
std::vector<int> map[1505];
int n,visit[1505],link[1505];
int dfs(int cur){
	int i,j;
	for (i=0;i<map[cur].size();i++){
		j=map[cur][i];
		if (!visit[j]){
			visit[j]=1;
			//if (link[j]==-1||dfs(j)){
			if (link[j]==-1||dfs(link[j])){
				link[j]=cur;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	int m,id,i,j,tot;
	while (scanf("%d",&n)!=EOF){
		for (i=0;i<n;i++) map[i].clear();
		for (i=0;i<n;i++){
			scanf("%d:(%d)",&id,&m);
			while (m--){
				scanf("%d",&j);
				map[id].push_back(j);
				map[j].push_back(id);
			}
		}
		memset(link,-1,sizeof(link));
		tot=0;
		for (i=0;i<n;i++){
			memset(visit,0,sizeof(visit));
			tot+=dfs(i);
		}
		//printf("%d\n",tot);
		printf("%d\n",tot/2);
	}
	return 0;
}