/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 자료구조 : 맵                           SS      WW   WW  */
/* Time Complexity   : O(NlogN)                                SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //이전 - 이후 문자가 각각 어디에 대응되는지 기록 (인접리스트랑 같은 원리)
        map<char, set<char>> m1, m2; 
        
        for(int i = 0; i < s.length(); i++){
            char temp1 = s[i], temp2 = t[i];
            m1[temp1].insert(temp2); // edge case: f11 -> b23 
            m2[temp2].insert(temp1); // edge case: f12 -> b22
        }

        //1:1 대응이 되는지 확인. set 크기가 0이거나 2 이상이면 1:1 대응이 아니라는 뜻
        bool flag = true;
        for(auto p : m1){
            if(p.second.size() != 1)
                flag = false;
        }

        for(auto p : m2){
            if(p.second.size() != 1)
                flag = false;
        }

        if(flag)
            return true;
        else
            return false;
    }
};

/*
int main(void)
{
    Solution sol;

    cout << sol.isIsomorphic("egg", "add") << sol.isIsomorphic("f11", "b23") << sol.isIsomorphic("paper", "title");
}*/