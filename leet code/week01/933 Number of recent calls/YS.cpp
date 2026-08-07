/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : Park Yeonseo                            SSSSS   WW   WW  */
/* Algorithm         : Queue                                   SS      WW   WW  */
/* Time Complexity   : O(1) (amortized)                        SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
class RecentCounter {
public:
    vector<int> v;
    int head = 0;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        v.push_back(t); //큐에 넣음
        if(!v.empty()){
            while(v[head]<t-3000&&head<v.size()){
                head++; // 범위에 안맞으면 큐 길이 줄임
            }
        }
        return v.size()-head; //큐 범위의 길이 반환

    }
};