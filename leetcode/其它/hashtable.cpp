#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct ListNode {
    int key;
    int value;
    ListNode* next;
    ListNode* pre;
    ListNode() { next = pre = NULL; }
};

struct List {
    ListNode* head;
    ListNode* tail;
    List() { head = tail = NULL; }
};

class HashTable {
   public:
    HashTable() { hash_table = vector<list<pair<int, int>>>(capacity); }

    int remove(int k) {
        if (count == 0) return -1;

        int index = k % capacity;

        for (auto it : hash_table[index]) {
            if (it.first == k) {
                hash_table[index].remove(it);
            }
        }

        return -1;
    }

    int get(int k) {
        if (count == 0) return -1;

        int index = k % capacity;

        for (auto it : hash_table[index]) {
            if (it.first == k) {
                return it.second;
            }
        }

        return -1;
    }

    void put(int k, int v) {
        // 求索引
        int index = k % capacity;

        // 检查是否存在
        for (auto it : hash_table[index]) {
            if (it.first == k) {
                it.second = v;
                return;
            }
        }

        // 如果满了，扩容
        if (count == capacity) {
            // TODO resize
        }

        // 头插法
        hash_table[index].push_front({k, v});
    }

   private:
    int capacity = 15;
    int count = 0;
    vector<list<pair<int, int>>> hash_table;
};

int main() {}