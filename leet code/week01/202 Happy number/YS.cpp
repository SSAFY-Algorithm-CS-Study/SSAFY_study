/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : Park Yeonseo                            SSSSS   WW   WW  */
/* Algorithm         : Set                                     SS      WW   WW  */
/* Time Complexity   : O(log N)                                SSSSS   WW W WW  */
/* Space Complexity  : O(log N)                                   SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
class Solution {
public:
    bool isHappy(int n) {
        set<int> st; 
        while(true){
            int s = 0;
            if(st.count(n)) return false; // 이미 st에 존재하면 반복이라서 false
            st.insert(n); // st에 없으면 삽입
            while(n>0){ // s = n의 각 자리수의 제곱의 합
                s += (n%10) * (n%10);
                n /= 10;
            }
            if(s == 1){ // 각 자리수의 제곱의 합이 1이되면 true 반환
                return true;
            }
            n = s; // n값 갱신
        }
    }
};
