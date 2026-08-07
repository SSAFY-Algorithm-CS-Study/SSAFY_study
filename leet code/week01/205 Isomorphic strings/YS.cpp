/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : MAP                                     SS      WW   WW  */
/* Time Complexity   : O(N Log N)                              SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              : 두개의 map을 사용해서 양방향 대응관계   SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mps, mpt; // s, t 양방향 맵핑
        bool flag = true;
        for (int i = 0;i < s.length();i++) {
            if (mps.find(s[i]) != mps.end()) { // 이미 있는 키면, 키값이랑 t[i]랑 같은지 확인
                if (mps[s[i]] != t[i]) {
                    flag = false;
                    break;
                }
            }
            else if (mpt.find(t[i]) != mpt.end()) {// 이미 있는 키면, 키값이랑 s[i]랑 같은지 확인
                if (mpt[t[i]] != s[i]) {
                    flag = false;
                    break;
                }
            }
            else { // 키값이 없으면 추가
                mps[s[i]] = t[i];
                mpt[t[i]] = s[i];
            }

        }
        return flag;
    }
};