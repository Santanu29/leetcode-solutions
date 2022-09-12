class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(begin(tokens), end(tokens));
        
        int i=0, j=tokens.size()-1;
        int score=0, maxScore=0;
        
        while(i<=j)
        {
            if(tokens[i]<=power)
            {
                power -= tokens[i];
                score++;
                maxScore = max(score, maxScore);
                i++;
            }
            else if(score > 0)
            {
                power += tokens[j];
                j--;
                score--;
            }
            else
                break;
        }
        return maxScore;
    }
};
