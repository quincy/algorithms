/*
 * This program implements the Heap Sort algorithm.
 *
 * Heap Sort uses a data structure called a Heap to
 * sort a list of elements.  Using a Heap allows us
 * to sort in O(log n) time due to the nature of the
 * Heap structure.
 *
 * Our Heap Sort will use a type of Heap called a Max
 * Heap.  A Max Heap has the following properties:
 *
 * 1. It is a Complete Binary Tree.
 *
 * 2. Each node in the Heap is larger than either of
 *    its children.
 *
 * Heap Sort works by re-ordering the list into a 
 * Max Heap structure.  Then we simply move the root
 * node to the end of the list, remove that element 
 * from the Heap, and rebuild the remaining elements
 * into a valid Max Heap.  Then we can move the new
 * root element to the end of the list (1 position
 * to the left of the end actually) and re-build
 * the Heap again.  Continue until the list is sorted.
 */

#include "stdio.h"

int getLeftChild(int);
int getRightChild(int);
int getParent(int);
void printArray(int, int*);
void maxHeapify(int*, int, int);
void buildMaxHeap(int*, int);
void swap(int*, int*);
void heapSort(int*, int);

int main( int argc, char *argv[] )
{
    int length = argc-1;
    int list[length];
    int i;

    if ( argc == 1 )
    {
        printf("You must suplpy a list to sort.\n");
        return 1;
    }

    for ( i=1; i<argc; i++ )
    {
        list[i-1] = atoi(argv[i]);
    }

    heapSort(list, length);

    printArray(length, list);

    return 0;
}

/*
 * Perform the Heap Sort algorithm as described above.
 */
void heapSort(int *array, int length)
{
    int i;
    int heapLength = length;

    buildMaxHeap(array, length);

    for ( i=length-1; i>=1; i-- )
    {
        swap(&array[i], &array[0]);
        heapLength--;
        maxHeapify(array, 0, heapLength);
    }
}

/*
 * Reposition the element at index i to a correct position in the Heap.
 *
 * post: array is now a Max Heap.
 */
void maxHeapify(int *array, int i, int length)
{
    int largest;
    int l = getLeftChild(i);
    int r = getRightChild(i);

    if ( l <= length-1 && array[l] > array[i] )
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    if ( r <= length-1 && array[r] > array[largest] )
    {
        largest = r;
    }

    if ( largest != i )
    {
        swap(&array[i], &array[largest]);
        maxHeapify(array, largest, length);
    }
}

/*
 * Reposition the elements in array in order to make it a Max Heap.
 *
 * post: array is now a Max Heap.
 */
void buildMaxHeap(int *array, int length)
{
    int i;

    for ( i=length; i>=0; i-- )
    {
        maxHeapify(array, i, length);
    }
}

/*
 * Returns the index of the left child of node.
 */
int getLeftChild(int node)
{
    return (2 * node) + 1;
}

/*
 * Returns the index of the right child of node.
 */
int getRightChild(int node)
{
    return 2 * (node + 1);
}

/*
 * Returns the index of the parent of node.
 */
int getParent(int node)
{
    return (node - 1) / 2;
}

/*
 * Prints each element of the array.
 */
void printArray(int length, int *array)
{
    int i;

    for ( i=0; i<length; i++ )
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}

/* Swaps the values between the two given addresses. */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

