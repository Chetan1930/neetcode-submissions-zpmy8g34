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
    if (find(following[followerId].begin(),
             following[followerId].end(),
             followeeId) == following[followerId].end()) {
        
        following[followerId].push_back(followeeId);
    }
}
    
    void unfollow(int followerId, int followeeId) {
        vector<int>followers = following[followerId];
        
       followers.erase(
    remove(followers.begin(), followers.end(), followeeId),
    followers.end()
);
        following[followerId]=followers;

        return ;
    }
};
