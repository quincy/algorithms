/* This program demonstrates the Insertion Sort algorithm.
 *
 * Insertion Sort works by examining each element in the 
 * list from left to right.  The first element can be 
 * considered a one-element sorted list and therefore
 * is in the correct place.  Then the second element is
 * examined.  It is compared to the element which precedes
 * it and if the current element is smaller than the previous
 * they are swapped.  Swapping continues as long as the
 * element on the left is larger.  Once the element on the
 * left is smaller the current element has been placed in the 
 * correct place and we can move onto the next unsorted element.
 *
 * EXAMPLE
 *
 * U = Next unsorted element.
 * | = Visual separator of sorted and unsorted portion of list
 *
 *     U
 * 5 | 4 3 2 7 6 1
 *
 *       U
 * 4 5 | 3 2 7 6 1
 *
 *         U
 * 3 4 5 | 2 7 6 1
 *
 *           U
 * 2 3 4 5 | 7 6 1
 *
 *             U
 * 2 3 4 5 7 | 6 1
 *
 *               U
 * 2 3 4 5 6 7 | 1
 *
 * Finished
 * 1 2 3 4 5 6 7
 */

#include <stdio.h>


void insertionSort(int, int*);
void printArray(int, int*);
void swap(int*, int*);

/* This program demonstrates the Insertion Sort algorithm described above. */
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

    insertionSort(length, array);
    printArray(length, array);

    return(0);
}

/* Implementation of Insertion Sort */
void insertionSort(int length, int *array)
{
    int i, j, k;

    /* Visit each element from left to right starting with index 1. */
    for ( i=1; i<length; i++ )
    {
        j = i; 

        /* Compare the current element with the previous and swap
           if necessary.  Continue doing this toward the beginning
           of the array until no swap is necessary. */
        while ( j > 0 )
        {
            if ( array[j] < array[j-1] )
            {
                swap(&array[j-1], &array[j]);
                j--;
            }
            else
            {
                j = -1; /* break out of the while */
            }
        }
    }
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

