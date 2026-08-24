/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 이진탐색                                SS      WW   WW  */
/* Time Complexity   : O(log n)                                SSSSS   WW W WW  */
/* Space Complexity  : O(1)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

//left와 right 중간이 타겟보다 작으면 오른쪽으로 이동, 크면 왼쪽으로 이동
//타겟을 찾으면 지금은 타겟인데 그 전이나 후는 타겟이 아닐때를 찾아서 저장

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int first, end;

        while(1){
            if(left>right){ // left가 right보다 커지면 못찾은 것이므로 -1,-1 return
                return {-1, -1};
            }
            int mid = (left+right)/2; // 중앙값
            if(nums[mid]>target) right = mid-1; // mid 부분 값이 target보다 크면 왼쪽으로 범위 좁힘
            else if(nums[mid]<target) left = mid+1;// mid 부분 값이 target보다 작으면 오른쪽으로 범위 좁힘
            else{ // target을 찾았을 때
                int leftmid = mid, rightmid = mid;

                // first 찾기
                while(1){
                    int m = (left+leftmid)/2; // 중앙값
                    if(nums[m] != target)left = m+1; // 타겟이 중앙값이 아니면 오른쪽으로 범위 좁힘 
                    else{// 중앙값이 타겟일때 그전 인덱스 값이 타겟이 아니거나 더이상 왼쪽으로 이동하지 못하면 first 찾음
                        if(m == 0 || nums[m-1]!= target){
                            first = m;
                            break;
                        }
                        leftmid = m-1; // 왼쪽으로 범위 좁힘
                    }
                }

                // end 찾기
                while(1){
                    int m = (right+rightmid)/2; // 중앙값
                    if(nums[m] != target)right = m-1; // 중앙값이 타겟이 아니면 왼쪽으로 범위 좁힘
                    else{ // 중앙값이 타겟이고 그 다음 인덱스 값이 타겟이 아니거나 더이상 오른쪽으로 이동하지 못하면 end 찾음
                        if(m ==nums.size()-1 || nums[m+1]!= target){
                            end = m;
                            break;
                        }
                        rightmid = m+1; // 오른쪽으로 범위 좁힘
                    }
                }
                return {first, end};
            }
        }
    }
};