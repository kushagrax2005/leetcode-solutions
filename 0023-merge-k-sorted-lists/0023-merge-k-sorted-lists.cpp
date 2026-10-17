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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        // vector<ListNode*>v;
        ListNode*head=new ListNode();
        ListNode*ans=head;
        int b=0;
        while(true)
        {
            // int a=0;
            // ListNode*a;
            int a=0;
            b=INT_MAX;
            for(int i=0;i<n;i++)
            {
                if(lists[i]!=nullptr&&lists[i]->val<b)
                {
                    b=lists[i]->val;
                    // a=lists[i];
                    a=i;
                }
            }
            if(b==INT_MAX)break;
            ans->next=lists[a];
            lists[a]=lists[a]->next;
            // ListNode*aa=new ListNode;
            // ans->next=aa;
            ans=ans->next;
            // ans->val=b;
        }
        // ans=nullptr;
        return head->next;
    }
};