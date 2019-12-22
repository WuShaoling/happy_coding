#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class RandomizedSet {
   public:
    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already
     * contain the specified element. */
    bool insert(int val) {
        if (m.find(val) == m.end()) {
            v.push_back(val);
            m[val] = v.size() - 1;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the
     * specified element. */
    bool remove(int val) {
        map<int, int>::iterator it = m.find(val);
        if (it != m.end()) {
            v[it->second] = v[v.size() - 1];
            v.pop_back();
            m.erase(val);
        }
    }

    /** Get a random element from the set. */
    int getRandom() {
        int random = rand() % v.size();
        return m[random];
    }

    vector<int> v;
    map<int, int> m;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {}