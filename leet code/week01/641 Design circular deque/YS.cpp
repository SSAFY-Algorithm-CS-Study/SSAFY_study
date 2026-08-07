/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : Park Yeonseo                            SSSSS   WW   WW  */
/* Algorithm         : Deque                                   SS      WW   WW  */
/* Time Complexity   : O(1)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(K)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
class MyCircularDeque {
public:
    deque<int> dq;
    int maxSize;
    MyCircularDeque(int k) {
        maxSize = k;
    }
    
    bool insertFront(int value) {
        if(dq.size()<maxSize){
            dq.push_front(value); // dq크기가 maxSize보다 작으면 dq의 앞에 삽입
            return true;
        }
        return false; //dq크기가 maxSize보다 크면 false반환
    }
    
    bool insertLast(int value) {
        if(dq.size()<maxSize){
            dq.push_back(value); // dq크기가 maxSize보다 작으면 dq의 뒤에 삽입
            return true;
        }
        return false; //dq크기가 maxSize보다 크면 false반환
    } 
    
    bool deleteFront() {
        if(!dq.empty()){
            dq.pop_front(); // dq가 비어있지 않으면 앞에 있는 원소 pop
            return true;
        }
        return false; // dq가 비어있으면 false반환
    }
    
    bool deleteLast() {
        if(!dq.empty()){ // dq가 비어있지 않으면 뒤에 있는 원소 pop
            dq.pop_back();
            return true;
        }
        return false; // dq가 비어있으면 false반환
    }
    
    int getFront() {
        if(!dq.empty()){ // dq가 비어있지 않으면 앞에 있는 원소 반환
            return dq.front();
        }
        return -1; // dq가 비어있으면 -1반환
    }
    
    int getRear() {
        if(!dq.empty()){ // dq가 비어있지 않으면 뒤에 있는 원소 반환
            return dq.back();
        }
        return -1; // dq가 비어있으면 -1반환
    }
    
    bool isEmpty() {
        if(dq.empty())return true; // dq가 비어있으면 true 반환
        return false; // dq가 비어있지 않으면 false 반환 
    }
    
    bool isFull() {
        if(dq.size() == maxSize)return true; // dq가 maxSize만큼 찼으면 true 반환
        return false; // dq가 다 차있지 않으면 false 반환 
    }
};
