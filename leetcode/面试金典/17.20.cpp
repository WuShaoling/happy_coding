#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
   public:
    MedianFinder() {}

    void addNum(int num) {
        bigHeap.push(num);
        smallHeap.push(bigHeap.top());
        bigHeap.pop();

        if (smallHeap.size() > bigHeap.size()) {
            bigHeap.push(smallHeap.top());
            smallHeap.pop();
        }
    }

    double findMedian() {
        if (bigHeap.size() == 0) return 0.0;
        if (smallHeap.size() == bigHeap.size()) {
            return 1.0 * (smallHeap.top() + bigHeap.top()) / 2.0;
        }
        return bigHeap.top();
    }

    priority_queue<int> bigHeap;
    priority_queue<int, vector<int>, greater<int>> smallHeap;
};

int main() {}