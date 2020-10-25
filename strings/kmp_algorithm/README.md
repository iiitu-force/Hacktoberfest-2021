# Knuth Morris Pratt Algorithm
[KMP Algorithm](https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm) is an efficient string searching or string matching algorithm invented by Donald Knuth, 
Vaughan Pratt and James H. Morris. It is a linear time algorithm that employs the observation that every time a match or a mismatch happens, the pattern itself contains enough
information to dictate where the new examination should begin from.

## Algorithm
KMP algorithm searches for a pattern in the given text by using LPS array (longest proper prefix which is also suffix) that is formed by preprocessing the pattern.

### Preprocessing of the pattern
* A one dimensional array is defined whose size is equal to length of the pattern (LPS[size]).
* Initializing l = 0, i = 1, LPS[0] = 0 
* Comparing the characters at pattern[i] and pattern[l], if both are matched then LPS[i] becomes l + 1 i.e. LPS[i] = l + 1 and the values of l, i are incremented.
* Else if both are not matched then then value of l is checked, if it is 0, then LPS[l] = 0, and increment i by one, else l = LPS[l - 1]
* These steps are repeated until all the values of LPS[] are filled.

<strong> Using this LPS array the pattern is searched in the given text as follows: </strong>
* Initialize i = 0 (the index for text string) and j = 0 (the index of pattern string)
* Comparing the characters at pattern[i] and pattern[j], if both are matched i and j both are incremented by 1.
* If j is equal to length of the pattern, it means the pattern is found at index i - j (0 based indexing) and j is set to LPS[j - 1].
* Else if there's a mismatch after j matches and i is less than the length of the text, there's no need to match LPS[0] to LPS[j - 1] characters, they will surely match.
  - If j is equal to 0 then i is incremented by 1 else j is set to LPS[j - 1].
* These steps are repeated until i becomes equal to n - 1, where n = length of text

## Pseudo Code
```
procedure lpsArray(pattern):
   m = len(pattern)
   lps[0] = 0
   j = 0 
   for i in range(1,m):
      while j >= 0 and pattern[j] != pattern[i]:
         if j-1 >= 0:
                j = lps[j-1]
         else:
                j =- 1 
      j += 1
      lps[i] = j
   return lps
end procedure
   
procedure find_occurrences(text, pattern)
   matches = []
   lps = lpsArray(pattern)
   n ,m = len(text), len(pattern)
   j = 0
   for i in range(n)
      while j >= 0 and text[i] != pattern[j]:
         if j > 0
            j = lps[j - 1]
         else
            j =- 1
      j += 1  
      if j == m
         j = lps[m - 1]
         matches.append(i - m + 1)
   return matches
end procedure
```   

## Example
Consider the following Text and Pattern </br>
Text : ABC ABCDAB ABCDABCDABDE </br>
Pattern : ABCDABD </br>
LPS[] is {0,1,2,3,4,5,6} </br>

**Step 1:** Start comparing first character of pattern with first character of Text from left to right

Text: ABC ABCDAB ABCDABCDABDE

Pattern: ABCDABD

0123456

Here mismatch occurred at Pattern[3],so we need to consider LPS[2] value. Since LPS[2] value is '0' we must compare first character in pattern with next character in Text.

**Step 2:** Start comparing first character of pattern with next character of Text.

Text : ABC ABCDAB ABCDABCDABDE

Pattern : ABCDABD

0123456

Here mismatch occurred at Pattern[6], so we need to consider LPS[5] value. Since LPS[5] value is '2' we compare Pattern[2] character with mismatched character in Text.

**Step 3:** Since LPS value is '2' no need to compare the Pattern[0] and Pattern[1] values

Text : ABC ABCDAB ABCDABCDABDE

Pattern : ABCDABD

0123456

Here mismatch occurred at pattern[2],so we need to consider LPS[1] value. Since LPS[1] value is  '0' we must compare first character in Pattern with next character in Text. 

**Step 4** Compare Pattern[0] with next character in Text

Text : ABC ABCDAB ABCDABCDABDE

Pattern : ABCDABD

0123456

Here mismatch occurred at Pattern[6], so we need to consider LPS[5] value. Since LPS[5] value is '2' we compare Pattern[2] character with mismatched character in Text.

**Step 5:** Compare Pattern[2] with mismatched character in Text.

Text : ABC ABCDAB ABCDABCDABDE

Pattern : ABCDABD

0123456

Here all the characters of Patterns matched with a substring in Text which is starting from index value 15.

*So, we conclude that given Pattern found at index 15 in Text.*

<b>Here is another example of string searching using KMP Algorithm</b>

![kmp_algorithm](https://user-images.githubusercontent.com/55757584/97105610-2ee34b80-16e2-11eb-8f58-d86b026792f8.png)

## Complexity
```
Time Complexity: O(n)
Space Complexity: O(m)
```
*where n = length of text, m = length of pattern* </br>

The time complexity of KMP algorithm is O(n). </br>
The space complexity of KMP alorithm is O(m) because some pre-processing is involved.
