class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        
        vector<long> sums(n, 0L);
        
        for(int i=0;i<n;i++)
        {
            sums[edges[i]] += i;
        }
        
        return max_element(begin(sums), end(sums)) - begin(sums);
    }
};
