/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : ssafy                                   SSSSS   WW   WW  */
/* Algorithm         : 비트마스킹                              SS      WW   WW  */
/* Time Complexity   : O(N * 2^N)                              SSSSS   WW W WW  */
/* Space Complexity  : O(N * 2^N)                                 SS   WWW WWW  */
/* Note              : 재귀로도 풀 수 있을 듯?                 SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> answer;

        //2^n개의 부분집합 검사
        //nums엔 n개의 수가 있음. 각 수 하나마다 존재/존재x -> 2개의 경우가 존재. 부분집합은 총 2^n개
        for(int i = 0; i < (1 << n); i++){
            vector<int> temp;

            //각 자리(n개)에 대해 0인지 1인지 검사.
            for(int j = 0; j < n; j++){
                if(i & (1 << j)) // i 와 j 비교. 1이 있으면 temp에 추가
                    temp.push_back(nums[j]);
            }

            answer.push_back(temp);
        }

        return answer;
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums1 = {1, 2, 3}, nums2 = {0};

    vector<vector<int>> results = sol.subsets(nums1), results2 = sol.subsets(nums2);

    for(int i = 0; i < results.size(); i++){
        for(int j = 0; j < results[i].size(); j++){
            cout << results[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << '\n';

    for(int i = 0; i < results2.size(); i++){
        for(int j = 0; j < results2[i].size(); j++){
            cout << results2[i][j] << ' ';
        }
        cout << '\n';
    }
}