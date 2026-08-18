/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 재귀                                    SS      WW   WW  */
/* Time Complexity   : O(2^N)                                  SSSSS   WW W WW  */
/* Space Complexity  : O(2^N)                                     SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;
void hanoi(int n, int start, int end, int sub){
    if(n == 1){
       answer.push_back({start, end});
        return;
    }
    else{
        hanoi(n-1, start, sub, end); //n-1을 start에서 sub로 이동
        answer.push_back({start, end});
        hanoi(n-1, sub, end, start); // sub로 옮겨진 n-1개 원판을 다시 end로 옮김
    }
}
vector<vector<int>> solution(int n) {
    hanoi(n, 1, 3, 2);
    
    
    return answer;
}