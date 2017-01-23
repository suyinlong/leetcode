class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        timestamp = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (posts.find(userId) == posts.end()) {
            vector<pair<int, int>> newPost;
            posts[userId] = newPost;
        }
        posts[userId].push_back(make_pair(timestamp, tweetId));
        timestamp++;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        vector<int> fo(follows[userId].begin(), follows[userId].end());
        fo.push_back(userId);

        for (int uid: fo) {
            if (posts.find(uid) == posts.end()) continue;
            auto po = posts[uid];
            auto it = po.rbegin();
            for (int i = 0; i < min(10, (int)po.size()); i++) {
                pq.push(*it);
                it++;
            }
        }

        vector<int> result;
        for (int i = 0; i < 10; i++) {
            if (!pq.empty()) {
                result.push_back(pq.top().second);
                pq.pop();
            }
        }
        return result;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        if (follows.find(followerId) == follows.end()) {
            unordered_set<int> newFollow;
            newFollow.insert(followeeId);
            follows[followerId] = newFollow;
        }
        else {
            if (follows[followerId].count(followeeId))
                return;
            follows[followerId].insert(followeeId);
        }
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (follows.find(followerId) == follows.end() || follows[followerId].count(followeeId) == 0)
            return;
        follows[followerId].erase(followeeId);
    }

private:
    unordered_map<int, vector<pair<int, int>>> posts;
    unordered_map<int, unordered_set<int>> follows;
    int timestamp;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */