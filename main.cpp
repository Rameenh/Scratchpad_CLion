
#include <iostream>
#include <queue>

using namespace std;

bool queueContains(queue<int> a, int b) {
    for (int i = a.size(); i > 0; i--) {
        if (a.front() == b) {
            return true;
        }
        a.pop();
    }
    return false;
}

void print_queue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    cout << endl;
}

bool arrayContains(int test[][2], int b, int length) {
    for (int i = 0; i < length; i++) {
        if (test[i][0] == b) return true;
    }
    return false;
}

int main() {

    int n = 3;
    int test[n][2];
    int length = sizeof(test) / sizeof(test[0]);
    test[0][0] = 2;
    test[0][1] = 1;
    test[1][0] = 6;
    test[0][1] = 1;
    test[2][0] = 4;
    test[0][1] = 1;

    cout << arrayContains(test, 2, length) << endl; //should return 1
    cout << arrayContains(test, 6, length) << endl; //should return 1
    cout << arrayContains(test, 4, length) << endl; //should return 1
    cout << arrayContains(test, 1, length) << endl; //should return 0
    cout << arrayContains(test, 10, length) << endl; //should return 0
    cout << arrayContains(test, 8, length) << endl; //should return 0
    cout << arrayContains(test, 14, length); //should return 0
    return 0;
}