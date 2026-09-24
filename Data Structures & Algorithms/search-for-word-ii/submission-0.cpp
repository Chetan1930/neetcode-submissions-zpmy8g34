class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;
    
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Solution {
public:
    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    bool exist(std::vector<std::vector<char>>& board, int i, int j, TrieNode* root) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || !root)
            return false;
        
        if (root->isEndOfWord)
            return true;
        
        char c = board[i][j];
        root = root->children[c - 'a'];
        board[i][j] = '#';  // mark this cell as visited
        
        bool found = exist(board, i + 1, j, root) || exist(board, i - 1, j, root) ||
                     exist(board, i, j + 1, root) || exist(board, i, j - 1, root);
        
        board[i][j] = c;  // backtrack and mark the cell as unvisited
        
        return found;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode root;
        for (auto word : words) {
            insert(&root, word);
        }

        vector<string> result;
        for (auto word : words) {
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    if (exist(board, i, j, root.children[board[i][j] - 'a'])) {
                        if (root.children[board[i][j] - 'a']->isEndOfWord) {
                            result.push_back(word);
                            root.children[board[i][j] - 'a']->isEndOfWord = false;
                        }
                        break;
                    }
                }
            }
        }
        return result;
    }
};