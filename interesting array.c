#include<stdio.h>
int main()
{
    int n,i,j;
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        printf("\nEnter arr[%d] :",i);
        scanf("%d",&arr[i]);
    }
    printf("\nThe original array is: ");
    for(i=0;i<n;i++)
        printf("%d",arr[i]);
    //Sort the array

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    //rearranging
    // Rearranging
    for(i = 0; i < n-2; i++) {
        if ((arr[i] <= arr[i+1] && arr[i+1] <= arr[i+2]) || (arr[i] >= arr[i+1] && arr[i+1] >= arr[i+2])) {
            int temp = arr[i+1];
            arr[i+1] = arr[i+2];
            arr[i+2] = temp;
        }
    }

    printf("\nThe interesting array is: ");
    for(i=0;i<n;i++)
        printf("%d",arr[i]);
}
