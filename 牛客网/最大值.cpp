#include <iostream>
#include<limits.h>

using namespace std;

int main() {



    //max_fir > max_sec > max_thd, min_fir < min_sec
    int max_fir, max_sec, max_thd, min_fir, min_sec, n, t;
    max_fir = max_sec = max_thd = INT_MAX;
    min_fir = min_sec =
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t > max_fir) {

        }
    }


    // a>=b>=c
    int a, b, c, t, min1, min2, size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        cin >> t;
        if (i == 0) {
            a = t;
        } else if (i == 1) {
            b = t;
            if (a < b) {
                b = a;
                a = t;
            }
        } else if (i == 2) {
            c = t;
            if (a < t) {
                c = b;
                b = a;
                a = t;
            } else if (b < t) {
                c = b;
                b = t;
            }
        } else {
            if (t > a) {
                c = b;
                b = a;
                a = t;
            } else if (t > b) {
                c = b;
                b = t;
            } else if (t > c) {
                c = t;
            }
        }
    }
    cout << a * b * c;

}