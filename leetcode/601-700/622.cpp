#include <iostream>

using namespace std;

class MyCircularQueue {
   public:
    /** Initialize your data structure here. Set the size of the queue to be k.
     */
    MyCircularQueue(int k) {
        capacity = k;
        if (k > 0) arr = new int[k];
    }

    /** Insert an element into the circular queue. Return true if the operation
     * is successful. */
    bool enQueue(int value) {
        if (capacity <= 0 || isFull()) return false;

        arr[rear++] = value;
        rear %= capacity;
        count++;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation
     * is successful. */
    bool deQueue() {
        if (capacity <= 0 || isEmpty()) return false;

        front++;
        front %= capacity;
        count--;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (capacity == 0 || isEmpty()) return -1;
        return arr[front];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (capacity == 0 || isEmpty()) return -1;

        if (rear == 0) return arr[capacity - 1];
        return arr[rear - 1];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() { return count == 0; }

    /** Checks whether the circular queue is full or not. */
    bool isFull() { return count == capacity; }

   private:
    int capacity = 0;
    int front = 0;
    int rear = 0;
    int* arr = NULL;
    int count = 0;
};

// h       t
// 1 2 3 4 5

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main() {
    MyCircularQueue* obj = new MyCircularQueue(3);
    cout << obj->enQueue(1) << endl;
    cout << obj->enQueue(2) << endl;
    cout << obj->enQueue(3) << endl;
}