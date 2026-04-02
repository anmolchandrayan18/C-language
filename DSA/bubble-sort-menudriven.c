
#include <stdio.h>
int main()
{
int n, i, j, temp;
int arr[100];
int passes = 0, swaps = 0;
/* Accept number of elements */
printf("Enter number of elements: ");
scanf("%d", &n);
/* Accept array elements */
printf("Enter %d elements:\n", n);
for (i = 0; i < n; i++)
{
scanf("%d", &arr[i]);
}
/* Bubble Sort Algorithm */
for (i = 0; i < n - 1; i++)
{
passes++; // One pass completed
for (j = 0; j < n - i - 1; j++)
{
if (arr[j] > arr[j + 1])
{
/* Swap elements */
temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
swaps++;
}
}
}
/* Display sorted array */
printf("Sorted array (Ascending Order):\n");
for (i = 0; i < n; i++)
{
printf("%d ", arr[i]);
}
/* Display number of passes and swaps */
printf("\nNumber of passes: %d", passes);
printf("\nNumber of swaps: %d", swaps);
return 0;
}
