//Swap and Amax-Amin
#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b)
{
    return (*(int*)a-*(int*)b);
}
void swap(int *A, int *B, int i,int j)
{
    int temp=A[i];
    A[i]=B[j];
    B[j]=temp;
}
void diff(int *A,int *B,int n)
{
    qsort(A,n,sizeof(int),compare);
    qsort(B,n,sizeof(int),compare);
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]<B[i])
        {
            c++;
            swap(A,B,i,i);
        }
    }
    printf("\nNumber of swaps=%d",c);
    printf("\nMinimum possible value of Amax-Amin=%d",A[n-1]-A[0]);
}
void main()
{
    int n,i,j;
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    int A[n],B[n];
    printf("\nEnter elements of 1st array:\n");
    for(i=0;i<n;i++)
    {
        printf("\nEnter A[%d] :",i);
        scanf("%d",&A[i]);
    }
    printf("\nEnter elements of 2nd array:\n");
    for(i=0;i<n;i++)
    {
        printf("\nEnter B[%d] :",i);
        scanf("%d",&B[i]);
    }
    printf("\nThe original arrays are: ");
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d",A[i]);
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d",B[i]);
    printf("\n");
    diff(A,B,n);
}
