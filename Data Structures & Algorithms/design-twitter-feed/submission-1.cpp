class Twitter {
public:
    unordered_map<int,vector<int>>tweet;
    unordered_map<int,vector<int>>following;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back(tweetId);
        return ;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<int,vector<int>,greater<int>>pq;

        for(auto &i:tweet[userId]){
            pq.push(i);
            if(pq.size()>10)pq.pop();
        }

        for(auto &j:following[userId])
        for(auto &i:tweet[j]){
            pq.push(i);
            if(pq.size()>10)pq.pop();
        }

        vector<int>lastesttweet;

        while(!pq.empty()){
            lastesttweet.push_back(pq.top());
            pq.pop();
        }
        reverse(lastesttweet.begin(),lastesttweet.end());

        return lastesttweet;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].push_back(followeeId);
        return ;
    }
    
    void unfollow(int followerId, int followeeId) {
        vector<int>followers = following[followerId];
        
        erase(followers,followeeId);
        following[followerId]=followers;

        return ;
    }
};
