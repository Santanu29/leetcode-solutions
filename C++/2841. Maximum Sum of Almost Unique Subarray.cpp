class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long res = 0, sum = 0;
        unordered_map<int, int> mpp;
        int n = nums.size();
        
        for(int i=0;i<k;i++) {
            mpp[nums[i]]++;
            sum += nums[i];
        }
        
        if(mpp.size()>=m) {
            res = sum;
        }
        
        for(int i=k;i<n;i++) {
            sum -= nums[i-k];
            mpp[nums[i-k]]--;
            if(mpp[nums[i-k]] == 0) {
                mpp.erase(nums[i-k]);
            }
            mpp[nums[i]]++;
            sum += nums[i];
            
            if(mpp.size() >= m) {
                res = max(res, sum);
            }
        }
        
        return res;
    }
};
