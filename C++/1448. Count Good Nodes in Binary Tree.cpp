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
Here we are passing the greatest node value so far in the path to the current node.
If the greatest node is <= current node val then increment ans;

Next iteration, send the greatest value among the greatest so far and current node.
*/


class Solution {
    int ans;
    
    void helper(TreeNode* root, int greatest)
    {
        if(root==NULL)
            return;
        
        if(root->val >= greatest)
            ans++;
        
        greatest = max(greatest, root->val);
        helper(root->left, greatest);
        helper(root->right, greatest);
    }
public:
    int goodNodes(TreeNode* root) {
        ans=0;
        int greatest = root->val;
        helper(root, greatest);
        return ans;
    }
};
