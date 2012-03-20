/*
 * This is an implementation of the BubbleSort algorithm.
 * 
 * BubbleSort works by repeatedly walking through a list of
 * elements and comparing adjacent values.  If the value on 
 * the left is greater than the value on the right they are
 * swapped.  This is repeated until a pass through the list
 * causes no swaps to be performed.
 *
 * This BubbleSort is optimized to prevent examining elements
 * which are already in the correct position.  After the first
 * pass the largest element will always be at the end of the 
 * list which is its correct position.  After the second pass
 * the next largest element will be at the n-1 position, also
 * its correct position, and so on.  You can say that the length
 * of the unsorted portion of the list is n at the beginning
 * of the procedure and it is decreased by 1 with every pass.
 * So by only visiting elements in the unsorted portion of
 * the list we can reduce the number of iterations required
 * to sort the list.  The total number of swaps will remain 
 * unchanged, however.
 *
 * One more optimization would be to always check if we have
 * made any swaps on a pass and exit if not.
 */

#include <stdio.h>
#include <limits.h>

/* Function declarations */
void printArray(int, int*);
void bubbleSort(int, int*);

/* MAIN */
int main(int argc, char *argv[])
{
    int length = argc-1; /* argv[0] is the name of the program */
    int array[length];
    int s;

    /* Get the array of ints from the args.
       We are copying argv[1]..argv[n] into 
       array[0]..array[n-1] */
    for ( s=1; s<argc; s++)
    {
        array[s-1] = atoi(argv[s]);
    }

    /* Sort the array in place. */
    bubbleSort(length, array);
    printArray(length,array);
}

/* Sorts the array in place. */
void bubbleSort(int length, int *array)
{
    /* The length of the unsorted portion */
    int unsorted = length;
    int i, j;

    /* This loop controls the number of passes over
       the array.  */
    for ( i=0; i < length; i++ )
    {
        int swap = INT_MIN;

        /* This loop walks the array and swaps when
           necessary. */
        for ( j=0; j < unsorted-1; j++ )
        {
            if ( array[j] > array[j+1] )
            {
                swap       = array[j];
                array[j]   = array[j+1];
                array[j+1] = swap;
            }
        }

        /* exit early if we didn't swap anything */
        if ( swap == INT_MIN )
        {
            break;
        }

        unsorted--;    /* reduce the length of the unsorted portion */
    }
}

/* walk the array and print each value */ 
void printArray(int length, int *a)
{
    int i;
    for ( i=0; i<length; i++ )
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}
