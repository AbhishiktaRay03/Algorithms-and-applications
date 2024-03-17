#include <stdio.h>
#include <stdlib.h>

// Recursive function to count the number of distinct ways
// to make the sum by using n coins
int count(int coins[], int n, int sum, int** dp) {
    // Base Case
    if (sum == 0)
        return dp[n][sum] = 1;

    // If the number of coins is 0 or sum is less than 0, then
    // there is no way to make the sum.
    if (n == 0 || sum < 0)
        return 0;

    // If the subproblem is previously calculated, then
    // simply return the result
    if (dp[n][sum] != -1)
        return dp[n][sum];

    // Two options for the current coin
    return dp[n][sum] = count(coins, n, sum - coins[n - 1], dp) +
                        count(coins, n - 1, sum, dp);
}

int main() {
    int tc = 1;
    // scanf("%d", &tc);
    while (tc--) {
        int n = 3, sum = 5;
        int coins[] = {1, 2, 3};

        // 2D dp array to store previously calculated results
        int** dp = (int**)malloc((n + 1) * sizeof(int*));
        for (int i = 0; i <= n; i++) {
            dp[i] = (int*)malloc((sum + 1) * sizeof(int));
            for (int j = 0; j <= sum; j++) {
                dp[i][j] = -1;
            }
        }

        int res = count(coins, n, sum, dp);
        printf("%d\n", res);

        // Freeing the dynamically allocated memory for dp array
        for (int i = 0; i <= n; i++) {
            free(dp[i]);
        }
        free(dp);
    }
    return 0;
}
