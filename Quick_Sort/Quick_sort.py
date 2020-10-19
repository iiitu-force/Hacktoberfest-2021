def quicksort(a, start, end):
    ##'Sorts the list from indexes start to end - 1 inclusive.'
    if end - start > 1:
        p = partition(a, start, end)
        quicksort(a, start, p)
        quicksort(a, p + 1, end)
 
 
def partition(a, start, end):
    pivot = a[start]
    i = start + 1
    j = end - 1
 
    while True:
        while (i <= j and a[i] <= pivot):
            i = i + 1
        while (i <= j and a[j] >= pivot):
            j = j - 1
 
        if i <= j:
            a[i], a[j] = a[j], a[i]
        else:
            a[start], a[j] = a[j], a[start]
            return j
 
 
a = input('Enter the list of numbers: ').split()
a = [int(x) for x in a]
quicksort(a, 0, len(a))
print('Sorted list: ', end='')
print(a)
#The user has to enter a list of numbers.
#The list is passed to the quicksort function.
#The sorted list is displayed.
