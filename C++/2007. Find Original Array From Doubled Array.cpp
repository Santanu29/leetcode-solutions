class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int, int> m;
        vector<int> res;
        sort(begin(changed), end(changed));
        
        if(changed.size()%2!=0)
            return {};
        
        for(int i : changed)
            m[i]++;
        
        for(int i : changed)
        {
            if(m[i]==0)
                continue;
            
            if(m[i*2]==0)
                return {};
            
            res.push_back(i);
            m[i]--;
            m[i*2]--;
        }
        return res;
    }
};
