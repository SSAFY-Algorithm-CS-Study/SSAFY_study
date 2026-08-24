/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : ssafy                                   SSSSS   WW   WW  */
/* Algorithm         : 이분탐색                                SS      WW   WW  */
/* Time Complexity   : O(logN)                                 SSSSS   WW W WW  */
/* Space Complexity  : O(1)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target); //target의 첫 인덱스
        
        //target이 nums에 없으면
        if(first == -1) 
            return {-1, -1};

        int last = findLast(nums, target); //target의 마지막 인덱스
        return {first, last};
    }

    //target인 첫 index 반환
    int findFirst(const vector<int>& nums, int target){
        int answer = -1;
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            //오버플로우 방지로 다음과 같이 쓰는 것이 좋다고 함
            // mid = left + (right - left) / 2
            int mid = (left + right) / 2;

            if(nums[mid] >= target){ //현재 값이 타겟 이상이면 right 포인터를 현재값 바로 아래로 이동
                if(nums[mid] == target)
                    answer = mid;


                //타겟을 발견해도 왼쪽에 타겟이 더 있는지 탐색
                right = mid - 1;
            }
            else //현재 값이 타겟보다 작으면 left 포인터를 현재값 바로 위로 이동
                left = mid + 1;
        }
        return answer;
    }

    //target인 마지막 index 반환
    int findLast(const vector<int>& nums, int target){
        int answer = -1;
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = (left + right) / 2;

            if(nums[mid] <= target){ //현재 값이 타겟 이하면 left 포인터를 현재값 바로 위로 이동
                if(nums[mid] == target)
                    answer = mid;

                //타겟을 발견해도 오른쪽에 타겟이 더 있는지 탐색
                left = mid + 1;
            }
            else //현재 값이 타겟보다 크면 right 포인터를 현재값 바로 아래로 이동
                right = mid - 1;
        }
        return answer;
    }
};
