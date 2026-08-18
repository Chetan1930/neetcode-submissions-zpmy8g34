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
    int countgood(TreeNode* root, int temp){
        if(root==nullptr)return 0;
        if(root->val>=temp){
            temp=root->val;
            return 1+ countgood(root->left,temp)+ countgood(root->right,temp);
        }

        return countgood(root->left,temp)+ countgood(root->right,temp);

    }
    int goodNodes(TreeNode* root) {
        
        int ans = countgood(root,INT_MIN);
        return ans;
    }
};
