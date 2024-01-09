​
​
**steps  for 4sum to be solved in O(n^2log n)
Convert it to problem with n*n elements
so now we have array of n*n each element is pair sum
so it became 2 sum problem but 2 pair can have column element so just check that the required complement sum doesn't have that common element.
​
Important inference if problem can be solvable with n*2 tc or more then it canbe converted 2 big problem like n*n problem then applying modified version of other problems of n size .
​
​
​
**
##### so n=200 , n*n*logn = 10^6 , n^3= 810^6*
#####
##### consider 3sum
##### steps :-
##### 1-sort the array
##### 2- traverse using i
##### 3- use while loop with j , k and check for a[j]+a[k]=target-a[i]
##### TC-O(nn)
​