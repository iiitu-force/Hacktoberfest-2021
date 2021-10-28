#include <iostream>
using namespace std;

int linear_search(int a[], int s, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        if (a[i] == s)
            return i;
    return -1;
}

int binary_search(int a[100], int key, int n)
{
    int beg = 0, end = n - 1, mid;
    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            end = mid - 1;
        else
            beg = mid + 1;
    }
    return -1;
}

int insertion(int a[], int s, int n)
{
    int i, j, pos = -1;
    if (a[0] > s)
        pos = 0;
    for (i = 0; i < n; ++i)
        if (a[i] <= s && a[i + 1 > s])
            pos = i + 1;
    if (a[n - 1] < s)
        pos = n;
    for (j = n; j >= pos; --j)
        a[j + 1] = a[j];
    a[pos] = s;
    return ++n;
}

int deletion(int a[], int s, int n)
{
    int i, j, pos = -1;
    for (i = 0; i < n; ++i)
    {
        pos = -1;
        if (a[i] == s)
            pos = i;
        if (pos != -1)
        {
            for (j = pos; j < n; ++j)
                a[j] = a[j + 1];
            a[j] = 0;
            --n, --i;
        }
    }
    return n;
}

void selection_sort(int a[], int n)
{
    int i, j, small, pos;
    for (j = 0; j < n; ++j)
    {
        small = a[j];
        for (i = j; i < n; ++i)
        {
            if (a[i] < small)
            {
                small = a[i];
                pos = i;
            }
            if (a[j] > small)
                swap(a[j], a[pos]);
        }
    }
}

void bubble_sort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; ++i)
        for (j = 0; j < n - i - 1; ++j)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

void insertion_sort(int a[], int n)
{
    int i, j, k;
    for (i = 1; i < n; ++i)
    {
        k = a[i];
        for (j = i - 1; a[j] > k && j >= 0; --j)
            a[j + 1] = a[j];
        a[j + 1] = k;
    }
}

void print_array(int a[], int n)
{
    cout << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}