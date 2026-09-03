#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
	int n = static_cast<int>(height.size());
	int a = 0;
	int b = n - 1;

	int max_s = 0;
	int curr_s;

	while (a < b) {
		curr_s = (b - a) * min(height[a], height[b]);
		if (max_s < curr_s) max_s = curr_s;

		if (height[a] < height[b]) a++;
		else b--;
	}
	return max_s;
}

int main() {
	// 기대값: 49
	vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	// 기대값: 42
	//vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 7, 3 };
	// 기대값: 1
	//vector<int> height = { 1, 1 };

	cout << maxArea(height);
}