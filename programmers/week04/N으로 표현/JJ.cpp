/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : ssafy                                   SSSSS   WW   WW  */
/* Algorithm         : dp                                      SS      WW   WW  */
/* Time Complexity   : O(1)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(1)                                       SS   WWW WWW  */
/* Note              : N의 최댓값이 8일 때                     SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

/*
dp[i] : n을 i개 사용해서 만들 수 있는 수의 집합

dp[0]   : 0
dp[1]   : 1 (n)
dp[2]   : nn , n + n , n - n , n * n , n / n
dp[3]   : nnn , 
          n + nn , n - nn , n * nn , n / nn , nn + n , nn - n , nn * n , nn / n
          n + (n+n) , n - (n+n) , n * (n+n) , n / (n+n) , (n+n) + n , (n+n) - n , (n+n) * n , (n+n) / n
          n + (n-n) , n - (n-n) , n * (n-n) , n / (n-n) , (n-n) + n , (n-n) - n , (n-n) * n , (n-n) / n
          n + (n*n) , n - (n*n) , n * (n*n) , n / (n*n) , (n*n) + n , (n*n) - n , (n*n) * n , (n*n) / n
          n + (n/n) , n - (n/n) , n * (n/n) , n / (n/n) , (n/n) + n , (n/n) - n , (n/n) * n , (n/n) / n


dp[k] = dp[a] + dp[b] (a + b = k)
dp[a]의 값과 dp[b]의 값들의 조합 집합 = dp[k]

///////////////////////////////////////

k = 7
dp[7] = dp[1] + dp[6]
        dp[2] + dp[5]
        dp[3] + dp[4]
        dp[4] + dp[3]
        dp[5] + dp[2]
        dp[6] + dp[1]

*/

#include <bits/stdc++.h>

using namespace std;

vector<set<int>> dp(9);

void make_combination(int idx)
{
    // dp[x] 와 dp[y]의 순열조합을 set 안에 넣어줌.
    for(int i = 1; i < idx; i++){
        for(int x : dp[i]){ 
            for(int y : dp[idx - i]){
                dp[idx].insert(x + y);
                dp[idx].insert(x - y);
                dp[idx].insert(x * y);

                if(y != 0)
                    dp[idx].insert(x / y);
            }
        }
    }
}

int solution(int N, int number)
{
    int answer = -1;
    int temp = 0;
    for(int i = 1; i <= 8; i++){
        //dp[i]에 연속된 i개의 N 넣어줌 (연속된 수는 사칙연산으로 만들 수 없어서 따로 넣어주는 것)
        //5 55 555 5555
        temp += N;
        dp[i].insert(temp);
        temp *= 10;

        make_combination(i); //조합 만들기
    }

    //set 안에 number가 없으면 -1 리턴 , 있으면 인덱스(number를 만드는데 든 n 개수) 리턴
    //역순으로 for문을 돌린 이유는 최솟값으로 answer를 리턴하기 위해. (12를 만드는데 필요한 5의 개수는 4 or 8임. i가 오름차순으로 오르게 되면 8을 리턴하게 됨)
    //사실 i 오름차순으로 돌리고 answer = i 후 리턴하면 되는데 깔끔하게 표현하고 싶어서 아래처럼 구현. (시간적인 면에선 비효율적)
    for(int i = 8; i >= 1; i--) 
        if(dp[i].find(number) != dp[i].end())
            answer = i;
    
    return answer;
}
