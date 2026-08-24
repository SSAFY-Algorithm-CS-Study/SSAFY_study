/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 이분탐색                                SS      WW   WW  */
/* Time Complexity   : O(log N)                                SSSSS   WW W WW  */
/* Space Complexity  : O(1)                                       SS   WWW WWW  */
/* Note              : leetcode - 34 Find First and Last Po…   SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer; // 정답 벡터

        int left = 0; // 왼쪽 인덱스
        int right = nums.size() - 1; // 오른쪽 인덱스
        int first = -1; // 최종적으로 넣고자 하는 인덱스(왼쪽을 구하므로 가장 왼쪽)
        while (left <= right) // 이 조건을 만족할 때 까지 반복문 실행(원하는 값의 가장 왼쪽 인덱스 구하기)
        {
            int mid = left + (right - left) / 2; // 중앙값을 좌우 합의 반으로 생각(값이 너무 커져서 
                                                 // left + right값이 정수 최대 값을 넘어갈 수 있어서 이렇게 표현)
            if (nums[mid] == target) // 인덱스가 중앙인 값이 원하는 값과 같다면
            {
                first = mid; // 인덱스값으로 중앙값을 저장
                right = mid - 1; // 그러면서 이곳은 왼쪽 인덱스값을 구하는 곳이므로 오른쪽 인덱스를 중앙값보다 작은 값으로 설정해서
                                 // 혹시 더 작은 인덱스에 구하는 값이 있는지 탐색
            }
            else if (nums[mid] < target) // 만약 인덱스가 중앙인 값이 원하는 값보다 작다면
            {
                left = mid + 1; // 작기 때문에 왼쪽 인덱스 값을 중앙 +1로
            }
            else // 전부 아니라면 즉, 인덱스가 중앙인 값이 원하는 값보다 크다면 
            {
                right = mid - 1; // 오른쪽 인덱스값을 중앙보다 -1한 값으로 
            }
        }
        if (first != -1) // -1이 초기에 설정한 값이므로 -1이 아니라면 
        {
            answer.push_back(first); // 왼쪽 인덱스로 first 정답 벡터에 대압
        }

        int left2 = 0; // 왼쪽 인덱스
        int right2 = nums.size() - 1; // 오른쪽 인덱스
        int first2 = -1; // 최종적으로 넣고자 하는 인덱스(오른쪽을 구하므로 가장 오른쪽)
        while (left2 <= right2) // 이 조건을 만족할 때 까지 반복문 실행(원하는 값의 가장 오른쪽 인덱스 구하기)
        {
            int mid2 = left2 + (right2 - left2) / 2; // 중앙값을 좌우 합의 반으로 생각
            if (nums[mid2] == target) // 인덱스가 중앙인 값이 원하는 값과 같다면
            {
                first2 = mid2; // 인덱스값으로 중앙값을 저장
                left2 = mid2 + 1; // 그러면서 이곳은 오른쪽 인덱스값을 구하는 곳이므로 왼쪽 인덱스를 중앙값보다 큰 값으로 설정해서
                                  // 혹시 더 큰 인덱스에 구하는 값이 있는지 탐색
            }
            else if (nums[mid2] < target) // 만약 인덱스가 중앙인 값이 원하는 값보다 작다면
            {
                left2 = mid2 + 1; // 작기 때문에 왼쪽 인덱스 값을 중앙 +1로
            }
            else // 전부 아니라면 즉, 인덱스가 중앙인 값이 원하는 값보다 크다면 
            {
                right2 = mid2 - 1; // 오른쪽 인덱스값을 중앙보다 -1한 값으로 
            }
        }
        if (first2 != -1) // -1이 초기에 설정한 값이므로 -1이 아니라면
        {
            answer.push_back(first2); // 오른쪽 인덱스로 first2 정답 벡터에 대압
        }

        if (answer.empty()) // 정답 벡터가 비어있다면 아예 원하는 target이 없다는 것이므로
        {
            answer.push_back(-1); // 왼쪽 인덱스로 -1 대입
            answer.push_back(-1); // 오른쪽 인덱스로 -1 대입
        }
        else if (answer.size() == 1) // 정답 벡터가 크기가 1이라면 하나만 존재하는 것이므로
        {
            answer.push_back(answer[0]); // 한번 더 넣어서 같은 값을 대입
        }

        return answer; // 정답 벡터 리턴
    }
};