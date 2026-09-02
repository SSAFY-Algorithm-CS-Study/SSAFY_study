/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : ssafy                                   SSSSS   WW   WW  */
/* Algorithm         : DP                                      SS      WW   WW  */
/* Time Complexity   : O(N)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              : leet code - 198 House Robber            SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); // 각 집의 소지액 벡터 nums의 크기
        if (n == 1) // 집이 하나면 한 집을 터는 것이 최대 금액이므로
        {
            return nums[0]; // 유일한 값 리턴
        }

        vector<int> dp(n); // 인접한 두 집을 침입하지 못하면서 최대 금액을 구할 벡터 dp 
        dp[0] = nums[0]; // 첫 번째 집만 고려할 경우 첫 번째 집의 금액이 최대 금액
        dp[1] = max(nums[0], nums[1]); // 두번째 집까지 고려한다면 인접한 곳은 못 고르므로  
                                       // 첫번째와 두번째 집 중 가장 큰 금액을 값으로 함
        for (int i = 2; i < nums.size(); i++) // dp[0]과 dp[1]을 정했으므로 
        {                                     // 2부터 마지막 집까지 반복문 실행
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]); // 그랬을 때 i번째 집을 기준으로 인접하지 않으려면
        }                                                // i-1번째 vs i-2번째 + i번째 를 비교해서 
                                                         // 더 큰 값을 가지도록 함.
        return dp[n - 1]; // 그랬을 때 최대 금액은 마지막 집까지 고려한 n-1 이므로 dp[n-1] 리턴
    }
};