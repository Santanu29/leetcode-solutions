class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        int res = n;
        int zcnt=0, fcnt=0;
        for(int i=n-1;i>=0;i--) {
            if(zcnt==1 && (num[i] == '5')) {
                    res = min(res, n-i-2);
            }
            if(fcnt == 1 && (num[i] == '2' || num[i] == '7')) {
                res = min(res, n-i-2);
                break;
            }
            if(num[i] == '5') {
                fcnt=1;
            }
            if(num[i] == '0') {
                zcnt++;
                res = min(res, n-1);
            }
            if(zcnt==2) {
                res = min(res, n-i-2);
                break;
            }
        }
        return res;        
    }
};
