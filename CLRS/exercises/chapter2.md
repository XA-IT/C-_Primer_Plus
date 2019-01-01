#### 2.3.7
> Describe a O(nlgn) -time algorithm that, given a set S of n integers and another integer x, determines whether or not there exist two elements in S whose sum is exactly x.  

```
使用归并排序对S中n个整数进行排序得到set A；  
for i = 1 to A.length
    if (BINARY-SEARCH(A, x-i) != NIL)
        return true;

return false;
```
#### Problems 2-1
> 2-1 Insertion sort on small arrays in merge sort  
Although merge sort runs in O(n lg n) worst-case time and insertion sort runs in O(n2) worst-case time, the constant factors in insertion sort can make it faster in practice for small problem sizes on many machines. Thus, it makes sense to coarsen the leaves of the recursion by using insertion sort within merge sort when subproblems become sufficiently small. Consider a modification to merge sort in which n=k sublists of length k are sorted using insertion sort and then merged using the standard merging mechanism, where k is a value to be determined.    
a. Show that insertion sort can sort the n/k sublists, each of length k, in O(nk) worst-case time.  
b. Show how to merge the sublists in O(n lg(n/k)) worst-case time.  
c. Given that the modified algorithm runs in O(nk + n lg(n/k)) worst-case time,
what is the largest value of k as a function of n for which the modified algorithm has the same running time as standard merge sort, in terms of O-notation?
d. How should we choose k in practice?    

