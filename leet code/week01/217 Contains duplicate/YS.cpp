/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : Park Yeonseo                            SSSSS   WW   WW  */
/* Algorithm         : Set                                     SS      WW   WW  */
/* Time Complexity   : O(N log N)                              SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> st;
        for(int i = 0;i<nums.size();i++){
            if(st.count(nums[i]))return true; // 이미 st에 존재하면 겹치는 거니까 true
            st.insert(nums[i]); // st에 없으면 삽입
        }
        return false; // 끝까지 돌았는데 겹치는게 없으면 false
    }
};