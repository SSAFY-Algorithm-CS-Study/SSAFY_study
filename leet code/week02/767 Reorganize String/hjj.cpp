class Solution {
public:
	string reorganizeString(string s) {
		// 아이디어
		// 개수가 가장 많은 문자를 우선 배치한다
		// 개수가 가장 많은 문자 -> 우선순위 큐 (개수, 문자) 꼴로 저장

		// 각 인덱스는 문자를 가리킴 (a: 0, e: 4)
		// 인덱스에 해당하는 문자의 개수를 저장
		int counting[int('z') - int('a') + 1] = { 0 };

		// (개수, 문자) 를 개수의 내림차순 순으로 정렬할 우선순위 큐 'data' 정의
		priority_queue<pair<int, char>> data;

		// 1. 먼저 개수를 센다
		for (char c : s) {
			counting[int(c) - int('a')]++;
		}

		// 2. 우선순위 큐에 입력한다
		for (int idx = 0; idx < sizeof(counting) / sizeof(int); idx++) {
			if (counting[idx] > 0) {
				data.push({ counting[idx], char(int('a') + idx) });
			}
		}

		// 3. 답을 출력한다

		string answer = "";

		// 우선순위 큐의 가장 위의 원소
		pair<int, char> data_top;
		// case 3에 해당할 경우, 임시로 원소를 저장할 큐(스택도 상관 없음. 중요한건 넣고 빼는데 O(1)인 자료구조면 됨)
		queue<pair<int, char>> data_top_saving;
		// case 3에서 answer에 문자가 더해졌는지 여부
		bool is_answer_added = false;

		// 우선순위 큐가 모두 빌 때까지 반복
		while (!data.empty()) {
			// 초기화
			data_top = data.top();
			is_answer_added = false;

			// case 1: answer가 비어있는 경우
			// 바로 문자를 추가한다
			// 문자를 추가하고 나면, 카운팅이 1 감소한다. 이를 반영하여 우선순위 큐에 다시 저장한다
			// 만약 answer에 문자를 추가하고 나서, 문자 개수가 0개가 된 경우는 우선순위 큐에 저장하지 않는다
			if (answer.length() == 0) {
				answer += data_top.second;
				data.pop();
				if (data_top.first > 1) {
					data.push({ data_top.first - 1, data_top.second });
				}
			}
			// case 2: answer의 맨 마지막 문자와, 우선순위 큐의 top 원소의 문자와 다른 경우
			// 바로 문자를 추가한다
			// 문자를 추가하고 나면, 카운팅이 1 감소한다. 이를 반영하여 우선순위 큐에 다시 저장한다
			// 만약 answer에 문자를 추가하고 나서, 문자 개수가 0개가 된 경우는 우선순위 큐에 저장하지 않는다
			else if (answer[answer.length() - 1] != data_top.second) {
				answer += data_top.second;
				data.pop();
				if (data_top.first > 1) {
					data.push({ data_top.first - 1, data_top.second });
				}
			}
			// case 3: answer의 맨 마지막 문자와, 우선순위 큐의 top 원소의 문자가 같은 경우
			else {
				// data의 원소들을 빼면서 확인해간다
				while (!data.empty()) {
					// 뺀 원소들을 임시 저장
					data_top_saving.push(data_top);
					data.pop();

					data_top = data.top();
					// answer의 맨 마지막 문자와, 우선순위 큐의 top 원소의 문자와 다른 경우
					if (answer[answer.length() - 1] != data_top.second) {
						// case 2와 유사하게 진행한다. is_answer_added 플래그를 true로 변경한다
						answer += data_top.second;
						is_answer_added = true;
						data.pop();

						if (data_top.first > 1) {
							data.push({ data_top.first - 1, data_top.second });
						}

						// 임시 저장했던 원소들을 다시 우선순위 큐에 추가한다
						while (!data_top_saving.empty()) {
							data.push(data_top_saving.front());
							data_top_saving.pop();
						}

						break;
					}
				}
				// case 3인데 is_answer_added 가 false인 경우
				// answer의 마지막 문자와 서로 다른 문자가 우선순위 큐 내부에 없다는 뜻이므로
				// 조건을 만족하는 answer를 리턴할 수 없다.
				if (!is_answer_added) {
					return "";
				}
			}
		}

		return answer;
	}
};