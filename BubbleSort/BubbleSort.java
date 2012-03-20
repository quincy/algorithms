/**
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

public class BubbleSort
{
    /**
     * Demonstrates the Bubble Sort algorithm.
     *
     * @param args The list of integers to sort.
     */
    public static void main( String[] args )
    {
        int length  = args.length;
        int[] array = new int[length];

        // get the array of ints from the args
        for ( int s=0; s<args.length; s++)
        {
            array[s] = Integer.parseInt(args[s]);
        }

        bubbleSort(array);

        printArray(array);
    }

    /**
     * The Bubble Sort algorithm described above.
     *
     * @param array an array of int to sort.
     */
    public static void bubbleSort( int[] array )
    {
        int unsorted = array.length;

        // This loop controls the number of passes over
        // the array.  
        for ( int i = 0; i < array.length; i++ )
        {
            //printArray(array);
            int swap = Integer.MIN_VALUE;

            // This loop walks the array and swaps when
            // necessary.
            for ( int j = 0; j < unsorted - 1; j++ )
            {
                if ( array[j] > array[j+1] )
                {
                    swap       = array[j];
                    array[j]   = array[j+1];
                    array[j+1] = swap;
                }
            }

            // exit early if we didn't swap anything
            if ( swap == Integer.MIN_VALUE )
            {
                break;
            }

            unsorted--;    // reduce the length of the unsorted portion
        }
    }

    /**
     * Prints the array values.
     *
     * @param a the array to print.
     */
    public static void printArray( int[] a )
    {
        for ( int i=0; i<a.length; i++ )
        {
            System.out.print( a[i] + " " );
        }
        System.out.println();
    }
}
