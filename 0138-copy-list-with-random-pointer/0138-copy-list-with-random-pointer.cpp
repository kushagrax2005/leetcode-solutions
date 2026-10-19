/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node*root=new Node(-1);
        Node*p=root;
        Node*q=head;
        unordered_map<Node*,Node*>m;
        while(q!=nullptr)
        {
            p->next=new Node(q->val);
            p=p->next;
            m[q]=p;;
            q=q->next;
        }
        q=head;
        p=root->next;
        // m[nullptr]=nullptr;
        while(q!=nullptr)
        {
            p->random=m[q->random];
            q=q->next;
            p=p->next;
        }
        return root->next;
    }
};