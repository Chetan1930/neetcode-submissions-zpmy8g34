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
    bool isValidBST(TreeNode* root) {
        bool temp=true;
        if(root->left !=nullptr){
            temp = root->left->val < root->val;
            if(!temp)return false;
            else temp = isValidBST(root->left);
        }

        if(root->right !=nullptr){
            temp = root->right->val > root->val;
            if(!temp)return false;

            else temp = isValidBST(root->right);
        }

        return temp;
        
    }
};
