/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : Park Yeonseo                            SSSSS   WW   WW  */
/* Algorithm         : map                                     SS      WW   WW  */
/* Time Complexity   : O(N log N)                              SSSSS   WW W WW  */
/* Space Complexity  : O(1)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end()); // participant 정렬
    sort(completion.begin(), completion.end()); // completion 정렬
    for(int i = 0;i<completion.size();i++){
        if(completion[i] !=participant[i]){ // 두개가 다르면 answer에 저장
            answer = participant[i];
            return answer;
        }
    }
    answer = participant[participant.size()-1]; // 다른걸 못찾았으면 맨끝에 있는 요소 answer에 저장
    return answer;
}