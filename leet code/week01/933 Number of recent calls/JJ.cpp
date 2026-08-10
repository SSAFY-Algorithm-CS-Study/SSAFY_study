/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 자료구조 : 우선순위 큐                  SS      WW   WW  */
/* Time Complexity   : O(NlogN)                                SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class RecentCounter {
private:
    priority_queue<int, vector<int>, greater<int>> q; //최소 우선순위 큐 (항상 오름차순으로 유지)

public:
    RecentCounter() {
        //생성자
    }
    
    int ping(int t) {
        int Min = t - 3000;
        
        q.push(t);

        //q가 비어있을 때 q.top -> 에러. 먼저 비어있는지 검사
        //안에 값이 존재하면 가장 오래된 시간 검사. Min 보다 작으면 카운팅 안되게 pop. Min 이상이 될 때까지 반복
        while(!q.empty() && q.top() < Min) 
            q.pop();

        return q.size();
    }
};

/*
int main(int argc, char* argv[])
{
    RecentCounter rc;

    vector<int> test = {1, 100, 3001, 3002};

    for(int t : test){
        cout << "ping(" << t << ") = ";
        cout << rc.ping(t) << '\n';
    }
}*/