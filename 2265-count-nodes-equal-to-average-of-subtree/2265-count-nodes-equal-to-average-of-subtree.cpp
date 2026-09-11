/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* copy(TreeNode* root)
    {
        if(root==NULL)return NULL;

        TreeNode* p=new TreeNode(root->val);
        p->left=copy(root->left);
        p->right=copy(root->right);

        return p;
    }
    void dfs(TreeNode*root,TreeNode*&p,TreeNode*c,int &ans)
    {
        if(root==NULL)return ;
        if(p->val!=-1)return ;
        dfs(root->left,p->left,c->left,ans);
        dfs(root->right,p->right,c->right,ans);
        p->val=root->val;
        if(p->left!=NULL)p->val+=p->left->val;
        if(p->right!=NULL)p->val+=p->right->val;
        if(p->val/c->val==root->val)ans++;
    }
    void con(TreeNode*&p)
    {
        if(p==NULL)return ;
        p->val=-1;
        con(p->left);
        con(p->right);
    }
    void count(TreeNode*&c)
    {
        if(c==NULL)return ;
        count(c->left);
        count(c->right);
        c->val=1;
        if(c->left!=NULL)c->val+=c->left->val;
        if(c->right!=NULL)c->val+=c->right->val;
    }
public:
    int averageOfSubtree(TreeNode* root) {
        TreeNode*p=copy(root);
        TreeNode*c=copy(root);
        count(c);
        con(p);
        int ans=0;
        dfs(root,p,c,ans);
        return ans;
    }
};