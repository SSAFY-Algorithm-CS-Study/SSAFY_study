/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 덱                                      SS      WW   WW  */
/* Time Complexity   : O(1)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              : 641 Design circular deque               SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <deque>
using namespace std;

class MyCircularDeque { 
private:
    deque<int> d; // 사용할 deque, 앞에서 또는 뒤에서 추가/삭제해야하므로 덱
    int size; // 덱의 최대 크기
public:
    MyCircularDeque(int k)
        : size(k) {} // 생성자, 덱의 최대 크기 k로 초기화

    bool insertFront(int value) {
        if (isFull()) // 덱이 가득 찼으면 
        {
            return false; // false 반환
        }
        d.push_front(value); // 덱의 앞에 value 추가
        return true; // true 반환
    }

    bool insertLast(int value) {
        if (isFull()) // 덱이 가득 찼으면
        {
            return false; // false 반환
        }
        d.push_back(value); // 덱의 뒤에 value 추가
        return true; // true 반환
    }

    bool deleteFront() {
        if (isEmpty()) // 덱이 비어있으면
        {
            return false; // false 반환
        }
        d.pop_front(); // 덱의 첫 번째 원소 삭제
        return true; // true 반환
    }

    bool deleteLast() {
        if (isEmpty()) //  덱이 비어있으면
        {
            return false; // false 반환
        }
        d.pop_back(); // 덱의 마지막 원소 삭제
        return true; // true 반환
    }

    int getFront() {
        if (isEmpty()) // 덱이 비어있으면
        {
            return -1; // -1 반환
        }
        return d.front(); // 덱의 첫 번째 원소 반환
    }

    int getRear() {
        if (isEmpty()) // 덱이 비어있으면
        {
            return -1; // -1 반환
        }
        return d.back(); // 덱의 마지막 원소 반환
    }

    bool isEmpty() {
        if (d.empty()) // 덱이 비어있으면 
        {
            return true; // true 반환
        }
        return false; // false 반환
    }

    bool isFull() {
        if (d.size() == size) // 덱의 크기가 최대 크기와 같으면
        {
            return true; // true 반환
        }
        return false; // false 반환
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