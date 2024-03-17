#include <stdio.h>

void countToMakeDiffEqual(int arr[], int n) {
    int ma = 0;
    int freq[100] = {0}; // Assuming a maximum size of 100 for the frequency array

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++; // Increment the frequency of the current element
        ma = (ma > freq[arr[i]]) ? ma : freq[arr[i]]; // Update the maximum frequency
    }

    if (n <= 2) {
        printf("0\n");
    } else if (ma == 1) {
        printf("%d\n", n - 2);
    } else {
        printf("%d\n", n - ma);
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6};
    int N = sizeof(arr) / sizeof(arr[0]);

    countToMakeDiffEqual(arr, N);

    return 0;
}
