class Twitter {
public:
    // {timestamp, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweet;

    // user -> set of users they follow
    unordered_map<int, unordered_set<int>> following;

    int timer = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        
        // {timestamp, tweetId}
        // Smallest timestamp stays at top
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // Add user's own tweets
        for (auto &t : tweet[userId]) {
            pq.push(t);

            if (pq.size() > 10)
                pq.pop();
        }

        // Add tweets from people user follows
        for (auto &followee : following[userId]) {
            
            for (auto &t : tweet[followee]) {
                pq.push(t);

                if (pq.size() > 10)
                    pq.pop();
            }
        }

        vector<int> latestTweets;

        while (!pq.empty()) {
            latestTweets.push_back(pq.top().second);
            pq.pop();
        }

        // Heap gives oldest -> newest
        reverse(latestTweets.begin(), latestTweets.end());

        return latestTweets;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};