class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string e1, e2, o1, o2;
        int n = s1.size();
        
        for(int i=0;i<n;i++) {
            if(i%2) {
                o1.push_back(s1[i]);
                o2.push_back(s2[i]);
            } else {
                e1.push_back(s1[i]);
                e2.push_back(s2[i]);
            }
        }
        
        sort(begin(o1), end(o1));
        sort(begin(o2), end(o2));
        sort(begin(e1), end(e1));
        sort(begin(e2), end(e2));
        
        return o1 == o2 && e1 == e2;
    }
};
