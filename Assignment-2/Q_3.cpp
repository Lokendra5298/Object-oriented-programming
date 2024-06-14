#include <iostream>
#include <queue>
using namespace std; // Add this line

class Queue {
private:
    queue<int> dataQueue; 
public:
    // Constructor
    Queue() {}

    // Function to put a data item on the queue
    void put(int item) {
        dataQueue.push(item);
    }

    // Function to get data from the queue
    int get() {
        if (!dataQueue.empty()) {
            int frontItem = dataQueue.front();
            dataQueue.pop();
            return frontItem;
        } else {
            cerr << "Queue is empty. Unable to get data." << endl;
            return -1; // Special value indicating an error or empty queue.
        }
    }
};

int main() {
    Queue myQueue;

    myQueue.put(10);
    myQueue.put(20);
    myQueue.put(30);
    myQueue.put(40);
    cout << "Getting data from the queue: " << myQueue.get() << endl;
    cout << "Getting data from the queue: " << myQueue.get() << endl;
    cout << "Getting data from the queue: " << myQueue.get() << endl;
    cout << "Getting data from the queue: " << myQueue.get() << endl;

    return 0;
}
