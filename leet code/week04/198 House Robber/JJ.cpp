/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : ssafy                                   SSSSS   WW   WW  */
/* Algorithm         : DP                                      SS      WW   WW  */
/* Time Complexity   : O(N)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

    /* 
        dp[i] : 0에서 시작해 i까지의 훔칠 수 있는 최대 금액을 뜻함
        i번째 집에서는 두 가지 선택 가능                              (전전집 기준 훔친 돈 최댓값)
            1. 훔친다 -> dp[i] = dp[i-2] + nums[i] (바로 이전에선 못훔침. 전전집 dp에 현재 돈을 더하면 됨)
            2. 안훔친다 -> dp[i] = dp[i-1];

            dp[i] = max(dp[i-1] , dp[i-2] + nums[i])
    */

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        //털 집이 하나밖에 없을 땐 첫 집만 털기 (없으면 nums[i-1]에서 에러 발생)
        if(n == 1)
            return nums[0]; 

        vector<int>dp(n+1, 0);

        dp[0] = 0; //집을 하나도 털지 않았을 땐 0원임

        if(n >= 1)
            dp[1] = nums[0]; //nums[0] (첫 번째 집 기준 무조건 터는 것이 최대의 돈을 가질 수 있음)

        for(int i = 2; i <= n; i++) //두 번째 집부터는 비교 시작
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]); //i번째 집 훔치지 않음 / 훔침 비교 후 최댓값 갱신
        
        return dp[n];
    }
};

/*
int main(void)
{
    Solution sol;

    vector<int> nums1 = {1,2,3,1}, nums2 = {2,7,9,3,1};

    cout << sol.rob(nums1) << ' ' << sol.rob(nums2);
}*/