/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 스택                                    SS      WW   WW  */
/* Time Complexity   : O(N)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

/*
스택에 가격이 아닌 "아직 가격이 떨어진 시점을 찾지 못한 날의 인덱스" 저장

현재 보고있는 가격(prices[i])이 스택 top의 인덱스의 가격보다 낮으면
-> top에 해당하는 날짜(인덱스)의 가격이 현재 시점에서 처음으로 떨어졌음을 의미
-> 현재 인덱스 - top idx를 계산하여 가격이 떨어지지 않은 기간 저장
-> 현재 가격보다 높은 이전 가격들이 스택에 더 저장되어 있을 수 있으므로 조건을 만족하는 동안 위 과정 반복

비교가 끝나면 현재 인덱스를 스택에 추가.
모든 가격을 확인한 후에도(prices 한 번 순회) 스택에 남은 인덱스는 끝까지 가격이 떨어지지 않았음을 의미하므로
마지막 인덱스(n-1)와의 차이를 정답으로 저장
*/

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n);

    //스택에 가격이 아닌 "아직 가격이 떨어진 시점을 찾지 못한 날의 인덱스" 저장
    stack<int> st;

    for(int i = 0; i < n; i++){
        //top의 날짜의 가격이 떨어졌음을 의미
        while(!st.empty() && prices[st.top()] > prices[i]){
            int idx = st.top();

            //idx번째 날부터 i번째 날까지 걸린 날
            answer[idx] = i - idx;

            st.pop();
        }

        
        //현재 i번째 날도 이후 가격들과 비교해야하므로 스택에 넣고 이후 날짜의 가격들과 비교
        st.push(i);
    }

    //스택에 남아있는 값 : 끝까지 가격 하락이 없던 주식들 -> 마지막 날짜 (n-1)에서 본인 인덱스 빼서 기간 구하기
    while(!st.empty()){
        int idx = st.top();
        answer[idx] = (n - 1) - idx;
        st.pop();
    }

    return answer;
}