//THIS TECHNIQUE USES MEMOIZATION AND RECURSION
#include <stdio.h>
#include <string.h>
int fibo(int num,int dp[])
{
    if (num==0 || num==1) return num;
    else if (dp[num]!=-1) return dp[num];
    else
        return dp[num]=fibo(num-1,dp)+fibo(num-2,dp);
}
int main() {
    int num;
    printf("\nEnter the nth term: ");
    scanf("%d",&num);
    int dp[num+1];
    memset(dp,-1,sizeof(dp));
    int result=fibo(num,dp);
    printf("\nThe fibonacci term is:%d",result);
    return 0;
}


//ALTERNATE APPROACH - TABULATION (faster)
//THE FIBONACCI FUNCTION
int fib(int n){
    int dp[n + 2];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}