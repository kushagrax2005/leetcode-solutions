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
    ListNode* partition(ListNode* head, int x) {
        // ListNode* a=head;
        // ListNode* b=head;
        ListNode* p=head;
        ListNode*head1=new ListNode;
        ListNode*head2=new ListNode;
        ListNode*a=head1;
        ListNode*b=head2;
        while(p!=nullptr)
        {
            if(p->val<x)
            {
                a->next=new ListNode(p->val);
                a=a->next;
            }
            else
            {
                b->next=new ListNode(p->val);
                b=b->next;
            }
            p=p->next;
        }
        a->next=head2->next;
        return head1->next;
    }
};