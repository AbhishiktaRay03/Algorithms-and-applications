// Inversion Count for an array indicates – how far (or close) the array is from being sorted. If the array is already sorted, then the inversion count is 0, but if the array is sorted in reverse order, the inversion count is the maximum. 

//Given an array arr[]. The task is to find the inversion count of arr[]. Where two elements arr[i] and arr[j] form an inversion if a[i] > a[j] and i < j.
#include <stdio.h>
int merge(int arr[],int temp[],int left,int mid,int right)
{
    int i,j,k,inv_count=0;
    i=left;
    j=mid;
    k=left;
    while((i<=mid-1)&&(j<=right))
    {
        if(arr[i]<arr[j])
            temp[k++]=arr[i++];
        else
        {
            temp[k++]=arr[j++];
            inv_count+= mid-i;
        }
    }
    while(i<=mid-1)
        temp[k++]=arr[i++];
    while(j<=right)
        temp[k++]=arr[j++];

    for(i=left;i<=right;i++)
        arr[i]=temp[i];
    return inv_count;
}
int mergesort(int arr[],int temp[],int left,int right)
{
    int inv_count=0;
    if(left<right)
    {
        int mid= left+ (right-left)/2;
        inv_count+=mergesort(arr,temp,left,mid);
        inv_count+=mergesort(arr,temp,mid+1,right);
        inv_count+=merge(arr,temp,left,mid+1,right);
    }
    return inv_count;
}
int main()
{
    int n,i;
    printf("\nEnter the number of elements of array:");
    scanf("%d",&n);
    int arr[n],temp[n];
    printf("\nEnter the elements of array\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int inversions = mergesort(arr,temp,0,n-1);
    printf("\nThe number of inversions required is:%d",inversions);
    return 0;
}
