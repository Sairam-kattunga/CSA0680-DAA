#include <stdio.h>
int merge(int arr[], int l, int m, int r)
 {
    int i, j, k,count=0;
    int n1 = m - l + 1;
    count++;
    int n2 = r - m;
    count++;
    int L[n1], R[n2];
    count++;
    count++;
    for (i = 0; i < n1; i++) 
	{
		count++;
		count++;
        L[i] = arr[l + i];
        count++;
    }
    count++;
    count++;
    for (j = 0; j < n2; j++)
	 {
	 	count++;
	 	count++;
        R[j] = arr[m + 1 + j];
        count++;
    }
    count++;
    i = 0;
    count++;
    j = 0;
    count++;
    k = l;
    count++;
    count++;
    while (i < n1 && j < n2) 
	{
        if (L[i] <= R[j]) 
		{
			count++;
            arr[k] = L[i];
            count++;
            i++;
        }
        else
		 {
            arr[k] = R[j];
            count++;
            j++;
            count++;
        }
        count++;
        k++;
    }
    count++;
    count++;
    while (i < n1)
	 {
	 	count++;
        arr[k] = L[i];
        i++;
        count++;
        k++;
        count++;
    }
    count++;
    count++;
    while (j < n2)
	 {
	 	count++;
        arr[k] = R[j];
        count++;
        j++;
        count++;
        k++;
    }
}
int count=0;
int mergeSort(int arr[], int l, int r) 
 
{
    if (l < r) 
	{
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        count++;
        mergeSort(arr, m + 1, r);
        count++;
        merge(arr, l, m, r);
        count++;
    }
}
int main() {
    int n, i;
    printf("Enter the number of elements in the array: ");
    count++;
    scanf("%d", &n);
    count++;
    int arr[n];
    count++;
    printf("Enter the elements of the array: ");
    count++;
    count++;
    for (i = 0; i < n; i++) 
	{
		count++;
		count++;
        scanf("%d", &arr[i]);
        count++;
    }
    count++;
    mergeSort(arr, 0, n - 1);
    count++;
    printf("Sorted array: ");
    count++;
    count++;
    for (i = 0; i < n; i++) 
	{
		count++;
		count++;
        printf("%d ", arr[i]);
        count++;
    }
    	printf("\nTime complexity is %d\n",count);
    return 0;
}
