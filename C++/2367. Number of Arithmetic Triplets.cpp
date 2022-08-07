/*
    Checking if we have an n-diff and n-diff*2.
    If they have appeared earlier in the nums array then we have a valid triplet.
*/

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int arr[201]={}, res=0;
        
        for(int n : nums)
        {
            if(n >= diff*2)
            {
                res += (arr[n-diff] && arr[n - 2*diff]);
            }
            arr[n]=1;
        }
        return res;
    }
};
