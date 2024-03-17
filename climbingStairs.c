//You are climbing a staircase. It takes n steps to reach the top.

//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

int climbStairs(int n) {
    int dp[n+1];
    memset(dp, -1, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main() {
    int num;
    printf("\nEnter the nth term: ");
    scanf("%d",&num);
    int result=climbStairs(num);
    printf("\nThe result is:%d",result);
    return 0;
}