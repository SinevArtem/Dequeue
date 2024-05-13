// Example program
#include <iostream>
#define SIZE 6
using namespace std;
class Dequeue {

    int start = -1;
    int end = -1;
    int size = SIZE;
    int buffer[SIZE];

public:
    Dequeue() = default;
    bool IsEmpty() const {
        return (start == end && start == -1);
    }
    bool IsFull() const {
        return (end + 1) % size == start;
    }
    int front() const {
        if (IsEmpty()) exit(1);
        return buffer[start];
    }
    int back() const {
        if (IsEmpty()) exit(1);
        return buffer[end];
    }
    int get_size() const {
        if (IsEmpty()) return 0;
        return (start <= end) ? (end - start + 1) : size - (start - end - 1);
    }
    bool push_back(int element) {
        if (IsFull()) return false;
        if (IsEmpty()) start = end = 0;
        else end = (end + 1) % size;
        buffer[end] = element;
        return true;
    }
    bool push_front(int element) {
        if (IsFull()) return false;
        if (IsEmpty()) start = end = 0;
        else start = (start - 1 + size) % size;
        buffer[start] = element;
        return true;
    }
    bool pop_front() {
        if (IsEmpty()) return false;
        if (start == end && start != -1) start = end = -1;
        else start = (start + 1) % size;
        return true;
    }
    bool pop_back() {
        if (IsEmpty()) return false;
        if (start == end && start != -1) start = end = -1;
        else end = (end - 1 + size) % size;
        return true;
    }

    void print_front() const {
        int i = start;
        cout << "first->";
        while (i != end) {
            cout << buffer[i] << " ";
            i = (i + 1) % size;
        }cout << buffer[i] << "<-last" << endl;
    }

    void print_back() const {
        int i = end;
        cout << "last->";
        while (i != start) {
            cout << buffer[i] << " ";
            i = (i - 1 + size) % size;
        }cout << buffer[i] << "<-first" << endl;
    }
};

int main()
{
    Dequeue q1;
    q1.push_front(1);
    q1.push_back(2);
    q1.push_front(3);
    q1.push_front(4);
    q1.print_back(); // 2 1 3 4
    q1.push_back(5);
    q1.pop_front();
    q1.print_front(); // 3 1 2 5
    return 0;
}

