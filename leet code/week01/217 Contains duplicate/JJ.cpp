/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 자료구조 : 셋                           SS      WW   WW  */
/* Time Complexity   : O(N)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //중복된 수가 있는지만 확인하면 됨. 셋을 이용하여 중복제거
        //중복제거가 됐으면 셋의 크기와 nums의 크기는 다를 것
        unordered_set<int> S;
        for(auto n : nums)
            S.insert(n);

        if(nums.size() != S.size())
            return true;
        else
            return false;
    }
};

/*
int main(void)
{
    Solution sol;

    vector<int> nums1 = {1,2,3,1}, nums2 = {1,2,3,4}, nums3 = {1,1,1,3,3,4,3,2,4,2};
    cout << sol.containsDuplicate(nums1) << sol.containsDuplicate(nums2) << sol.containsDuplicate(nums3);
}*/