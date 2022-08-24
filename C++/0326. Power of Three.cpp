class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1)
            return false;
        else if(n==1)
            return true;
        
        while(n>1)
        {
            if(n%3==0)
            {
                n = n/3;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
