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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a=0;
        ListNode*p=l1;
        ListNode*q=l2;
        ListNode*r=new ListNode();
        ListNode*rr=r;
        while(l1!=NULL&&l2!=NULL)
        {
            ListNode*node=new ListNode((l1->val+l2->val+a)%10);
            a=(l1->val+l2->val+a)/10;
            l1=l1->next;
            l2=l2->next;
            r->next=node;
            r=r->next;
        }
        while(l1!=NULL)
        {
            ListNode*node=new ListNode((l1->val+a)%10);
            a=(l1->val+a)/10;
            l1=l1->next;
            r->next=node;
            r=r->next;
        }
        while(l2!=NULL)
        {
            ListNode*node=new ListNode((l2->val+a)%10);
            a=(l2->val+a)/10;
            l2=l2->next;
            r->next=node;
            r=r->next;
        }
        if(a!=0)
        {
            ListNode*node=new ListNode(a%10);
            r->next=node;
            r=r->next;
        }
        return rr->next;
    }
};