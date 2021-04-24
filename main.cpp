
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

void print2DArray(int array[][2], int wss) {
    cout << endl;
    cout << endl;
    for (int i = 0; i < wss; i++) {
        cout << array[i][0] << " ";
    }
    cout << endl;
    for (int i = 0; i < wss; i++) {
        cout << array[i][1] << " ";
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

int Clock(int wss, int pageNumbers[]) { //we will have to create our own "queue" for this one
    int workingSetArray[3][2] = {}; //second part of two-dimensional array will be the use bit
    int counter = 0; //to keep track of when we hit out wss limit
    int pointer = 0; //initialized to the first position in our queue
    int pageReferenced; //initialize a variable to store the index of a referenced page number
    int pageFaultCount = 0; //initialize the counter for page faults to zero
    for (int i = 0; i < 12; i++) {
        cout << "index i: " << i << ", workingSetArray...";
        print2DArray(workingSetArray, wss);
        cout << "checking to see if page number " << pageNumbers[i] << " is in working set, "
             << (arrayContains(workingSetArray, pageNumbers[i], wss)) << endl;
        if (!arrayContains(workingSetArray, pageNumbers[i],
                           wss)) { //if our working set does not contain this incoming page number
            cout << "checking to see if counter is less than working set size limit, " << (counter < wss) << endl;
            if (counter <
                wss) { //as long as there is an empty slot in the working set, no need to do any page replacement, just tack it on the end
                cout << "counter is less than limit therefore add page number directly to working set. Pointer = "
                     << pointer << endl;
                workingSetArray[pointer][0] = pageNumbers[i];
                workingSetArray[pointer][1] = 1; //the zero indicates that the page is given its first chance
                pointer++; //we have to manually keep track of where we are in the working set page queue, move it up one; we don't need to check to see
                // if the pointer will exceed the working set size because our condition to get into this coding section already prevents that
                counter++; //we just added an element to our working set; moves in lockstep with the pointer variable in this section of code
                print2DArray(workingSetArray, wss);
                cout << "pointer and counter incremented.\n";
            } else { //this means that our working set has reached max capacity and we must start swapping out pages
                cout << "working set is at max limit, page replacement starting. Pointer = " << pointer << endl;
                while (workingSetArray[pointer][1] !=
                       0) { //keep doing this loop until we encounter a page that is replaceable
                    cout << "have not yet found a replacement page, this page is set to 1 right now... ";
                    workingSetArray[pointer][1] = 0;//set the current position to replaceable
                    cout << "setting to 0. ";
                    if (pointer == wss - 1) { //if the pointer is pointing to the last slot in the working set
                        pointer = 0; //set the pointer to point to slot zero
                        cout << "we are at the end of the set, setting pointer to 0..." << endl;
                    } else { //otherwise
                        pointer++; //we have to manually keep track of where we are in the working set page queue, move it up one
                        cout << "pointer incremented to: " << pointer << endl;
                    }
                }
                //at this point in the code, the pointer MUST be pointing to a page index where is it replaceable, it
                // may have not ran at all, in which case the program simply started in a replaceable page
                cout
                        << "page number we landed on now should have 0 be its flag without the need to change it, pointer is at position: "
                        << pointer << " change page number, flag, incremented pointer and fault count...\n";
                workingSetArray[pointer][0] = pageNumbers[i]; //the page has now been replaced
                workingSetArray[pointer][1] = 1; //set it to newly place so it's not chosen for replacement
                pageFaultCount++; //increment the page fault counter
                print2DArray(workingSetArray, wss);
                pointer++;
            }
        } else //if the working set does include this incoming page number already, pointer nor counter increment
        {
            pageReferenced = arrayContainsWithIndex(workingSetArray, pageNumbers[i],
                                                    wss); //locate the specific position of where that page is located in the working set
            cout << "the page already exists! at position " << pageReferenced << " setting flag to 1\n";
            workingSetArray[pageReferenced][1] = 1; //a rule of the clock algorithm is that if a page is referenced in the working set, even if the use bit is 0, set it back to 1
            print2DArray(workingSetArray, wss);
        }

        if (pointer == wss) {
            pointer = 0;
            cout << "manual line 256 pointer was beyond last position, to moved it to pos 0\n";
        }
        cout
                << "-----------------------------------------------------------------------------------------------------------\n";
    }
    return pageFaultCount;
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

    Clock(wss, pageAddr);


    return 0;
}