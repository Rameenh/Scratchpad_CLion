
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

int main() {

    queue<int> FIFOqueue;
    int queueSize = 0;
    FIFOqueue.push(2);
    FIFOqueue.push(3);
    FIFOqueue.pop();
    FIFOqueue.push(2);
    FIFOqueue.push(1);
    print_queue(FIFOqueue);
    FIFOqueue.pop();
    FIFOqueue.push(5);
    print_queue(FIFOqueue);
    FIFOqueue.pop();
    FIFOqueue.push(2);
    FIFOqueue.pop();
    FIFOqueue.push(4);
    print_queue(FIFOqueue);
    FIFOqueue.pop();
    FIFOqueue.push(5);
    FIFOqueue.pop();
    FIFOqueue.push(3);
    print_queue(FIFOqueue);
    FIFOqueue.pop();
    FIFOqueue.push(2);
    print_queue(FIFOqueue);
    FIFOqueue.pop();
    FIFOqueue.push(5);
    return 0;
}