/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : O(1)로 동작하게끔 구현                  SS      WW   WW  */
/* Time Complexity   : O(1)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(k)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class MyCircularDeque {
private:
    vector<int> v;
    int capacity, front, rear, cnt;

public:
    MyCircularDeque(int k) { 
        capacity = k;
        v.resize(k);
        front = 0;
        rear = k - 1;
        cnt = 0;
    }
    
    bool insertFront(int value) {
        if(isFull())
            return false;

        front = (front - 1 + capacity) % capacity;
        v[front] = value;
        cnt++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())
            return false;

        rear = (rear + 1) % capacity;
        v[rear] = value;
        cnt++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())
            return false;
        
        front = (front + 1) % capacity;
        cnt--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())
            return false;
        
        rear = (rear - 1 + capacity) % capacity;
        cnt--;
        return true;
    }
    
    int getFront() {
        if(isEmpty())
            return -1;
        return v[front];
    }
    
    int getRear() {
        if(isEmpty())
            return -1;
        return v[rear];
    }
    
    bool isEmpty() {
        if(cnt == 0)
            return true;
        return false;
    }
    
    bool isFull() {
        if(cnt == capacity)
            return true;
        else
            return false;
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

 /*
int main(void)
{
    MyCircularDeque q(3);

    cout << boolalpha;

    cout << "insertLast(1)  : "
         << q.insertLast(1) << '\n';

    cout << "insertLast(2)  : "
         << q.insertLast(2) << '\n';

    cout << "insertFront(3) : "
         << q.insertFront(3) << '\n';

    cout << "insertFront(4) : "
         << q.insertFront(4) << '\n';

    cout << "getRear()      : "
         << q.getRear() << '\n';

    cout << "isFull()       : "
         << q.isFull() << '\n';

    cout << "deleteLast()   : "
         << q.deleteLast() << '\n';

    cout << "insertFront(4) : "
         << q.insertFront(4) << '\n';

    cout << "getFront()     : "
         << q.getFront() << '\n';

}*/