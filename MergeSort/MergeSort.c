/* This program demonstrates the Merge Sort algorithm.
 *
 * Merge Sort is a divide and conquer algorithm that
 * works as follows.
 *
 * If the list is length 0 or 1 it is already sorted. Otherwise:
 *
 * Divide the unsorted list into two sublists of about half the size.
 * Sort each sublist recursively by re-applying Merge Sort.
 * Merge the two sublists back into one sorted list.
 *
 * By dividing the list into smaller and smaller problems we guarantee
 * that eventually we will get down to many lists of size 1 or 0, 
 * which are already sorted by definition.
 *
 * We then merge all of these lists back together with the merge
 * routine.  Merge works as follows.
 *
 * Compare the first element of both subarrays.  Copy the smaller
 * element to the new merged list.  Increment the index of the list
 * that was copied from so that there is a new first element.
 * Continue until all elements from both list have been copied.
 */

#include <stdio.h>


int *mergeSort(int, int*);
int *merge(int*, int, int*, int);
void printArray(int, int*);
void swap(int*, int*);

/* This program demonstrates the Merge Sort algorithm described above. */
int main(int argc, char *argv[])
{
    int length = argc-1;
    int array[length];
    int *new_array;
    int i;

    if ( argc == 1 )
    {
        printf("You must supply a list to sort.\n");
        return(1);
    }

    /* Copy the array values from argv. */
    for ( i=1; i<argc; i++ )
    {
        array[i-1] = atoi(argv[i]);
    }

    new_array = mergeSort(length, array);
    printArray(length, new_array);

    return(0);
}

/* Implementation of Merge Sort */
int *mergeSort(int length, int *array)
{
    int mid;
    int *left;
    int *right;
    int left_length, right_length;
    int i, lindex, rindex;

    /* This list is already sorted so return it. */
    if ( length <= 1 )
    {
        return array;
    }

    /* Calculate the middle element. */
    mid = length / 2;

    /* Calculate the lengths of the two subarrays. */
    left_length  = length - mid;
    right_length = mid;
    
    /* Copy the elements into the two subarrays. */
    lindex = 0;
    rindex = mid + 1;
    for ( i=0; i< length; i++ )
    {
        if ( i <= mid )
        {
            left[lindex] = array[i];
            lindex++;
        }
        else
        {
            right[rindex] = array[i];
            rindex++;
        }
    }
    
    /* Recusively call mergeSort on each subarray. */
    left  = mergeSort(left_length, left);
    right = mergeSort(right_length, right);

    return merge(left, left_length, right, right_length);
}

/* Merges the two subarrays into one sorted array. */
int *merge(int *left, int left_length, int *right, int right_length)
{
    int lindex = 0;
    int rindex = 0;
    int done   = 0;
    int m      = 0;  /* Index of merged */
    int *merged;

    while ( ! done )
    {
        if ( lindex < left_length && rindex < right_length )
        {
            if ( left[lindex] <= right[rindex] )
            {
                merged[m] = left[lindex];
                m++;
                lindex++;
            }
            else
            {
                merged[m] = right[rindex];
                m++;
                rindex++;
            }
        }
        else if ( lindex < left_length && rindex > right_length )
        {
            merged[m] = left[lindex];
            m++;
            lindex++;
        }
        else if ( lindex > left_length && rindex < right_length )
        {
            merged[m] = right[rindex];
            m++;
            rindex++;
        }
        else
        {
            done = 1;
        }
    }

    return merged;
}


/* Swaps the values between the two given addresses. */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Print the given array. */
void printArray(int length, int *array)
{
    int i;

    for ( i=0; i<length; i++ )
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}

