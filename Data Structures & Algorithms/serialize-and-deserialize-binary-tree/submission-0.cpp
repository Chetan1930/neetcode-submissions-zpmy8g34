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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res="";
        if(root==nullptr)return res;

        queue<TreeNode*>q;
        q.push(root);
        res+=to_string(root->val);
        res+="-";

        while(!q.empty()){
            int n=q.size();

            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    res+=to_string(temp->left->val);
                    res+="-";
                }
                else{
                    res+="#";
                    res+="-";
                } 

                if(temp->right){
                    q.push(temp->right);
                    res+=to_string(temp->right->val);
                    res+="-";
                }
                else {
                    res+="#";
                    res+="-";
                }
            }
        }
        return res;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        vector<string> v;
        string temp = "";

        for (char ch : data) {
            if (ch == '-') {
                v.push_back(temp);
                temp = "";
            } else {
                temp += ch;
            }
        }

        
        if (v.empty() || v[0] == "#") return nullptr;

        // Create root
        TreeNode* root = new TreeNode(stoi(v[0]));

        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while (!q.empty() && i < v.size()) {
            TreeNode* curr = q.front();
            q.pop();

            // Left child
            if (i < v.size() && v[i] != "#") {
                curr->left = new TreeNode(stoi(v[i]));
                q.push(curr->left);
            }
            i++;

            // Right child
            if (i < v.size() && v[i] != "#") {
                curr->right = new TreeNode(stoi(v[i]));
                q.push(curr->right);
            }
            i++;
        }

        return root;

    }
};
