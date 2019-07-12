#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// bubble sort
// pre conditon: unsorted int array A[N]
// post condition: sorted int array A[N]
void bubble_sort(int A[], int n)
{
    // if (A[j] > A[j+1])
    // swap adjacent elements
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

// insertion sort
// pre conditon: unsorted int array A[N]
// post condition: sorted int array A[N]
void insertion_sort(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // assert A[0...i-1] is sorted
        int temp = A[i];
        int j = i;
        while (j > 0 && temp < A[j - 1])
        {
            // assert A[j] ... A[i] > temp
            A[j] = A[j - 1];
            j--;
        }
        // assert A[j - 1] <= temp or j = 0
        A[j] = temp;
    }
}

// generate a random array, return the pointer
// pre conditon: int n
// post condition: a pointer points to a random array with size n -> *ptr = &arr[0]
int *create_random_array(int n)
{
    int *ptr = malloc(sizeof(int) * n);
    if (ptr != NULL)
    {
        // Seed the random number generator
        srand((unsigned)time(NULL));
        for (int i = 0; i < n; i++)
        {
            // int random_number = rand() % range + min;
            // random numbers contain duplicates
            ptr[i] = rand() % 1000 + 1;
        }
        return ptr;
    }
    return NULL;
}

//  on 2 sorting algorithms: 1. bubble sort 2. insertion sort
//  5 types of arrays: 1.sorted 2.reverse sorted 3. 3 randomly scrambled arrays(which contains duplicates)
//  3 array sizes : 20000, 40000, 100000

