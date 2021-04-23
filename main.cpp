
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

int arrayContainsWithIndex(int test[][2], int b, int length) {
    int whereIs;
    for (int i = 0; i < length; i++) {
        if (test[i][0] == b) {
            whereIs = i;
        }
    }
    return whereIs;
}

int tempFunc(int n) {
    return n * 2;
}

template<typename T, size_t size>
void print(const T (&array)[size]) {
    for (size_t i = 0; i < size; ++i)
        std::cout << array[i] << " ";
}

int intArraySum(int array[], int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        sum += array[i];
    }

    return sum;
}

int main() {

    int tempArray[5];

    for (int n = 0; n < 5; n++) {
        tempArray[n] = tempFunc(n);
    }

    int length = sizeof(tempArray) / sizeof(tempArray[0]);

    print(tempArray);
    cout << endl << intArraySum(tempArray, length);

    return 0;
}