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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        if(root==nullptr)return res;

        TreeNode* base = root;
        queue<TreeNode*>q;
        q.push(base);
        while(!q.empty()){
            int n=q.size();

            while(n>0){
                TreeNode* temp=q.front();
                if(n==1)res.push_back(temp->val);
                q.pop();

                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                n--;
            }
        }

        return res;
    }
};
