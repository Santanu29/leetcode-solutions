class Solution {
    void dfs(int current, int digitsLeft, vector<int>& ans, int k)
    {
        if(digitsLeft==0)
        {
            ans.push_back(current);
            return;
        }
        
        int lastDigit = current%10;
        
        if((lastDigit + k) <= 9)
            dfs((current*10) + lastDigit + k, digitsLeft-1, ans, k);
        
        if((lastDigit - k) >= 0 && k>0)
            dfs((current*10) + lastDigit - k, digitsLeft-1, ans, k);
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        
        for(int i=1;i<10;i++)
            dfs(i, n-1, ans, k);
        
        return ans;
    }
};
