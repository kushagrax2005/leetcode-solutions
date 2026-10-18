/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        q.push(root);
        if(root==nullptr)return root;
        while(!q.empty())
        {
            int l=q.size();
            while(true)
            {
            Node*r=q.front();
            q.pop();
            if(r->left)
            {
                q.push(r->left);
            }
            if(r->right)
            {
                q.push(r->right);
            }
            l--;
            if(l==0)break;
            r->next=q.front();
            }
        }
        return root;
    }
};