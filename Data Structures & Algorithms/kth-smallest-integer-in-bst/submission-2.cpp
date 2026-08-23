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
public:

    void inorder(TreeNode* root,vector<int>& key){
        if(root==nullptr)return ;
        inorder(root->left,key);
        key.push_back(root->val);
        inorder(root->right,key);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>key;
        inorder(root,key);
       if(k<= key.size())return key[k-1];

       return -1;
       
    }
};
