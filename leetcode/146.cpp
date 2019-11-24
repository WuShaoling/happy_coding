#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

struct LRUNode{
    int value;
    int key;
    LRUNode(int k, int v){
        key = k;
        value = v;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        auto it = mm.find(key);
        // 如果存在，删除原节点，新节点放到链表头部
        if (it != mm.end()){
            // 在头部创建新节点
            LRUNode *newNode = new LRUNode(key, it->second->value);
            ll.push_front(newNode);
            // 移除旧节点
            ll.remove(it->second);
            // 更新map
            mm[key] = newNode;
            return newNode->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // 如果存在，直接删除
        auto it = mm.find(key);
        if(it != mm.end()){
            ll.remove(it->second);
        }

        // 如果满了，删除队尾的节点
        if(ll.size() >= _capacity){
            int key = ll.back()->key;
            ll.pop_back();
            mm.erase(key);
        }

        // 插入新的
        LRUNode *newNode = new LRUNode(key, value);
        ll.push_front(newNode);
        mm[key] = newNode;
    }

private:
    unordered_map<int, LRUNode*> mm;
    list<LRUNode*> ll;
    int _capacity;
};

int main(){
    LRUCache* obj = new LRUCache(2);
    cout << obj->get(10) << endl;
    obj->put(1,1);
    obj->put(2,2);
    cout << obj->get(1) << endl;
    obj->put(3,3);
    cout << "this" << endl;
    cout << obj->get(1) << endl;
    cout << obj->get(3) << endl;
    return 0;
}   

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */