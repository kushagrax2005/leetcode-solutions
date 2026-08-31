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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>v;
        ListNode*p=head;
        int prev=p->val;
        int next=-1;
        int i=0;
        p=p->next;
        int maxi=0;
        int mini=INT_MAX;
        int pre=-1;
        int it=0;
        while(p)
        {
            if (p->next==NULL)
            {
                break;
            }
            else
            {
                next=p->next->val;
                if(p->val>next&&p->val>prev || p->val<next&&p->val<prev)
                {
                    if(pre==-1)
                    {
                        pre=i;
                        it=i;
                    }
                    else
                    {
                        maxi=i-it;
                        mini=min(mini,i-pre);
                    }
                    pre=i;
                }
                
            }
            prev=p->val;
            p=p->next;
            i++;
        }
        if(maxi==0)return {-1,-1};
        return {mini,maxi};
        // int maxi=v[v.size()-1]-v[0];
        // i=0;
        // int mini=INT_MAX;
        // while(i<v.size()-1)
        // {
        //     mini=min(mini,v[i+1]-v[i]);
        //     i++;
        // }
        return {mini,maxi};
    }
};