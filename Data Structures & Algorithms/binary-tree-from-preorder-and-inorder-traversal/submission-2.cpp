class Solution {
public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return nullptr;

        int temp = preorder[0];

        TreeNode* root = new TreeNode(temp);

        int i = 0;
        while (inorder[i] != temp) {
            i++;
        }

        vector<int> leftPreorder(
            preorder.begin() + 1,
            preorder.begin() + i + 1
        );

        vector<int> rightPreorder(
            preorder.begin() + i + 1,
            preorder.end()
        );

        vector<int> leftInorder(
            inorder.begin(),
            inorder.begin() + i
        );

        vector<int> rightInorder(
            inorder.begin() + i + 1,
            inorder.end()
        );

        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};