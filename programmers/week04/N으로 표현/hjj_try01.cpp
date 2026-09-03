#include <iostream>

using namespace std;


// N으로 만들 수 있는 숫자
// 1 (N / N), 11 (NN / N), ...
// 아니면 DP 니까 점화식을 사용한다?
// f(1) = N / N
// f(2) = f(1) + f(1) = N/N + N/N ? -> (N + N) / N
// f(3) = f(2) + f(1) = (N + N) / N + N/N ? -> (N + N + N) / N
int solution(int N, int number) {
    int answer = 0;




    return answer;
}

int main() {
    int N = 5;
    int number = 12;

    cout << solution(N, number) << "\n";
}