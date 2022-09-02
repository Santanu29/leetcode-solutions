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
Similar to level order search. We take the size of the current level and sum up the values of all the nodes in that level. Then insert the average it into the ans array.
*/


class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        
        while(!q.empty())
        {
            int size=q.size();
            double sum=0;
            for(int i=0;i<size;i++)
            {
                auto p = q.front();
                q.pop();

                TreeNode *node = p.first;
                int level = p.second;
                
                sum+=node->val;
                
                if(node->left != NULL)
                    q.push(make_pair(node->left, level+1));
                
                if(node->right != NULL)
                    q.push(make_pair(node->right, level+1));
            }
            ans.push_back(sum/size);
        }
        return ans;
    }
};
