/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 셋                                      SS      WW   WW  */
/* Time Complexity   : O(N)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              : leet - 217 Contains Duplicate           SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        int sizeNums = nums.size();
        unordered_set<int> us;
        for (int i = 0; i < sizeNums; i++)
        {
            us.insert(nums[i]);
        }
        if (sizeNums == us.size())
        {
            return false;
        }
        return true;
    }
};