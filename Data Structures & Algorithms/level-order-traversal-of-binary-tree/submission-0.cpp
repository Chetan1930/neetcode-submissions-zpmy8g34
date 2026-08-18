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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr)return ans;

        TreeNode* base = root;
        queue<TreeNode*>q;
        q.push(base);
        while(!q.empty()){
            int n=q.size();
            vector<int>res;

            while(n>0){
                TreeNode* temp=q.front();
                res.push_back(temp->val);
                q.pop();

                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                n--;
            }
            ans.push_back(res);

        }

        return ans;

    }
};
