/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int nodeCount=0;

        ListNode *p = head;

        while(p!=NULL) {
            nodeCount++;
            p = p->next;
        }

        vector<ListNode*> res(k, nullptr);
        vector<int> nodes(k, nodeCount/k);
        int n = nodeCount%k;
        for(int i=0;n>0;i++) {
            nodes[i]++;
            n--;
        }

        p = head;
        int i = 0;
        while(p!=NULL) {
            res[i] = p;
            for(int j = 1; j<nodes[i];j++) {
                p = p->next;
            }
            ListNode *temp = p;
            cout << p->val << " ";
            p=p->next;
            temp->next = NULL;
            i++;
        }

        return res;
    }
};
