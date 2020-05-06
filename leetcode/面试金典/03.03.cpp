#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class StackOfPlates {
   public:
    StackOfPlates(int cap) { this->cap = cap; }

    void push(int val) {
        if (cap == 0) return;

        if (s.size() == 0 || s[s.size() - 1].size() == cap) {
            stack<int> t;
            s.push_back(t);
        }

        s[s.size() - 1].push(val);
    }

    int pop() {
        if (s.size() == 0) return -1;

        int res = s[s.size() - 1].top();
        s[s.size() - 1].pop();

        if (s[s.size() - 1].empty()) s.pop_back();
        return res;
    }

    int popAt(int index) {
        if (index < 0 || index >= s.size() || s.size() == 0 || s[index].empty())
            return -1;

        int res = s[index].top();
        s[index].pop();

        if (s[index].empty()) s.erase(s.begin() + index);

        return res;
    }

   private:
    int cap;
    vector<stack<int>> s;
};

int main() {}