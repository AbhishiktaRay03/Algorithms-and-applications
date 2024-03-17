//Cows in the FooLand city are interesting animals. One of their specialities is related to producing offsprings. A cow in FooLand produces its first calve (female calf) at the age of two years and proceeds to produce other calves (one female calf a year).
//Now the farmer Harold wants to know how many animals would he have at the end of N years, if we assume that none of the calves dies, given that initially, he has only one female calf?
#include <stdio.h>

long long findCows(int N) {
    long long dp[N + 1];
    dp[0] = 1;
    dp[1] = 1; // Initial calf

    for (int i = 2; i <= N; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2]; // Each existing cow produces one female calf
    }

    return dp[N];
}

int main() {
    int N;
    printf("Enter the number of years (N): ");
    scanf("%d", &N);

    long long totalCows = findCows(N);
    printf("Total cows after %d years: %lld\n", N, totalCows);

    return 0;
}