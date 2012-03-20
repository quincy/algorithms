/*
 *
 */

#include <stdlib.h>
#include <stdio.h>

void print_array(int*, int);
void quickSort(int*, int, int);
int partition(int*, int, int);
void swap(int*, int*);

int main(int argc, char *argv[])
{
    int i;
    int length = argc - 1;
    int list[length];

    if ( length < 1 )
    {
        printf("You must supply a list of numbers to sort.\n");
        return 1;
    }

    for ( i=0; i<length; i++ )
    {
        list[i] = atoi(argv[i+1]);
    }

    print_array(list, length);
    quickSort(list, 0, length-1);

    print_array(list, length);
}

void print_array(int *a, int length)
{
    int i;

    for ( i=0; i<length; i++ )
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}

void quickSort(int *list, int p, int r)
{
    int q;

    if ( p < r )
    {
        q = partition(list, p, r);

        quickSort(list, p, q-1);
        quickSort(list, q+1, r);
    }
}

int partition(int *list, int p, int r)
{
    int x;
    int i;
    int j;

    x = list[r];
    i = p - 1;

    for ( j=p; j<r; j++ )
    {
        if ( list[j] <= x )
        {
            i++;
            swap(&list[i], &list[j]);
        }
    }

    swap(&list[i+1], &list[r]);

    return i + 1;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
