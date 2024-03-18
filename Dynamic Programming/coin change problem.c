#include<stdio.h>
#include<string.h>
int count(int coins[],int n,int sum,int dp[n+1][sum+1])
{
    if (sum==0)
        return dp[n][sum]=1;
    else if (n==0 || sum<0)
        return 0;
    else if (dp[n][sum]!=-1)
        return dp[n][sum];
    return dp[n][sum]=count(coins,n,sum-coins[n-1],dp)+count(coins,n-1,sum,dp);
}
int main()
{
    int n,sum,i;
    int tc=1;
    while(tc--){
        printf("\nEnter the sum amount:");
        scanf("%d",&sum);
        printf("\nEnter the number of available coin options:");
        scanf("%d",&n);
        int coins[n];
        printf("\nEnter the coin values:");
        for(i=0;i<n;i++)
            scanf("%d",&coins[i]);
        int dp[n+1][sum+1];
        memset(dp,-1,sizeof(dp));
        int result=count(coins,n,sum,dp);
        printf("\nResult=%d",result);

    }
    return 0;

}
