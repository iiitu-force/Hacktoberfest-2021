# Merge Sort

[Merge Sort](https://en.wikipedia.org/wiki/Merge_sort) is very efficient sorting algorithm. It works on the principle of divide and conquer. In merge sort, the given list is repeatedly divided into several
sublists until each sublist consists of single element and these sublists are merged in a manner that results into a sorted list.

## Algorithm
Merge sort keeps on dividing the list into equal halves until it can no more be divided. If there's only one element in the list, it is already sorted. 
Merge sort combines the smaller sorted lists keeping the new list sorted too.

* If there is only one element in the list it is already sorted.
* Divide the list repeatedly into two halves until it cannot be divided further.
* Merge the smaller lists into new list in sorted order.


## Psuedo Code
```
procedure mergesort( var a as array )
   if ( n == 1 ) return a
   var l1 as array = a[0] ... a[n/2]
   var l2 as array = a[n/2+1] ... a[n]
   l1 = mergesort( l1 )
   l2 = mergesort( l2 )
   return merge( l1, l2 )
end procedure
procedure merge( var a as array, var b as array )
   var c as array
   while ( a and b have elements )
      if ( a[0] > b[0] )
         add b[0] to the end of c
         remove b[0] from b
      else
         add a[0] to the end of c
         remove a[0] from a
      end if
   end while
   
   while ( a has elements )
      add a[0] to the end of c
      remove a[0] from a
   end while
   
   while ( b has elements )
      add b[0] to the end of c
      remove b[0] from b
   end while
   
   return c
	
end procedure
```

## Example
Suppose the given array is [56, 10, 89, 23, 9, 4]

* The input array contains 6 elements and middle of the array is 3 it is divided into array [56, 10, 89] and [23, 9, 4].

* The left and right sub arrays are divided repeatedly until only one element remains in each sublist.
The left array [56, 10, 89] is further divided into [56], [10, 89], in this case the left sub list contains only one element so can't be divided further and the right sub list is divided as [10] and [89].
These sublist [56], [10] and [89] are merged by comparing them and arranged in ascending order.
  - [56] and [10] are compared and merged [10, 56], then 10 and 56 are compared with 89 are the left sublist gets merged as [10, 56, 89].

  *Similarly the right sub list (i.e. [23, 9, 4]) is divided into [23], [9] and [4] and merged as [4, 9, 23].*

* The sorted left and right sublists are merged by comparing the elements of [10, 56, 89] and [4, 9, 23] </br>
 *and the sorted list becomes [5, 9, 10, 23, 56, 89].*</br>

 Here is another example of sorting an array using Merge Sort Algorithm:

![merge_sort](https://user-images.githubusercontent.com/55757584/96385094-3d47d980-11af-11eb-9f55-c3b2699bbf9b.png)

## Complexity
```
  Time Complexity: O(nlogn)
  Auxiliary Space: O(n)
```
The overall <strong> time complexity </strong> of merge sort is O(nlogn). It is very efficient as its runtime is O(nlogn) even for the worst case.</br>
The <strong> space complexity </strong> of merge sort is O(n) which means this algorithm takes a lot of space and may slow down the operations for the large data sets.
