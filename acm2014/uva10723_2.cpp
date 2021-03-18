#include<stdio.h>
#include<string.h>
char s1[50],s2[50];
long long   dp[50][50],f[50][50];
long long l1,l2;

int main()
{
    int i,j,k,l,m,n;
    gets(s1);
    sscanf(s1,"%d",&l);
    for(k=1;k<=l;k++)
    {
//        scanf("%s%s",s1+1,s2+1);
		gets(s1+1);
		gets(s2+1);
        l1=strlen(s1+1);
        l2=strlen(s2+1);
        memset(f,0,sizeof(f));
        for(i=0;i<50;i++)
        {
            dp[0][i]=dp[i][0]=0;
            f[0][i]=f[i][0]=1;
        }
        for(i=1;i<=l1;i++)
        {
            for(j=1;j<=l2;j++)
            {
                if(s1[i]==s2[j])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    f[i][j]+=f[i-1][j-1];
                }
                else
                {

                    if (dp[i][j-1]>dp[i-1][j])
					{
                    	dp[i][j]=dp[i][j-1];
                    	f[i][j]+=f[i][j-1];
                    }
                    else if (dp[i][j-1]<dp[i-1][j])
					{
                    	dp[i][j]=dp[i-1][j];
                    	f[i][j]+=f[i-1][j];
                    }
                    else
					{
						dp[i][j]=dp[i-1][j];
                    	f[i][j]+=f[i-1][j]+f[i][j-1];
                    }
                }
            }
        }
        printf("Case #%d: %lld %lld\n",k,l1+l2-dp[l1][l2],f[l1][l2]);
    }
    return 0;
}

