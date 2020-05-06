#include <queue>
#include <string>
#include <vector>

using namespace std;

class MedianFinder {
   public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        lo.push(num);

        hi.push(lo.top());
        lo.pop();

        if (lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian() {
        if (lo.size() > hi.size()) return (double)lo.top();
        return (lo.top() + hi.top()) / 2;
    }

    priority_queue<int> lo;  // 大根堆，左半部分
    priority_queue<int, vector<int>, greater<int>> hi;  // 小根堆，右半部分
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {}