
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <cstdlib>
#include <vector>

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

int queueContainsIndex(queue<int> a, int b) {
    for (int i = a.size(); i > 0; i--) {
        if (a.front() == b) {
            return i;
        }
        a.pop();
    }
    return -1;
}

bool stackContains(stack<int> a, int b) {
    for (int i = a.size(); i > 0; i--) {
        if (a.top() == b) {
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
}

void print_stack(stack<int> q) {
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}

bool arrayContains(int test[][2], int b, int length) {
    for (int i = 0; i < length; i++) {
        if (test[i][0] == b) return true;
    }
    return false;
}

int arrayContainsWithIndex(int test[][2], int b, int length) {
    int whereIs;
    for (int i = 0; i < length; i++) {
        if (test[i][0] == b) {
            whereIs = i;
        }
    }
    return whereIs;
}

template<typename T, size_t size>
void print(const T (&array)[size]) {
    for (size_t i = 0; i < size; ++i)
        cout << array[i] << " ";
    cout << endl;
}

int FIFO(int wss, int pageNumbers[]) {
    queue<int> FIFOqueue;
    int counter = 0;
    int pageFaultCounter = 0;

    for (int i = 0; i < 12; i++) {
        cout << "loop index: " << i << endl;
        cout << "checking if queue [";
        print_queue(FIFOqueue);
        cout << "] contains: " << pageNumbers[i] << ", " << queueContains(FIFOqueue, pageNumbers[i]) << endl;

        if (!queueContains(FIFOqueue, pageNumbers[i])) {
            cout << "counter is at: " << counter << " wss = " << wss << endl;

            if (counter < wss) { //if the queue is not at max capacity
                cout << "therefore, queue is not at max capacity and must push " << pageNumbers[i]
                     << " and increase counter from " << counter;
                FIFOqueue.push(pageNumbers[i]);
                counter++; //this will keep track to see if the queue is at max capacity
                cout << " to " << counter << endl;
            } else { //if the queue is at max capacity
                cout << " therefore, queue is at max capacity so we will push in " << pageNumbers[i] << " after popping"
                     << endl;
                FIFOqueue.pop(); //pop that last added page (the queue class is automatically FIFO with pop()
                FIFOqueue.push(pageNumbers[i]); //push the new pageNumber in now that we have the oldest page removed
                pageFaultCounter++;
                cout << "page fault counter incremented, now at: " << pageFaultCounter << endl;
            }
        }
        cout << "new queue: [";
        print_queue(FIFOqueue);
        cout << "]\n";
        cout
                << "--------------------------------------------------------------------------------------------------------------------------\n";
    }
    return pageFaultCounter;
}

int LRU(int wss, int pageNumbers[]) {
    queue<int> LRUqueue;
    int counter = 0;
    int pageFaultCounter = 0;

    for (int i = 0; i < 12; i++) {
        cout << "loop index: " << i << endl;
        cout << "checking if queue [";
        print_queue(LRUqueue);
        cout << "] contains: " << pageNumbers[i] << ", " << queueContains(LRUqueue, pageNumbers[i]) << endl;

        if (!queueContains(LRUqueue, pageNumbers[i])) {
            cout << "counter is at: " << counter << " wss = " << wss << endl;

            if (counter < wss) { //if the queue is not at max capacity
                cout << "therefore, queue is not at max capacity and must push " << pageNumbers[i]
                     << " and increase counter from " << counter;
                LRUqueue.push(pageNumbers[i]);
                counter++; //this will keep track to see if the queue is at max capacity
                cout << " to " << counter << endl;
            } else { //if the queue is at max capacity
                cout << " therefore, queue is at max capacity so we will push in " << pageNumbers[i] << " after popping"
                     << endl;
                LRUqueue.pop(); //pop that last added page (the queue class is automatically FIFO with pop()
                LRUqueue.push(pageNumbers[i]); //push the new pageNumber in now that we have the oldest page removed
                pageFaultCounter++;
                cout << "page fault counter incremented, now at: " << pageFaultCounter << endl;
            }
        } else {
            cout << "since queue contains the page number, rejuvenating\n";
            int pageNumIndex = LRUqueue.size() - queueContainsIndex(LRUqueue, pageNumbers[i]);
            vector<int> queueTempFH;
            vector<int> queueTempSH;

            for (int i = 0; i < pageNumIndex; i++) {
                queueTempFH.push_back(LRUqueue.front());
                LRUqueue.pop();
            }
            LRUqueue.pop(); //this is the page number we're moving to the front

            int sizeForSH = LRUqueue.size();

            for (int i = 0; i < sizeForSH; i++) {
                queueTempSH.push_back(LRUqueue.front());
                LRUqueue.pop();
            }

            for (int i = 0; i < queueTempFH.size(); i++) {
                LRUqueue.push(queueTempFH.at(i));
            }

            for (int i = 0; i < queueTempSH.size(); i++) {
                LRUqueue.push(queueTempSH.at(i));
            }

            LRUqueue.push(pageNumbers[i]);
        }
        cout << "new queue: [";
        print_queue(LRUqueue);
        cout << "]\n";
        cout
                << "--------------------------------------------------------------------------------------------------------------------------\n";
    }
    return pageFaultCounter;
}


int intArraySum(int array[], int length) {
    int sum = 0;

    for (int i = 2; i < length; i++) {
        sum += array[i];
    }

    return sum;
}

void printVector(std::vector<int> const &a) {
    for (int i = 0; i < a.size(); i++)
        std::cout << a.at(i) << ' ';
}

int main() {
    bool t = true;
    bool f = false;
    cout << boolalpha << endl;

    int pageAddr[] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    int wss = 3;

    LRU(wss, pageAddr);


    return 0;
}