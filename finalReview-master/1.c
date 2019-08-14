#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// sort
void selectionSort(int *arr, int len);
void insertionSort(int *arr, int len);

void mergeSort(int *arr, int first, int last);
void merge(int *arr, int first, int mid, int last);

void quickSort(int *arr, int first, int last);
int partition(int *arr, int first, int last);

// search
int linearSearch(int *arr, int len, int target);
int binarySearch(int *arr, int len, int target);

int main()
{
    int arr[3] = {100, 10, 0};

    // int result = binarySearch(arr, 11, 10);
    // printf("%d\n", result);

    quickSort(arr, 0, 2);

    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", arr[i]);
    }
}

// 0 1 2 3 4
void selectionSort(int *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int temp = arr[i];
        int pos;
        for (int j = 1; j < len; j++)
        {
            if (arr[i] > arr[j])
            {
                arr[i] = arr[j];
                pos = j;
            }
        }
        // swap
        arr[pos] = temp;
    }
}

void insertionSort(int *arr, int len)
{
    for (int i = 1; i < len; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        int pos;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            // pos is the spot for temp value to slide in
            pos = j;
            j--;
        }

        arr[pos] = temp;
    }
}

// work for unsorted list
int linearSearch(int *arr, int len, int target)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}

// only workd for sorted list
int binarySearch(int *arr, int len, int target)
{
    // floor trim the value
    // floor(1.6) = 1
    int first = 0;
    int last = len - 1;
    while (first <= last)
    {
        int mid = floor((first + last) / 2);

        // if find the target in the mid
        if (arr[mid] == target)
        {
            return mid;
        }
        // if mid is greater than target, cut the last past
        // by moving last index one to left
        else if (arr[mid] > target)
        {
            last = mid - 1;
        }
        // if mid is lesser than target, cut the first past
        // by moving first index one to right
        else
        {
            first = mid + 1;
        }
    }

    return -1;
}

void mergeSort(int *arr, int first, int last)
{
    if (first < last)
    {
        int mid = (last - first) / 2;
        // sort the first part
        mergeSort(arr, first, mid);
        // sort the second part
        mergeSort(arr, mid + 1, last);
        // merge the first part and the second part together
        merge(arr, first, mid, last);
    }
    else
    {
        return;
    }
}

void merge(int *arr, int first, int mid, int last)
{
    int len = last - first + 1;
    int newArr[len];
    int leftPos = first;
    int rightPos = mid + 1;
    int newPos = 0;

    while (leftPos <= mid && rightPos <= last)
    {
        if (arr[leftPos] < arr[rightPos])
        {
            newArr[newPos++] = arr[leftPos++];
        }
        else
        {
            newArr[newPos++] = arr[rightPos++];
        }
    }

    // copy remaining elements from non-empty space
    while (leftPos <= mid)
    {
        newArr[newPos++] = arr[leftPos++];
    }

    while (rightPos <= last)
    {
        newArr[newPos++] = arr[rightPos++];
    }

    for (newPos = 0; newPos < len; newPos++)
    {
        arr[newPos + first] = newArr[newPos];
    }
    return;
}

void quickSort(int *arr, int first, int last)
{
    if (first < last)
    {
        // pi is in the middle of the list
        int pi = partition(arr, first, last);
        quickSort(arr, first, pi - 1);
        quickSort(arr, pi + 1, last);
    }
    else
    {
        return;
    }
}

int partition(int *arr, int first, int last)
{
    int pivot = arr[last];
    int i = first - 1;

    for (int j = first; j < last; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[last];
    arr[last] = temp;
    return i + 1;
}