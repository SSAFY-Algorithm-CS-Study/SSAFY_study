#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int n = people.size();
    // 1. 정렬
    sort(people.begin(), people.end());

    // 2.
    // 문제 조건 상 최대 2명까지 가능하므로
    // 그럼 한 사람은 가장 몸무게가 작은 사람
    // 다른 한 사람은 가장 몸무게가 큰 사람부터 무게를 줄여가며 확인한다

    // 구명 보트 수
    int boats = 0;

    // 범위 좁혀가면서 확인
    int i = 0;
    int j = n - 1;

    // 이 조건이여도 괜찮은 이유
    // i와 j가 서로 같아질 때까지 반복인데
    // 최악의 경우여도(2명 보트 없는 경우) j는 n-1부터 0까지 변화하므로
    // 총 n개 보트 수를 만족하게 됨
    // 2명 보트가 만들어지는 경우
    // 일단 i 인덱스 사람보다 더 적은 무게로 이루어진 2명 보트는 없으므로
    // i 인덱스에서 +1을 하게 되며
    // j 인덱스 또한 j 인덱스 사람보다 더 많은 무게로 이룰 수 있는 2명 보트가 없으므로
    // 그대로 나아가면 된다
    // 반복문 하나로 모두 체크할 수 있는 방법 (투 포인터)
    while (i <= j) {
        if (people[i] + people[j] <= limit) {
            i++;
        }
        boats++;
        j--;
    }

    return boats;
}