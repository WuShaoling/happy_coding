#include <iostream>

using namespace std;

class DiningPhilosophers {
   public:
    DiningPhilosophers() {}

    void wantsToEat(int philosopher, function<void()> pickLeftFork,
                    function<void()> pickRightFork, function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int left = philosopher;
        int right = (philosopher + 1) % 5;

        mu.lock();
        chopstick[left].lock();
        chopstick[right].lock();

        pickLeftFork();
        pickRightFork();

        mu.unlock();

        eat();

        putRightFork();
        putLeftFork();

        chopstick[right].unlock();
        chopstick[left].unlock();

        mu.unlock();
    }

   private:
    std::mutex chopstick[5];
    std::mutex mu;
};

int main() {}