int main()
{
    clock_t start, end;
    double cpu_time_used;
    int aSize = 20000;
    int bSize = 40000;
    int cSize = 100000;

    /* starts from Insertion sort, test 15 cases */

    // test for sorted array
    printf("Insertion Sort, sorted array\n");

    // sort the aSize arry first
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr = create_random_array(aSize);
    int arr[aSize];
    for (int i = 0; i < aSize; i++)
    {
        arr[i] = ptr[i];
    }
    insertion_sort(arr, aSize);
    // start the clock
    start = clock();
    // run the sorting algotihm
    insertion_sort(arr, aSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", aSize, cpu_time_used);

    // sort the bSize arr first
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr2 = create_random_array(bSize);
    int arr2[bSize];
    for (int i = 0; i < bSize; i++)
    {
        arr2[i] = ptr2[i];
    }
    insertion_sort(arr2, bSize);
    // start the clock
    start = clock();
    // run the sorting algotihm
    insertion_sort(arr2, bSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", bSize, cpu_time_used);

    // sort the cSize array first
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr3 = create_random_array(cSize);
    int arr3[cSize];
    for (int i = 0; i < cSize; i++)
    {
        arr3[i] = ptr3[i];
    }
    insertion_sort(arr3, cSize);
    // start the clock
    start = clock();
    // run the sorting algotihm
    insertion_sort(arr3, cSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", cSize, cpu_time_used);

    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    // test for reversed sorted array    //
    // from insertion sort               //
    ///////////////////////////////////////
    ///////////////////////////////////////
    printf("Insertion Sort, reversed sorted array\n");

    // sort the aSize arry first
    ////////////////////////////
    ////////////////////////////
    ////////////////////////////
    ////////////////////////////
    int *ptr4 = create_random_array(aSize);
    int arr4[aSize];
    for (int i = 0; i < aSize; i++)
    {
        arr4[i] = ptr4[i];
    }
    insertion_sort(arr4, aSize);
    // then reverse the array
    int arr4Reversed[aSize];
    for (int i = aSize - 1; i >= 0; i--)
    {
        arr4Reversed[aSize - 1 - i] = arr4[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    insertion_sort(arr4Reversed, aSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", aSize, cpu_time_used);

    // sort the bSize arry first
    ////////////////////////////
    ////////////////////////////
    ////////////////////////////
    ////////////////////////////
    int *ptr5 = create_random_array(bSize);
    int arr5[bSize];
    for (int i = 0; i < aSize; i++)
    {
        arr5[i] = ptr5[i];
    }
    insertion_sort(arr5, bSize);
    // then reverse the array
    int arr5Reversed[bSize];
    for (int i = bSize - 1; i >= 0; i--)
    {
        arr5Reversed[bSize - 1 - i] = arr5[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    insertion_sort(arr5Reversed, bSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", bSize, cpu_time_used);

    // sort the cSize arry first
    ////////////////////////////
    ////////////////////////////
    ////////////////////////////
    ////////////////////////////
    int *ptr6 = create_random_array(cSize);
    int arr6[cSize];
    for (int i = 0; i < cSize; i++)
    {
        arr6[i] = ptr6[i];
    }
    insertion_sort(arr6, cSize);
    // then reverse the array
    int arr6Reversed[cSize];
    for (int i = cSize - 1; i >= 0; i--)
    {
        arr6Reversed[cSize - 1 - i] = arr6[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    insertion_sort(arr6Reversed, cSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", cSize, cpu_time_used);

    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    // test for first scrambled array    //
    // from insertion sort               //
    ///////////////////////////////////////
    ///////////////////////////////////////
    printf("Insertion Sort, first random scrambled array\n");

    // first aSize random scrambled array
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr7 = create_random_array(aSize);
    int arr7[aSize];
    for (int i = 0; i < aSize; i++)
    {
        arr7[i] = ptr7[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    insertion_sort(arr7, aSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", aSize, cpu_time_used);

    // first bSize random scrambled array
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr8 = create_random_array(bSize);
    int arr8[bSize];
    for (int i = 0; i < bSize; i++)
    {
        arr8[i] = ptr8[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    insertion_sort(arr8, bSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", bSize, cpu_time_used);

    // first cSize random scrambled array
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr9 = create_random_array(cSize);
    int arr9[cSize];
    for (int i = 0; i < cSize; i++)
    {
        arr9[i] = ptr9[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    insertion_sort(arr9, cSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", cSize, cpu_time_used);

    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    // test for second scrambled array   //
    // from insertion sort               //
    ///////////////////////////////////////
    ///////////////////////////////////////
    printf("Insertion Sort, second random scrambled array\n");

    // second aSize random scrambled array
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr10 = create_random_array(aSize);
    int arr10[aSize];
    for (int i = 0; i < aSize; i++)
    {
        arr10[i] = ptr10[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    insertion_sort(arr10, aSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", aSize, cpu_time_used);

    // second bSize random scrambled array
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr11 = create_random_array(bSize);
    int arr11[bSize];
    for (int i = 0; i < bSize; i++)
    {
        arr11[i] = ptr11[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    insertion_sort(arr11, bSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", bSize, cpu_time_used);

    // second cSize random scrambled array
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr12 = create_random_array(cSize);
    int arr12[cSize];
    for (int i = 0; i < cSize; i++)
    {
        arr12[i] = ptr12[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    insertion_sort(arr12, cSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", cSize, cpu_time_used);

    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    // test for third scrambled array    //
    // from insertion sort               //
    ///////////////////////////////////////
    ///////////////////////////////////////
    printf("Insertion Sort, third random scrambled array\n");

    // third aSize random scrambled array
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr13 = create_random_array(aSize);
    int arr13[aSize];
    for (int i = 0; i < aSize; i++)
    {
        arr13[i] = ptr13[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    insertion_sort(arr13, aSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", aSize, cpu_time_used);

    // third bSize random scrambled array
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr14 = create_random_array(bSize);
    int arr14[bSize];
    for (int i = 0; i < bSize; i++)
    {
        arr14[i] = ptr14[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    insertion_sort(arr14, bSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", bSize, cpu_time_used);

    // third cSize random scrambled array
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr15 = create_random_array(cSize);
    int arr15[cSize];
    for (int i = 0; i < cSize; i++)
    {
        arr15[i] = ptr15[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    insertion_sort(arr15, cSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", cSize, cpu_time_used);

    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    /* ends with Bubble sort, test 15 cases more */

    // test for sorted array
    printf("Bubble Sort, sorted array\n");

    // sort the aSize arry first
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr16 = create_random_array(aSize);
    int arr16[aSize];
    for (int i = 0; i < aSize; i++)
    {
        arr16[i] = ptr16[i];
    }
    bubble_sort(arr16, aSize);
    // start the clock
    start = clock();
    // run the sorting algotihm
    bubble_sort(arr16, aSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", aSize, cpu_time_used);

    // sort the bSize arr first
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr17 = create_random_array(bSize);
    int arr17[bSize];
    for (int i = 0; i < bSize; i++)
    {
        arr17[i] = ptr17[i];
    }
    bubble_sort(arr17, bSize);
    // start the clock
    start = clock();
    // run the sorting algotihm
    bubble_sort(arr17, bSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", bSize, cpu_time_used);

    // sort the cSize array first
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr18 = create_random_array(cSize);
    int arr18[cSize];
    for (int i = 0; i < cSize; i++)
    {
        arr18[i] = ptr18[i];
    }
    bubble_sort(arr18, cSize);
    // start the clock
    start = clock();
    // run the sorting algotihm
    bubble_sort(arr18, cSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", cSize, cpu_time_used);

    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    // test for reversed sorted array    //
    // from bubble sort                  //
    ///////////////////////////////////////
    ///////////////////////////////////////
    printf("Bubble Sort, reversed sorted array\n");

    // sort the aSize arry first
    ////////////////////////////
    ////////////////////////////
    ////////////////////////////
    ////////////////////////////
    int *ptr19 = create_random_array(aSize);
    int arr19[aSize];
    for (int i = 0; i < aSize; i++)
    {
        arr19[i] = ptr19[i];
    }
    bubble_sort(arr19, aSize);
    // then reverse the array
    int arr19Reversed[aSize];
    for (int i = aSize - 1; i >= 0; i--)
    {
        arr19Reversed[aSize - 1 - i] = arr19[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    bubble_sort(arr19Reversed, aSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", aSize, cpu_time_used);

    // sort the bSize arry first
    ////////////////////////////
    ////////////////////////////
    ////////////////////////////
    ////////////////////////////
    int *ptr20 = create_random_array(bSize);
    int arr20[bSize];
    for (int i = 0; i < aSize; i++)
    {
        arr20[i] = ptr20[i];
    }
    bubble_sort(arr20, bSize);
    // then reverse the array
    int arr20Reversed[bSize];
    for (int i = bSize - 1; i >= 0; i--)
    {
        arr20Reversed[bSize - 1 - i] = arr20[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    bubble_sort(arr20Reversed, bSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", bSize, cpu_time_used);

    // sort the cSize arry first
    ////////////////////////////
    ////////////////////////////
    ////////////////////////////
    ////////////////////////////
    int *ptr21 = create_random_array(cSize);
    int arr21[cSize];
    for (int i = 0; i < cSize; i++)
    {
        arr21[i] = ptr21[i];
    }
    bubble_sort(arr21, cSize);
    // then reverse the array
    int arr21Reversed[cSize];
    for (int i = cSize - 1; i >= 0; i--)
    {
        arr21Reversed[cSize - 1 - i] = arr21[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    bubble_sort(arr21Reversed, cSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", cSize, cpu_time_used);

    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    // test for first scrambled array    //
    // from bubble sort                  //
    ///////////////////////////////////////
    ///////////////////////////////////////
    printf("Bubble Sort, first random scrambled array\n");

    // first aSize random scrambled array
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr22 = create_random_array(aSize);
    int arr22[aSize];
    for (int i = 0; i < aSize; i++)
    {
        arr22[i] = ptr22[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    bubble_sort(arr22, aSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", aSize, cpu_time_used);

    // first bSize random scrambled array
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr23 = create_random_array(bSize);
    int arr23[bSize];
    for (int i = 0; i < bSize; i++)
    {
        arr23[i] = ptr23[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    bubble_sort(arr23, bSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", bSize, cpu_time_used);

    // first cSize random scrambled array
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr24 = create_random_array(cSize);
    int arr24[cSize];
    for (int i = 0; i < cSize; i++)
    {
        arr24[i] = ptr24[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    bubble_sort(arr24, cSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", cSize, cpu_time_used);

    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    // test for second scrambled array   //
    // from bubble sort                  //
    ///////////////////////////////////////
    ///////////////////////////////////////
    printf("Bubble Sort, second random scrambled array\n");

    // second aSize random scrambled array
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr25 = create_random_array(aSize);
    int arr25[aSize];
    for (int i = 0; i < aSize; i++)
    {
        arr25[i] = ptr25[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    bubble_sort(arr10, aSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", aSize, cpu_time_used);

    // second bSize random scrambled array
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr26 = create_random_array(bSize);
    int arr26[bSize];
    for (int i = 0; i < bSize; i++)
    {
        arr26[i] = ptr26[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    bubble_sort(arr26, bSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", bSize, cpu_time_used);

    // second cSize random scrambled array
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr27 = create_random_array(cSize);
    int arr27[cSize];
    for (int i = 0; i < cSize; i++)
    {
        arr27[i] = ptr27[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    bubble_sort(arr27, cSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", cSize, cpu_time_used);

    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    // test for third scrambled array    //
    // from bubble sort                  //
    ///////////////////////////////////////
    ///////////////////////////////////////
    printf("Bubble Sort, third random scrambled array\n");

    // third aSize random scrambled array
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr28 = create_random_array(aSize);
    int arr28[aSize];
    for (int i = 0; i < aSize; i++)
    {
        arr28[i] = ptr28[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    bubble_sort(arr28, aSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", aSize, cpu_time_used);

    // third bSize random scrambled array
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr29 = create_random_array(bSize);
    int arr29[bSize];
    for (int i = 0; i < bSize; i++)
    {
        arr29[i] = ptr29[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    bubble_sort(arr29, bSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", bSize, cpu_time_used);

    // third cSize random scrambled array
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    int *ptr30 = create_random_array(cSize);
    int arr30[cSize];
    for (int i = 0; i < cSize; i++)
    {
        arr30[i] = ptr30[i];
    }
    // start the clock
    start = clock();
    // run the sorting algotihm
    bubble_sort(arr15, cSize);
    // stop the clock
    end = clock();
    //calculate the actual time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array size: %d time: %.4f seconds\n", cSize, cpu_time_used);

    return 0;
}