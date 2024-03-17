// Online C compiler to run C program online
#include <stdio.h>
#include <limits.h>
int max(int a,int b)
{
    if (a>b) 
        return a;
    else 
        return b;
}
int eggdrop(int n,int k)
{
    int i,j,x,res=0;
    int dp[n+1][k+1];
    for(i=0;i<=n;i++)
    {
        dp[i][1]=1;
        dp[i][0]=0;
    }
    for(j=0;j<=k;j++)
    {
        dp[1][j]=j;
    }
    for(i=2;i<=n;i++)
    {
        for(j=2;j<=k;j++)
        {
            dp[i][j]=INT_MAX;
            for(x=1;x<=j;x++)
            {
                res=1+max(dp[i-1][x-1],dp[i][j-x]);
                if(res<dp[i][j])
                    dp[i][j]=res;
            }
            
        }
    }
    return dp[n][k];
}
int main()
{
    int n,k;
    printf("\nEnter the number of floors:");
    scanf("%d",&k);
    printf("\nEnter the number of eggs:");
    scanf("%d",&n);
    printf("Required result:%d",eggdrop(n,k));
    return 0;
    
}