/*
Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

 

Example 1:

Input: x = 121
Output: true
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Example 4:

Input: x = -101
Output: false
 

Constraints:

-231 <= x <= 231 - 1

*/



// Solution by converting the number into string
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        
        string s=to_string(x);
        string rev;
        
        for(int i=s.length()-1;i>=0;i--)
        {
            rev = rev + s[i];
        }
        if(s.compare(rev)==0)
            return true;
        return false;
    }
};




// Solution Without converting number to string
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        
        int c=x;
        long p=0;
        
        while(x>0)
        {
            p=(p*10)+(x%10);
            x=x/10;
        }
        if(p==c)
            return true;
        return false;
  }
};  
