/* This program demonstrates the Selection Sort algorithm.
 *
 * Selection Sort works by examining each element in the
 * given list and finding the largest value.  Ithen swaps
 * the largest value with the last value in the list.  It
 * repeats the procedure with all elements except the last
 * until the entire list is sorted.
 *
 * Selection sort runs in O(n^2) time.
 */

#include <stdio.h>
#include <limits.h>

void selectionSort(int, int*);
void printArray(int, int*);

/* This program demonstrates the Selection Sort algorithm described above. */
int main(int argc, char *argv[])
{
    int length = argc-1;
    int array[length];
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

    selectionSort(length, array);
    printArray(length, array);

    return(0);
}

/* Implementation of Selection Sort. */
void selectionSort(int length, int *array)
{
    int unsorted = length;
    int i, j;
    int largest, swap;
    int largest_index;

    /* Make i passes through the array. */
    for ( i=0; i<length; i++ )
    {
        largest       = INT_MIN;
        largest_index = -1;

        /* Find the largest element in the unsorted portion. */
        for ( j=0; j<unsorted; j++ )
        {
            if ( array[j] > largest )
            {
                largest = array[j];
                largest_index = j;
            }
        }

        /* If a largest element was found swap it with the last one. */
        if ( largest_index > -1 )
        {
            swap                 = array[unsorted-1];
            array[unsorted-1]    = largest;
            array[largest_index] = swap;
        }

        unsorted--;
    }
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
