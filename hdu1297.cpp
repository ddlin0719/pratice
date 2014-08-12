#include<stdio.h>
int f[1001][1000];

void add(int sub)
{
    int i;
    for(i=0;i<100;i++)
    {
        f[sub][i]=0;
    }
    for(i=1;i<=f[sub-1][0];i++)
    {
        f[sub][i]+=f[sub-1][i]+f[sub-2][i]+f[sub-4][i];
        f[sub][i+1]=f[sub][i]/10;
        f[sub][i]%=10;
    }
    if(f[sub][f[sub-1][0]+1])
    {
        f[sub][0]=f[sub-1][0]+1;
    }
    else
    {
        f[sub][0]=f[sub-1][0];
    }
}


int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i;
        for(i=0;i<4;i++)
        {
            f[i][0]=1;
        }
        f[0][1]=1;
        f[1][1]=1;
        f[2][1]=2;
        f[3][1]=4;
        for(i=4;i<=n;i++)
        {
            add(i);
        }
        for(i=f[n][0];i>0;i--)
        {
            printf("%d",f[n][i]);
        }
        printf("\n");
    }
    return 0;
}

