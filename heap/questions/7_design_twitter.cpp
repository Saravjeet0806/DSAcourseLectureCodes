class Twitter {
    private: 
    int time;
    unordered_map<int, unordered_set<int>> mp; // Stores followers
    unordered_map<int, vector<pair<int, int>>> mp2; // Stores tweets (time, tweetId)
public:
    Twitter() {
        time =0;
    }
    
    void postTweet(int userId, int tweetId) {
        mp2[userId].emplace_back(time, tweetId);
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>>pq;  //first stores the time stamp and second stores the tweetID
        for(auto i : mp2[userId]){
            pq.push(i); //Add userId’s tweets to pq
        }
        for(auto i : mp[userId]){
            for(auto j : mp2[i]){
                pq.push(j);  // For each followee of userId → add their tweets to pq.
            }
        }

        vector<int> feed;
        int count =10;
        while(!pq.empty() && count){
            feed.push_back(pq.top().second);
            pq.pop(); // Pop up to 10 tweets to get the most recent ones
            count--;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
    }
};
