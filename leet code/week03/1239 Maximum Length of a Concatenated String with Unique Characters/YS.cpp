/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 비트마스킹                              SS      WW   WW  */
/* Time Complexity   : O(N * L + 2^N * N)                      SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

// arr의 각 원소마다 비트마스킹 해서 원소 내에 중복이 있는지 확인
// 중복 없는것 끼리 조합해서 최대 길이 구함 

// // 문자 → 비트
// int bit = 1 << (c - 'a');

// // 이미 사용한 문자인지
// if (mask & bit)

// 문자 추가
// mask |= bit;
int maxlen = 0;
vector<int> masks; // 중복 없는 원소 모음

void dfs(int start, int mask){
    maxlen = max(maxlen, __builtin_popcount(mask));

    for(int i=start;i<masks.size();i++){
        
        if(mask&masks[i]) continue; // 이미 선택한 문자열과 문자가 겹치면 넘어감
        dfs(i+1, mask|masks[i]); // 문자가 겹치지 않으면 현재 mask와 합쳐 탐색
    }
}



class Solution {
public:
    int maxLength(vector<string>& arr) {
        maxlen = 0;
        masks.clear();
        for(int i=0;i<arr.size();i++){
            int mask = 0;
            bool flag = true; 
            for (char c : arr[i]) {
                int bit = 1 << (c - 'a'); // 문자를 비트로

                if(mask & bit){ // 중복이 있으면 flag에 표시하고 break
                    flag = false;
                    break;
                }
                mask |= bit; // 중복이 없으면 합침
            }
            if(flag) masks.push_back(mask); // 문자열 내부에 중복이 없으면 비트마스크 저장
        }

        dfs(0, 0); 
        return maxlen;
    }
};