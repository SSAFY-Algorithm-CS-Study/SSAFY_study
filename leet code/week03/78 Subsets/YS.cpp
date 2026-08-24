/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 비트마스킹                              SS      WW   WW  */
/* Time Complexity   : O(n × 2ⁿ)                               SSSSS   WW W WW  */
/* Space Complexity  : O(n × 2ⁿ)                                  SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
class Solution {
public:
    vector<int> subset; // 현재 부분집합
    vector<vector<int>> result; // 모든 부분집합
    void dfs(int start, vector<int>& nums){
        result.push_back(subset); // 현재 상태를 부분집합으로 저장
        for(int i = start;i<nums.size();i++){ // 한번 사용한건 다시 안쓰기 위해 start부터 반복
            subset.push_back(nums[i]); // 현재 원소 선택
            dfs(i+1, nums); // 그 다음 인덱스 탐색
            subset.pop_back(); // 사용한건 pop
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums); // 0번 인덱스부터 탐색
        return result;
    }
}; 