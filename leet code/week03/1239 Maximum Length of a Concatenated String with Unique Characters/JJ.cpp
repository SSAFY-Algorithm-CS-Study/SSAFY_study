/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : ssafy                                   SSSSS   WW   WW  */
/* Algorithm         :                                         SS      WW   WW  */
/* Time Complexity   :                                         SSSSS   WW W WW  */
/* Space Complexity  :                                            SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <iostream>
#include <vector>


using namespace std;

/*
알파벳은 26개의 비트로 표현하기 쉽기 때문에 비트마스킹의 대표 유형으로 자주 나옴

    하나의 문자열 안에서도 중복이 없어야 함
    합 칠 두 문자열 사이에도 중복이 없어야 함

    1. 각 문자열을 비트마스크로 변환 - 내부 중복이 있으면 조합 후보에서 거르기
    2. DFS(백트래킹)로 문자열을 하나씩 선택 (조합)
    3. 문자열들을 선택할 때마다 & 연산 진행. 값이 0이면 겹치는 문자가 없다는 뜻이므로 선택 (합치는 건 | 연산. 새로운 비트마스크로 합친 문자열 표현)
    4. 합칠 때마다 Max값 갱신
*/
class Solution {
public:
    int Max = 0;
    vector<int> Masks;

    void dfs(int idx, int currMask){

        int cnt = 0;
        int temp = currMask;
        
        //currMask의 1의 개수 세기
        while(temp != 0){
            cnt += temp & 1;
            temp >>= 1;
        }
        Max = max(Max, cnt);

        //조합 연산
        for(int i = idx; i < Masks.size(); i++){
            if((currMask & Masks[i]) == 0)
                dfs(i+1, currMask | Masks[i]);
        }
    }

    int maxLength(vector<string>& arr) {

        //arr내 문자열 한 개씩 가져와서 그 안에 중복이 있는지 우선 검사 후 후보에 등록
        for(const string& s : arr){
            int mask = 0;
            bool flag = false;

            for(const char& c : s){
                int bit = c - 'a'; //0~25번째 비트에 대응 : a->0 , b->1, c->2 ... z->25

                //중복검사. 이전에 a가 나왔으면 0번째 비트가 on일텐데 & 연산으로 1이 됨
                if(mask & (1 << bit)){
                    flag = true;
                    break;
                }

                //중복이 없으면 해당 알파벳 비트마스크에 등록
                mask |= (1 << bit);
            }

            //문자열 내 중복 없으면 후보 등록
            if(!flag)
                Masks.push_back(mask);
        }

        dfs(0,0);
        return Max;
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    vector<string> arr1 = {"un", "iq", "ue"}, arr2 = {"cha", "r", "act", "ers"}, arr3 = {"abcdefghijklmnopqrstuvwxyz"};

    cout << sol.maxLength(arr1) << sol.maxLength(arr2) << sol.maxLength(arr3);
    // cout << sol.maxLength(arr3);
}