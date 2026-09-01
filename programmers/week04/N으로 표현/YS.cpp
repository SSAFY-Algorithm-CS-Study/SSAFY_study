/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : DP                                      SS      WW   WW  */
/* Time Complexity   : O(S^2)                                  SSSSS   WW W WW  */
/* Space Complexity  : O(S)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(int N, int number) {
    vector<unordered_set<int>> dp(9); // N을 i개 사용해서 만들수 있는 숫자 모음
    int num = 0;
    for(int i=1;i<9;i++){
        num = num*10 + N; //  N을 i개 이어 붙인 숫자 생성
        dp[i].insert(num);
        int left = 1;
        int right = i-1;
        while(right!=0){ // left+right = i인 left와 right 조합
            for(int a: dp[left]){
                for(int b:dp[right]){
                    dp[i].insert(a+b);
                    dp[i].insert(a-b);
                    dp[i].insert(a*b);
                    if(b!=0)dp[i].insert(a/b); // 분모가 0이 아닐때만
                }
            }
            left++;
            right--;
        }    
        if(dp[i].find(number) != dp[i].end()){ // 넣은것 중 number가 있으면 i 개가 최소값이니까 i return
            return i;
        }
    }
    
    return -1; // N을 8개 까지 사용했을때 number를 못나타내므로 -1 반환
}
