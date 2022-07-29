/*
Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

 

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
  
Example 2:

Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]
 

Constraints:

1 <= pattern.length <= 20
1 <= words.length <= 50
words[i].length == pattern.length
pattern and words[i] are lowercase English letters.
*/


/*
    Notes:
    We are checking with mapping if the pattern is possible or not.
    
    There are two unordered_map that we are using to keep the mapping of characters.
    
    1. We see if a character of word has a unique mapping to a character of pattern
    2. Similarly, we see if character of pattern has a unique mapping to a character of word
    3. Final condition we check if the value stored in the mapping is the same and is not changed. A change may occur when 2 chars are mapped to the same character of pattern.
    In that case the permutation is not possible and hence it is not valid.
*/

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for(string word : words)
        {
            if(matches(word, pattern))
                ans.push_back(word);
        }
        return ans;
    }
    
    bool matches(string w, string p)
    {
        unordered_map<char, char> wordToPattern, patternToWord;
        
        for(int i=0;i<w.size();i++)
        {
            if(wordToPattern.find(w[i]) == wordToPattern.end())
                wordToPattern[w[i]] = p[i];
            
            if(patternToWord.find(p[i]) == patternToWord.end())
                patternToWord[p[i]] = w[i];
            
            if(patternToWord[p[i]] != w[i] || wordToPattern[w[i]] != p[i])
                return false;
        }
        return true;
    }
};
