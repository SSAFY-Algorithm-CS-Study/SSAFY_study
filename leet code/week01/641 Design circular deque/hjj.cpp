class MyCircularDeque {
private:
    vector<int> circular_deque;
    int front;
    int last;
    int max_size;
    int size;

public:
    MyCircularDeque(int k) {
        circular_deque.resize(k);
        front = 0;
        last = 0;
        max_size = k;
        size = 0;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        circular_deque[front] = value;
        front = (front + 1) % max_size;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        last = (last + max_size - 1) % max_size;
        circular_deque[last] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + max_size - 1) % max_size;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        last = (last + 1) % max_size;
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return circular_deque[(front - 1 + max_size) % max_size];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return circular_deque[last];
    }

    bool isEmpty() {
        if (size == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isFull() {
        if (size == max_size) {
            return true;
        }
        else {
            return false;
        }
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */