#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class TweetCounts {
   public:
    TweetCounts() {}

    void recordTweet(string tweetName, int time) {
        if (mm.find(tweetName) != mm.end()) {
            mm[tweetName].push_back(time);
            sort(mm[tweetName].begin(), mm[tweetName].end());
        } else {
            vector<int> v = {time};
            mm[tweetName] = v;
        }
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName,
                                           int startTime, int endTime) {
        int delta = 60;
        if (freq == "hour") {
            delta = 60 * 60;
        } else if (freq == "day") {
            delta = 60 * 60 * 24;
        }

        vector<int> v = mm[tweetName];
        vector<int> res;
        int i = 0;
        while (true) {
            if (startTime > endTime) break;

            // 对于当前这个间隔，计算个数
            int end = min(startTime + delta - 1, endTime);
            int count = 0;
            for (; i < v.size() && v[i] <= end; i++) {
                if (v[i] >= startTime) count++;
            }

            startTime += delta;
            res.push_back(count);
        }

        return res;
    }

    map<string, vector<int> > mm;
};

int main() {}