class Solution {
public:

    bool diffByOne(string& a, string& b) {
        int count = 0;

        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i])
                count++;
        }

        return count == 1;
    }

    int ladderLength(string beginWord,
                     string endWord,
                     vector<string>& wordList) {

        if(find(wordList.begin(), wordList.end(), endWord)
           == wordList.end())
            return 0;

        // Add beginWord
        wordList.push_back(beginWord);

        unordered_map<string, vector<string>> adj;

        int n = wordList.size();

        // Build graph
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {

                if(diffByOne(wordList[i], wordList[j])) {
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        // BFS
        queue<string> q;
        unordered_set<string> visited;

        q.push(beginWord);
        visited.insert(beginWord);

        int level = 1;

        while(!q.empty()) {

            int size = q.size();

            for(int i = 0; i < size; i++) {

                string word = q.front();
                q.pop();

                if(word == endWord)
                    return level;

                for(auto &next : adj[word]) {

                    if(!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            level++;
        }

        return 0;
    }
};