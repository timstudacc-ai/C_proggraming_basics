#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20
void printArray(int arr[], int size);
int find_closest(int arr1[], int size, int target);
int main()
{
    srand(time(NULL)); // Seed the random number generator
    // so that each run produces different random values
    int arr1[SIZE], arr2[SIZE] = {0};
    for (int i = 0; i < SIZE; i++)
    {
        // Generate random values around 2*i for arr1 and 3*i for arr2
        // so that both arrays are sorted and have some overlap in values
        arr1[i] = 2 * i + rand() % 3; // Random values around 2*i
    }
    for (int i = 0; i < SIZE; i++)
    {
        arr2[i] = 3 * i + rand() % 4;
    }
    printf("=====Array1====\n");
    printArray(arr1, SIZE);
    printf("=====Array2====\n");
    printArray(arr2, SIZE);

    int min_diff = 10000; // Initialize with a large value
    int best_val1 = 0, best_val2 = 0;

    for (int i = 0; i < SIZE; i++)
    {
        int closest = find_closest(arr2, SIZE, arr1[i]);
        int diff = abs(arr1[i] - closest);
        printf("Closest to %d (from arr1) in arr2 is %d. Diff: %d\n", arr1[i], closest, diff);

        if (diff < min_diff)
        {
            min_diff = diff;
            best_val1 = arr1[i];
            best_val2 = closest;
        }
    }
    printf("\nPair with minimum absolute difference: %d and %d (Diff: %d)\n", best_val1, best_val2, min_diff);

    return 0;
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int find_closest(int arr1[], int size, int target)
{
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr1[mid] == target)
        {
            return arr1[mid];
        }
        else if (arr1[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    // Check edge cases, when target
    // is smaller than all elements (then high becomes negative)
    // or larger than all elements (then low becomes size)
    if (high < 0)
        return arr1[low]; // Return the smallest element
    if (low >= size)
        return arr1[high]; // Return the largest element

    // Return the closest of the two candidates
    // After the loop, low is the index of the smallest element greater than target
    // and high is the index of the largest element less than target

    return (abs(arr1[low] - target) < abs(arr1[high] - target)) ? arr1[low] : arr1[high];
}
