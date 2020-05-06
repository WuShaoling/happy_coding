#include <iostream>

using namespace std;

class TripleInOne {
   public:
    TripleInOne(int stackSize) {
        this->capcity = stackSize;
        stack = new int[stackSize * 3];
    }

    void push(int stackNum, int value) {
        int len = this->stack_size[stackNum];
        if (len == this->capcity) return;
        this->stack[this->capcity * stackNum + len] = value;
        this->stack_size[stackNum]++;
    }

    int pop(int stackNum) {
        int len = this->stack_size[stackNum];
        if (len == 0) return -1;
        int res = this->stack[this->capcity * stackNum + len - 1];
        this->stack_size[stackNum]--;
        return res;
    }

    int peek(int stackNum) {
        int len = this->stack_size[stackNum];
        if (len == 0) return -1;
        return this->stack[this->capcity * stackNum + len - 1];
    }

    bool isEmpty(int stackNum) { return this->stack_size[stackNum] == 0; }

   private:
    int capcity = 0;
    int* stack;
    int stack_size[3] = {0};
};

int main() {
    TripleInOne t(1);
    t.push(0, 1);
    t.push(0, 2);
}