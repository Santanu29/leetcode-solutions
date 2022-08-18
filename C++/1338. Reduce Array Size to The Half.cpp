class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> v;
        sort(begin(arr), end(arr));
        int n = arr.size();
        
        int c=1;
        
        for(int i=1;i<n;i++)
        {
            if(arr[i] == arr[i-1])
                c++;
            else
            {
                v.push_back(c);
                c=1;
            }
        }
        v.push_back(c);
        
        sort(begin(v), end(v), greater<>());
        
        int a=0, sum=n/2;
        for(int i=0;i<n && sum>0;i++)
        {
            a++;
            sum-=v[i];
        }
        return a;
    }
};
