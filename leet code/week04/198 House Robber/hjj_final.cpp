#include <iostream>
#include <vector>

using namespace std;

vector<int> memoization;

int robbing(vector<int>& nums, int cursor) {
	if (cursor == 0) return nums[0];
	else if (cursor == 1) return max(nums[0], nums[1]);

	if (memoization[cursor] != -1) return memoization[cursor];
	memoization[cursor] = max(robbing(nums, cursor - 1), nums[cursor] + robbing(nums, cursor - 2));

	return memoization[cursor];
}

int rob(vector<int>& nums) {
	int n = static_cast<int>(nums.size());
	memoization.resize(n, -1);
	return robbing(nums, n - 1);
}

int main() {
	// 4
	//vector<int> nums = { 1, 2, 3, 1 };

	// 12
	vector<int> nums = { 2, 7, 9, 3, 1 };

	cout << rob(nums);
}