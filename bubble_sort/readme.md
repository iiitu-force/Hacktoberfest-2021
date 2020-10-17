# BUBBLE SORT

[Bubble Sort](https://en.wikipedia.org/wiki/Bubble_sort) is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order. It makes multiple passes through a list, compares adjacent items and exchanges those that are out of order. Each pass through the list places the next largest value in its proper place.

## PSEUDOCODE

We use one flag variable swapped which will help us to see if any swap is happened or not. If no swap is occurred, i.e. the array requires no more processing to be sorted, it will come out of the loop.

Pseudocode of BubbleSort algorithm can be expressed as −

```
procedure bubbleSort(list : array of items)

    loop = list.count;

    for i = 0 to loop-1 do:
        swapped = false

        for j = 0 to loop-i-1 do:

            /* compare the adjacent elements */
            if list[j] > list[j+1] then
                /* swap them */
                swap(list[j], list[j+1])
                swapped = true
            end if

        end for

        /*if no number was swapped that means
        array is sorted now, break the loop.*/

        if(not swapped) then
            break
        end if
    end for

end procedure and return list
```

## COMPLEXITY

**Time complexity**  - О(n^2), where n is the number of items being sorted.

**Space complexity** - O(1), due to auxillary space only.
