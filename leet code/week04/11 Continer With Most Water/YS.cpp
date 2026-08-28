/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 투포인터                                SS      WW   WW  */
/* Time Complexity   : O(n)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(1)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxwater = 0;
        while(left<right){
            int water = (right-left)* min(height[right], height[left]); // 현재 위치에서 물의양
            maxwater = max(maxwater, water); //max 물의양 저장
            
            // left, right 중 더 작은 값을 옮겨줌 
            if(height[left]<height[right]) left ++;
            else right--;
        }
        return maxwater;
    }
};