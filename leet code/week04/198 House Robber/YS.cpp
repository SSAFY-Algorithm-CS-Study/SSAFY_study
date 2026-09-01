/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : DP                                      SS      WW   WW  */
/* Time Complexity   : O(N)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp (nums.size()); // i번째까지 봤을때 최대값
        dp[0] = nums[0]; // 0번째 초기화
        if(nums.size()>1)dp[1] = max(dp[0], nums[1]); // nums가 2개 이상있으면 2번 초기화
        for(int i=2;i<nums.size();i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]); // 현재 집을 안털때, 집을 털때 중 큰 값
        }

        return dp.back();
    }
};

