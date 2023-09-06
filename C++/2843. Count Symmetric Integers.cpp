class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res=0;
        for(int i=low; i<=high;i++) {
            if(i>10 && i<100) {
                string s = to_string(i);
                res += s[0] == s[1];
            } else if(i>1000) {
                string s = to_string(i);
                if((s[0]-'0') + (s[1]-'0') == (s[2]-'0') + (s[3]-'0')) {
                    res++;
                }
            }
        }
        return res;
    }
};
