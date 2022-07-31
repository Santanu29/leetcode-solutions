/*
You are given a positive integer array grades which represents the grades of students in a university. You would like to enter all these students into a competition in ordered non-empty groups, such that the ordering meets the following conditions:

The sum of the grades of students in the ith group is less than the sum of the grades of students in the (i + 1)th group, for all groups (except the last).
The total number of students in the ith group is less than the total number of students in the (i + 1)th group, for all groups (except the last).
Return the maximum number of groups that can be formed.

 

Example 1:

Input: grades = [10,6,12,7,3,5]
Output: 3
Explanation: The following is a possible way to form 3 groups of students:
- 1st group has the students with grades = [12]. Sum of grades: 12. Student count: 1
- 2nd group has the students with grades = [6,7]. Sum of grades: 6 + 7 = 13. Student count: 2
- 3rd group has the students with grades = [10,3,5]. Sum of grades: 10 + 3 + 5 = 18. Student count: 3
It can be shown that it is not possible to form more than 3 groups.
Example 2:

Input: grades = [8,8]
Output: 1
Explanation: We can only form 1 group, since forming 2 groups would lead to an equal number of students in both groups.
 

Constraints:

1 <= grades.length <= 10^5
1 <= grades[i] <= 10^5
*/


/*
NOTE:
    There are n students.
    SO, 1 + 2 + 3 + .... + k <= n, where n is the total number of students.
    
    There will be k number of groups. We will find this k by applying binary search.
    k*(k+1)/2 should be <= n. We need to find this k.
    
    There is also another way where we iteratively keep adding natural numbers until the total is more than n. In that case the number of iterations is the answer.
*/

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int l=0, n=grades.size(), r=n;
        
        while(l<r)
        {
            long k = (l+r+1)/2;
            if(k*(k+1)/2 > n)
            {
                r=k-1;
            }
            else
            {
                l=k;
            }
        }
        return l;
    }
};
