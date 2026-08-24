/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 비트마스킹, 재귀                        SS      WW   WW  */
/* Time Complexity   : O(N * 2^N)                              SSSSS   WW W WW  */
/* Space Complexity  : O(N * 2^N)                                 SS   WWW WWW  */
/* Note              : leetcode - 78 Subsets                   SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <vector>
#include <string>
using namespace std;

void run(int currentLevel, int level, string path, char* arr, vector<string>& subset) // 비트마스크를 구하는 재귀 함수
{ // 현재 레벨, 가고자 하는 레벨, 만들고자 하는 비트마스크, 들어가고자 하는 값이 있는 배열, 부분집합을 넣을 벡터
    if (currentLevel == level) // 가고자 하는 레벨에 도달하면
    {
        subset.push_back(path); // 만든 비트마스크를 부분집합 벡터에 대입
        return; // 구해서 넣었으니 리턴으로 재귀 종료
    }

    for (int i = 0; i < 2; i++) // 현재 0과 1만으로 만들어야 하므로 2번 반복문 실행
    {
        path += arr[i]; // 비트마스크로 문자열에 현재 인덱스의 배열 값 추가

        run(currentLevel + 1, level, path, arr, subset); // 다음 레벨 재귀 함수 실행

        path.pop_back(); // 다음 부분집합을 구하는 비트마스크를 구해야 하므로 꺼냄
    }
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer; // 정답 벡터(최종 부분집합)
        string path = ""; // 비트마스크를 만들 문자열
        char arr[3] = "01"; // 0과 1로만 만들어서 비교할 것이므로 0, 1이 들어있는 문자 배열
        int level = nums.size(); // 가고자 하는 레벨(nums 벡터의 크기)
        vector<string> subset; // 비트마스크를 넣을 부분집합 벡터

        run(0, level, path, arr, subset); // 재귀 함수 실행

        answer.resize(subset.size()); // 정답 벡터를 재귀 함수를 통해 만든 부분집합 벡터의 크기로 사이즈를 맞춤
                                      // 그래야 인덱스 접근 가능
        for (int i = 0; i < subset.size(); i++) // 부분집합 벡터의 크기만큼 반복문 싫행
        {
            for (int j = 0; j < level; j++) // 가고자 하는 레벨까지 반복문을 실행(비트마스크의 길이)
            {
                if (subset[i][j] == '1') // 비트마스크 문자 중에서 1이면 
                {
                    answer[i].push_back(nums[j]); // 해당 인덱스의 수를 정답벡터에 대입
                }
            }
        }

        return answer; // 정답 벡터 리턴
    }
};