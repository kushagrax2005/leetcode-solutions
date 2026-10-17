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
        ListNode*head=new ListNode();
        ListNode*ans=head;
        int b=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++)
        {
            if(lists[i]!=nullptr)
            pq.push({lists[i]->val,i});
        }
        while(!pq.empty())
        {
            pair a=pq.top();
            pq.pop();
            ans->next=lists[a.second];
            ans=ans->next;
            lists[a.second]=lists[a.second]->next;
            if(lists[a.second]!=nullptr)pq.push({lists[a.second]->val,a.second});
        }
        return head->next;
    }
};