/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 우선순위큐                              SS      WW   WW  */
/* Time Complexity   : O(nlogm)                                SSSSS   WW W WW  */
/* Space Complexity  : O(m)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

// 빈도수가 많은 것부터 내림차순으로 정렬
struct cmp{
    bool operator()(pair<char, int> a, pair<char, int> b){
        return a.second < b.second;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        // 각 문자의 등장 횟수 세기
        unordered_map<char, int> um;
        for(int i = 0; i < s.length(); i++)
            um[s[i]]++;

        priority_queue<pair<char, int> , vector<pair<char, int>>, cmp> pq;
        for(auto p : um) 
            pq.push({p.first, p.second});


        // 제일 많은 단어의 개수 > (문자열 길이 + 1)을 2로 나눈 몫보다 크면 불가능
        if(pq.top().second > (int)((s.length()+1) / 2))
            return "";
        

        string answer = "";
        // 일종의 버퍼. 사용한 문자를 바로 pq에 넣어버리면 같은 문자가 연속으로 올 수도 있음
        pair<char, int> prev = {NULL, 0};

        while(!pq.empty()){
            pair<char, int> temp = pq.top();
            pq.pop();
            
            answer += temp.first; // 문자 붙이기
            temp.second--; // 빈도수--

            // 이전에 answer에 붙인 문자의 개수가 아직 남아있으면 pq에 넣어서 answer에 더해질 수 있도록 함
            if(prev.second > 0)
                pq.push(prev); 

            // prev에 저장해 다음 반복문 때는 prev 문자는 아예 등장 안하게
            prev = {temp.first, temp.second};
        }
        return answer;
    }
};

/*
int main(void)
{   
    Solution sol;
    string result1 = sol.reorganizeString("aab"), result2 = sol.reorganizeString("aaab");

    cout << result1 << "\nresult2: " << result2 << " end";
}*/