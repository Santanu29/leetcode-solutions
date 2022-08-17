class Solution {
    string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        int ans=0;
        unordered_set<string> s;
        
        for(string str : words)
        {
            string a="";
            for(char ch : str)
            {
                a += morse[ch-'a'];
            }
            s.insert(a);
        }
        return s.size();
    }
};
