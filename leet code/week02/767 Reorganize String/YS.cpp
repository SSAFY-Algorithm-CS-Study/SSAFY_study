/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 우선순위 큐                             SS      WW   WW  */
/* Time Complexity   : O(N log K)                              SSSSS   WW W WW  */
/* Space Complexity  : O(K)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<vector<int>> pq; //(개수, 알파벳)
        int DAT[26] = {0}; // 알파벳 갯수 세기
        string answer = "";

        for (int i = 0; i < s.length(); i++) {
            DAT[s[i] - 'a']++;// 알파벳 갯수 세기
        }

        for (int i = 0; i < 26; i++) {
            if (DAT[i] > 0) {
                pq.push({DAT[i], i});  //(개수, 알파벳)으로 push
            }
        }

        while(!pq.empty()){
            vector<int> first;
            first = pq.top(); //first에 제일 개수 많은거 담고 pop
            pq.pop();

            if(answer.empty() || answer.back() !=  char(first[1]+'a')){ //answer가 비어있거나 전 글자와 first가 다르면
                answer += char(first[1]+'a'); // first글자 추가
                first[0]--; // 개수 1개 줄이고 0보다 크면 다시 푸시
                if(first[0]>0)pq.push(first);
            }
            else{
                if(pq.empty()) return ""; // 글자 마지막이랑 first가 같은데 empty이면 ""return
                vector<int> second;
                second = pq.top(); //두번쨰로 큰거 담고 pop
                pq.pop();
                answer += char(second[1]+'a'); // second 추가하고 갯수 줄이고 0보다 크면 다시 push
                second[0]--;
                if(second[0]>0)pq.push(second);
                pq.push(first); // first도 다시 푸시해줌
            }
        }
        return answer;
    }
};
