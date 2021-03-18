#include <iostream>
#include<cstdio>
#include<cstring>
#define N (1<<16)+100
#define INF 0x3f3f3f3f
using namespace std;
int dp[N],x[20],y[20];
int t,m,n,cas=1;
bool ok(int i,int j,int k)
{
    int a=x[i]-x[j],b=y[i]-y[j];
    int c=x[j]-x[k],d=y[j]-y[k];
    return a*d==b*c;
}
int DP(int k,int st)
{
    if(dp[st]!=INF)
    return dp[st];
    if(k<=0)
    return 0;
    if(k==1)
    return dp[st]=1;

    for(int i=0;i<n;i++)
    if((1<<i)&st)
    {
        int vis[17]={0};
        for(int j=i+1;j<n;j++)
        if(!vis[j]&&(1<<j)&st)
        {
            vis[j]=1;
            int t=st,count=0;
            for(int k=i;k<n;k++)
            if((1<<k)&st&&ok(i,j,k))
            {
                vis[k]=1;
                t-=(1<<k);
                count++;
            }
            dp[st]=min(dp[st],DP(k-count,t)+1);
        }
    }
    return dp[st];
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        scanf("%d%d",&x[i],&y[i]);
        memset(dp,INF,sizeof(dp));
        printf("Case #%d:\n",cas++);
        printf("%d\n",DP(m,(1<<n)-1));
        if(t)
        puts("");
    }
    return 0;
}
