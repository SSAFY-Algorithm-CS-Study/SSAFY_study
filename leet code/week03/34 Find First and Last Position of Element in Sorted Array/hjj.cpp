#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
	// nums 의 길이를 별도로 저장한다
	// static_cast<int>: int로 안전하게 형변환 한다. vector.size()의 자료형은 size_t 이므로
	// 연산 시 의도치 않은 오버/언더 플로우 현상이 발생할 수 있다.
	int nums_size = static_cast<int>(nums.size());

	// 공집합인 경우 별도로 처리한다
	if (nums_size == 0) {
		return { -1, -1 };
	}

	// 탐색할 영역의 시작과 끝
	int begin;
	int end;

	// left: target이 처음으로 등장하는 index
	// right: target이 마지막으로 등장하는 index
	// left 및 right의 초기값
	int left = nums_size;
	int right = -1;

	// left 탐색 시 사용할 중간 index: mid1
	// right 탐색 시 사용할 중간 index: mid2
	int mid1;
	int mid2;

	// [left 탐색]
	// begin 및 end 초기화
	begin = 0;
	end = nums_size - 1;

	while (begin < end) {
		mid1 = begin + (end - begin) / 2;

		// left 탐색 시, target이 nums[mid1] 보다 작거나 같은 조건으로 탐색하는 것이 중요
		// 왜냐하면 left는 가능한 왼쪽에 위치해야 한다
		// 그 외 로직은 동일하다
		if (target <= nums[mid1]) {
			if (target == nums[mid1] && left > mid1) {
				left = mid1;
			}
			end = mid1;
		}
		else {
			begin = mid1 + 1;
		}
	}
	// begin >= end 일 때, left는 begin으로 취급한다
	if (target == nums[begin]) left = begin;

	// [right 탐색]
	// begin 및 end 초기화
	begin = 0;
	end = nums_size - 1;

	while (begin < end) {
		mid2 = begin + (end - begin) / 2;

		// right 탐색 시, target이 nums[mid1] 보다 크거나 같은 조건으로 탐색하는 것이 중요
		// 왜냐하면 right는 가능한 오른쪽에 위치해야 한다
		// 그 외 로직은 동일하다
		if (target >= nums[mid2]) {
			if (target == nums[mid2] && right < mid2) {
				right = mid2;
			}
			begin = mid2 + 1;
		}
		else {
			end = mid2;
		}
	}
	// begin >= end 일 때, right는 end로 취급한다
	if (target == nums[end]) right = end;

	// 만약 left나 right이 초기값과 같은 경우, 탐색에 실패했다는 뜻이므로 그에 맞게 리턴
	if (left == nums_size || right == -1) {
		return { -1, -1 };
	}
	// 탐색에 성공한 경우 정상 리턴
	else {
		return { left, right };
	}
}

// 확인용
int main() {
	vector<int> input_nums = {};
	int target_num = 6;

	cout << "[";
	for (int elem : searchRange(input_nums, target_num)) {
		cout << elem << ", ";
	}
	cout << "]";
}