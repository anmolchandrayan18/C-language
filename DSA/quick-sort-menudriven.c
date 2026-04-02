
#include <stdio.h>
/* Function to swap two elements */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
/* Partition function using last element as pivot */
int partition(int arr[], int low, int high)
{
int pivot = arr[high]; // Last element as pivot
int i = low - 1; // Index of smaller element
int j;
for (j = low; j < high; j++)
{
if (arr[j] < pivot)
{
i++;
swap(&arr[i], &arr[j]);
}
}
// Place pivot in correct position
swap(&arr[i + 1], &arr[high]);
return (i + 1);
}
/* Recursive Quick Sort function */
void quickSort(int arr[], int low, int high)
{
if (low < high)
{
int p = partition(arr, low, high);
quickSort(arr, low, p - 1); // Sort left subarray
quickSort(arr, p + 1, high); // Sort right subarray
}
}
int main()
{
int n, i;
int arr[100];
/* Accept number of elements */
printf("Enter number of elements: ");
scanf("%d", &n);
/* Accept array elements */
printf("Enter %d elements:\n", n);
for (i = 0; i < n; i++)
{
scanf("%d", &arr[i]);
}
/* Apply Quick Sort */
quickSort(arr, 0, n - 1);
/* Display sorted array */
printf("Sorted array:\n");
for (i = 0; i < n; i++)
{
printf("%d ", arr[i]);
}
return 0;
}
