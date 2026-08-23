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
    int solve(TreeNode* root,int &ans){
        if(root==nullptr)return 0;

        int leftsum = max(0, solve(root->left,ans));
        int rightsum = max(0,solve(root->right,ans));

        ans=max(ans,(root->val + leftsum + rightsum));

        return root->val + leftsum + rightsum;
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        cout<<solve(root,ans);

        return ans;
    }
};
