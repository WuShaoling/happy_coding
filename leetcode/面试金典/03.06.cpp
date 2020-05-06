#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class AnimalShelf {
   public:
    AnimalShelf() {}

    void enqueue(vector<int> animal) {
        animal[2] = num++;
        if (animal[1] == 1) {  // dog
            dog.push(animal);
        } else {
            cat.push(animal);
        }
    }

    vector<int> dequeueAny() {
        vector<int> res = {-1, -1};
        if (dog.empty() && cat.empty()) return res;

        if (dog.empty()) {
            res = cat.front();
            cat.pop();
        } else if (cat.empty()) {
            res = dog.front();
            dog.pop();
        } else if (dog.front()[2] < cat.front()[2]) {
            res = dog.front();
            dog.empty();
        } else {
            res = cat.front();
            cat.empty();
        }

        res.pop_back();
        return res;
    }

    vector<int> dequeueDog() {
        vector<int> res = {-1, -1};
        if (!dog.empty()) {
            res = dog.front();
            dog.pop();
            res.pop_back();
        }
        return res;
    }

    vector<int> dequeueCat() {
        vector<int> res = {-1, -1};
        if (!cat.empty()) {
            res = cat.front();
            cat.pop();
            res.pop_back();
        }
        return res;
    }

   private:
    queue<vector<int>> dog;
    queue<vector<int>> cat;
    int num = 0;
};

// class AnimalShelf {
//    public:
//     AnimalShelf() {}

//     void enqueue(vector<int> animal) { L.push_back(animal); }

//     vector<int> dequeueAny() {
//         vector<int> res = {-1, -1};
//         if (L.empty()) return res;
//         res = L.front();
//         L.pop_front();
//         return res;
//     }

//     vector<int> dequeueDog() {
//         vector<int> res = {-1, -1};
//         for (list<vector<int>>::iterator it = L.begin(); it != L.end(); it++)
//         {
//             if ((*it)[1] == 1) {
//                 res = *it;
//                 L.erase(it);
//                 break;
//             }
//         }
//         return res;
//     }

//     vector<int> dequeueCat() {
//         vector<int> res = {-1, -1};
//         for (list<vector<int>>::iterator it = L.begin(); it != L.end(); it++)
//         {
//             if ((*it)[1] == 0) {
//                 res = *it;
//                 L.erase(it);
//                 break;
//             }
//         }
//         return res;
//     }

//    private:
//     list<vector<int>> L;
// };

int main() {}