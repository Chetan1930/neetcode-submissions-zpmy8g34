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
    int ans(TreeNode* root,int curr,int g){
        if(root==nullptr)return 0;
        // curr=max(curr,root->val);
        g=max(g,curr);

        int lg = ans(root->left,curr,g);
        int rg = ans(root->right,curr,g);

        return g;
    }
    int maxPathSum(TreeNode* root) {
        int globalMax=INT_MIN;

        return ans(root,root->val,globalMax);
    }
};
