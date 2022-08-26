/*
We are converting to string and then sort them. 
After that we keep checking it with powers of 2s in sorted form

Ex: 46. 
46 is not a power of 2, but if we rearrange the digits, 64 is a power of two.
We convert and sort it so the string is 46.
then we calculate all the powers of 2s and check with it .
2, 4, 8, 16, 32(sorted to 23), 64(sorted to 46), 128, 256, 512(sorted to 125) and so on.

*/

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = n_num(n);
        for(int i=0;i<32;i++)
        {
            if(s == n_num(1<<i))
                return true;
        }
        return false;
    }
    
    string n_num(int n)
    {
        string res = to_string(n);
        sort(begin(res), end(res));
        return res;
    }
};
