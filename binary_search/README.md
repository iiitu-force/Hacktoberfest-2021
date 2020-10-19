# Binary Search 
[Binary Search](https://en.wikipedia.org/wiki/Binary_search_algorithm) is a widely used searching algorithm that requires the array to be sorted before search is applied.


## Algorithm
Binary Search keep on dividing the array in half until the element is found, or all the elements are exhausted.
It works by comparing the middle item of the array with our target, if it matches, it returns true otherwise if the middle term is greater than the target, the search is performed in the left sub-array.
If the middle term is less than target, the search is performed in the right sub-array.

## Prototype
```
binary_search(startaddress, endaddress, valuetofind)
startaddress: the address of the first element of the array.
endaddress: the address of the last element of the array.
valuetofind: the target value which we have to search for.
```

## Pseudo Code
```
Procedure binary_search
   A ← sorted array
   n ← size of array
   x ← value to be searched
   Set lowerBound = 1
   Set upperBound = n 
   while x not found
      if upperBound < lowerBound 
         EXIT: x does not exists.
   
      set midPoint = lowerBound + ( upperBound - lowerBound ) / 2
      
      if A[midPoint] < x
         set lowerBound = midPoint + 1
         
      if A[midPoint] > x
         set upperBound = midPoint - 1 
      if A[midPoint] = x 
         EXIT: x found at location midPoint
   end while
   
end procedure
```

## Example

Let us understand this algorithm with a example. We are finding 22 in a sorted list (1, 2, 4, 5, 8, 9, 11, 22, 23, 28, 32)

1. Here, mid element is 9 and 22 is greater than 9. So, it is in other half.
2. Then, new mid element is 23, 22 is less than 22 than means it is among indices between element 9 and 23.
3. Now mid is 11, that means it right of 11 or left of 23.
4. Finally found.

## Complexity

**Time Complexity -** О(log n), where n is the number of items being sorted.

**Space Complexity -** O(1), due to auxillary space only.


