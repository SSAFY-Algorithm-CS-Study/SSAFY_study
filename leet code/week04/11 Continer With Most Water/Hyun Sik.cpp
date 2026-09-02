/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : ssafy                                   SSSSS   WW   WW  */
/* Algorithm         : 투포인터                                SS      WW   WW  */
/* Time Complexity   : O(N)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(1)                                       SS   WWW WWW  */
/* Note              : leet code - 11 Continer With Most Wa…   SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0; // 왼쪽 포인터를 첫 번째 위치로
        int right = height.size() - 1; // 오른쪽 포인터를 마지막 위치로
        int maxS = 0; // 현재까지 구한 물의 최대 넓이
        
        while (left < right) // 두 포인터가 서로 만나기 전까지 탐색
        {
            // 두 높이 중 낮은 높이가 물의 높이가 되고,
            // 두 포인터 사이의 거리가 물의 너비가 됨
            int s = min(height[left], height[right]) * (right - left);
            
            maxS = max(maxS, s); // 현재 넓이와 기존 최대 넓이 중 더 큰 값을 저장
            
            if (height[left] >= height[right]) // 오른쪽 높이가 왼쪽 높이보다 작거나 같으면
            {
                right--; // 더 큰 넓이를 얻기 위해 오른쪽 포인터를 안쪽으로 이동
            }         
            else // 왼쪽 높이가 오른쪽 높이보다 작으면
            {
                left++; // 더 큰 넓이를 얻기 위해 왼쪽 포인터를 안쪽으로 이동
            }
        }
                
        return maxS; // 탐색하면서 구한 최대 넓이 리턴
    }
};