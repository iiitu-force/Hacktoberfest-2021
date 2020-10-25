#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

// function to compute LPS (longest proper prefix which is also suffix)
void lpsArray(string pattern, int length, int lps[])
{
    // length of previous longest prefix suffix 
    int l = 0, i = 0;
    lps[0] = 0;
    // finding the lps[i] from i = 1 to i = length - 1; since lps[0] = 0
    i = 1;
    while (i < length - 1)
    {
        if (pattern[i] == pattern[l])
        {
            l++;
            lps[i] = l;
            i++;
        }
        else {
            if (l != 0)
            {
                l = lps[l - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// function to search for the pattern in the given text according to KMP algorithm
void search(string text, string pattern) 
{
    int length_of_text = text.length();
    int length_of_pattern = pattern.length();
    // array to hold the longest prefux suffix values for the pattern
    int *lps= new int[length_of_pattern];
    // preprocessing the pattern to calculate lps array
    lpsArray(pattern, length_of_pattern, lps);
    int i = 0, j = 0; // i = index for text string and j = index for pattern string
    while (i < length_of_text) {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }
        if (j == length_of_pattern)
        {
            cout << "The pattern is found at: " << i - j << endl;
            j = lps[j - 1];
        }
        // if there's a mismatch after j
        else if (i < length_of_text && pattern[j] != text[i])
        {
            if (j != 0)
            j = lps[j - 1];
            else
            i++;
        }
    }
}

int main()
{
    string text, pattern;
    cout << "Enter the string or text: ";
    cin >> text;
    cout << "Enter the pattern to search for: ";
    cin >> pattern;
    search(text, pattern);
    return 0;
}
