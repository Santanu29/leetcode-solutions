/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


/*
The important part is to check if the children nodes vector is empty or not.
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL)
            return {};
        
        vector<vector<int>> res;
        queue<Node*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> row(size);
            for(int i=0;i<size;i++)
            {
                Node *n = q.front();
                q.pop();
                
                if(!n->children.empty())
                {
                    for(auto c : n->children)
                    {
                        q.push(c);
                    }
                }
                
                row[i] = n->val;
            }
            
            res.push_back(row);
        }
        return res;
    }
};
