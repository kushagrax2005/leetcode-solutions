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
        ListNode*head1=new ListNode(-1);
        ListNode*head2=new ListNode(-1);
        ListNode*a=head1;
        ListNode*b=head2;
        while(p!=nullptr)
        {
            if(p->val<x)
            {
                head1->next=p;
                p=p->next;
                head1=head1->next;
                head1->next=nullptr;
            }
            else
            {
                head2->next=p;
                p=p->next;
                head2=head2->next;
                head2->next=nullptr;
            }
        }
        head1->next=b->next;
        return a->next;
    }
};