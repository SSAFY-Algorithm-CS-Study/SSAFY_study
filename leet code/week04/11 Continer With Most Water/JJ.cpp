/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : ssafy                                   SSSSS   WW   WW  */
/* Algorithm         : 투포인터, 그리디                        SS      WW   WW  */
/* Time Complexity   : O(N)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(1)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int Max = 0;

        int left = 0, right = height.size() - 1;

        while(left != right){
            //둘 중 낮은 높이를 가진 막대가 직사각형의 높이가 됨
            int h = min(height[left], height[right]);
            //직사각형 높이를 계산 후 Max 갱신
            Max = max(Max, (right - left) * h); 

            // 둘 중 더 낮은 높이를 가진 막대를 안쪽으로 옮기기
            if(height[left] > height[right])
                right--;
            else
                left++;
        }

        return Max;
    }
};

/*
int main(void)
{
    Solution sol;
    vector<int> height = {1,8,6,2,5,4,8,3,7} , height2 = {1,1};

    cout << sol.maxArea(height) << ' ' << sol.maxArea(height2);
}*/