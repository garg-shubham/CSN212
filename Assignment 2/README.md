# Assignment 2 ( Dynamic Programming )

## Problem 1 (ZigZag)
[Problem link](https://community.topcoder.com/stat?c=problem_statement&pm=1259)  

#### Approach:
    Dynamic programming approach with with this simple observation:
    For subarray a[i:j], if a[i] < a[i+1] <...< a[j], then length of longest zigzag subsequence with last positve diffrence is same for subarray a[0:x] where x belongs to [i+1,j]. Similar approach is followed for a decreasing subarray.
#### Complexity: 
    Time Complexity: O(n)
    Space Complexity: O(n)

## Problem 2 (Avoid Roads)
[Problem link](https://community.topcoder.com/stat?c=problem_statement&pm=1889)

#### Approach:
    Simple dynamic programming approach with results for subproblems stored in a 2-D array.
#### Complexity
    Time Complexity: O(n^2)
    Space Complexity: O(n^2)

## Problem 3 (Lucky Draw)
[Problem link](https://www.codechef.com/problems/D2/)

#### Approach
    Since given array is circular, so starting index of the array is not fixed. So, find longest increasing subsequence of the array for n times, each time changing the starting index. Maximum of all these values is the answer.

#### Complexity
    Time Complexity: O(n^2 log(n))
    Space Complexity: O(n)