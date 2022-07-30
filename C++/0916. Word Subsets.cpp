/*
You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.

 

Example 1:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]
Example 2:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
Output: ["apple","google","leetcode"]
 

Constraints:

1 <= words1.length, words2.length <= 104
1 <= words1[i].length, words2[i].length <= 10
words1[i] and words2[i] consist only of lowercase English letters.
All the strings of words1 are unique.
*/


/*
NOTE:
    In this solution we are combining the strings in the second array(words2). 
    We are combining them in such a way as the maximum number of each occurance of the characters is taken care of.
    Ex:
        ["ee", "oco", "ceo"] will be eeooc. Here the maximum number of the characters in the strings are taken. Like 'e' occurs a max of 2 times in "ee" and 'o' occurs 2 times in "oco".
        
    Lastly we check if the character frequency occurs in the string in words1. If the number of occurances of the characters in the strings is >= to the occurance in the merged string then, it is universal and added, else it is not.
*/

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        
        int arr[26] = {0};
        for(string b : words2)
        {
            int temp[26] = {0};
            
            for(char ch : b)
            {
                temp[ch-'a']++;
                arr[ch-'a'] = max(arr[ch-'a'], temp[ch-'a']);
            }
        }
        
        for(string a : words1)
        {
            int temp[26] = {0};
            
            for(char ch : a)
            {
                temp[ch-'a']++;
            }
            if(subset(temp, arr))
                ans.push_back(a);
        }
        return ans;
    }
    
    bool subset(int source[], int dest[])
    {
        for(int i=0;i<26;i++)
        {
            if(dest[i] > source[i])
                return false;
        }
        return true;
    }
};
