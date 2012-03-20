#!/usr/bin/perl
#
# This is an implementation of the BubbleSort algorithm.
#
# BubbleSort works by repeatedly walking through a list of
# elements and comparing adjacent values.  If the value on 
# the left is greater than the value on the right they are
# swapped.  This is repeated until a pass through the list
# causes no swaps to be performed.
#
# This BubbleSort is optimized to prevent examining elements
# which are already in the correct position.  After the first
# pass the largest element will always be at the end of the 
# list which is its correct position.  After the second pass
# the next largest element will be at the n-1 position, also
# its correct position, and so on.  You can say that the length
# of the unsorted portion of the list is n at the beginning
# of the procedure and it is decreased by 1 with every pass.
# So by only visiting elements in the unsorted portion of
# the list we can reduce the number of iterations required
# to sort the list.  The total number of swaps will remain 
# unchanged, however.
#
# One more optimization would be to always check if we have
# made any swaps on a pass and exit if not.


use strict;
use warnings;

my @array = @ARGV;

@array = bubble_sort(@array);
print "@array\n";

exit 0;

# function: bubble_sort(LIST)
#
# Sorts the values of LIST using the Bubble Sort
# algorithm described above and returns the
# sorted LIST.
sub bubble_sort
{
    my @array    = @_;
    my $unsorted = scalar @array;

    # This loop controls the number of passes over
    # the array.  
    for ( my $i = 0; $i < scalar @array; $i++ )
    {
        my $swap = undef;

        # This loop walks the array and swaps when
        # necessary.
        for ( my $j = 0; $j < $unsorted - 1; $j++ )
        {
            if ( $array[$j] > $array[$j+1] )
            {
                $swap        = $array[$j];
                $array[$j]   = $array[$j+1];
                $array[$j+1] = $swap;
            }
        }

        last  if ( ! defined $swap );   # exit early if we didn't swap anything
        $unsorted--;                      # reduce the length of the unsorted portion
    }

    return @array;
}
