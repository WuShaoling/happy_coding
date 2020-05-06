#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

struct Node {
    int userId;
    int index;
    int tweetId;
    long timestamp;
    Node(int uId, int idx, int tId, long time) {
        userId = uId;
        index = idx;
        tweetId = tId;
        timestamp = time;
    }
};

struct cmp {
    bool operator()(const Node* a, const Node* b) {
        return a->timestamp > b->timestamp;
    }
};

class Twitter {
   public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({tweetId, timestamp++});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<Node*, vector<Node*>, cmp> q;
        for (int followId : relationship[userId]) {
            if (posts[followId].size() > 0) {
                int index = posts[followId].size() - 1;
                pair<int, long> p = posts[followId][index];
                q.push(new Node(followId, index, p.first, p.second));
            }
        }
        if (posts[userId].size() > 0) {
            int index = posts[userId].size() - 1;
            pair<int, long> p = posts[userId][index];
            q.push(new Node(userId, index, p.first, p.second));
        }
        vector<int> ans;
        while (ans.size() < 10 && !q.empty()) {
            Node* node = q.top();
            // cout << it[0] << " " << it[1] << " " << it[2] << endl;
            q.pop();
            ans.push_back(node->tweetId);
            node->index--;
            if (node->index >= 0) {
                pair<int, long> p = posts[node->userId][node->index];
                node->tweetId = p.first;
                node->timestamp = p.second;
                q.push(node);
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        relationship[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        relationship[followerId].erase(followeeId);
    }

   private:
    long timestamp = 0;
    map<int, vector<pair<int, long>>> posts;
    map<int, set<int>> relationship;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main() {}