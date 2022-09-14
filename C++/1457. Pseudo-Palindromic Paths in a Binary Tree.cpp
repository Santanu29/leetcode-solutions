/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
Here we are doing a DFS on the BT. We are counting the node values in the path and storing them in a map. Then we are checking if there is any odd number of occurance of node values. If the odd number of occurance is <= 1 then the node values can be rearranged into a palindrome.
*/

class Solution {
    int ans;
    unordered_map<int, int> m;
    
    void helper(TreeNode* root)
    {
        if(!root)
            return;
        
        m[root->val]++;
        
        if(!root->left && !root->right)
        {
            int temp=0;
            
            for(int i=1; i<=9;i++)
            {
                if(m[i]%2==1)
                    temp++;
            }
            if(temp<=1)
                ans++;
        }
        
        helper(root->left);
        helper(root->right);
        
        m[root->val]--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        ans=0;
        helper(root);
        return ans;
    }
};
