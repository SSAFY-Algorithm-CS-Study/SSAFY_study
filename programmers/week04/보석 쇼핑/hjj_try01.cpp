#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

//vector<int> solution(vector<string> gems) {
//    vector<int> answer;
//    map<string, int> gem_counts;
//    gem_counts.insert({ gems[0], 1 });
//
//    int gems_size = gems.size();
//    int start = 0;
//    int end = 0;
//    int curr_start = 0;
//    int curr_end = 0;
//    string curr;
//
//    while (curr_start != ++curr_end) {
//        cout << "현재 start 및 end : " << curr_start << "\t" << curr_end << "\n";
//        if (curr_end == gems_size) {
//            curr_end--;
//            if (gem_counts[gems[curr_start]] == 1) break;
//            else {
//                gem_counts[gems[curr_start]]--;
//                curr_start++;
//                start = curr_start;
//                if (curr_start == curr_end) break;
//            }
//        }
//        else {
//            if (!gems[curr_end].compare(gems[curr_start])) {
//                curr_start++;
//                start = curr_start;
//            }
//            else {
//                if (gem_counts.find(gems[curr_end]) == gem_counts.end()) {
//                    gem_counts.insert({ gems[curr_end], 1 });
//                    end = curr_end;
//                }
//                else {
//                    gem_counts[gems[curr_end]]++;
//                }
//            }
//        }
//    }
//    
//    answer.push_back(start + 1);
//    answer.push_back(end + 1);
//
//    return answer;
//}

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int gems_size = gems.size();

    map<string, int> whole_gems;
    map<string, int> curr_gems;

    int start = 0;
    int end = 0;
    int curr = 0;

    for (curr; curr < gems_size; curr++) {
        if (whole_gems.find(gems[curr]) == whole_gems.end()) {
            whole_gems.insert({ gems[curr], 1 });
            curr_gems = whole_gems;
            end = curr;
        }
        else {
            whole_gems[gems[curr]]++;
        }
    }

    cout << start << " " << end << "\n";
    answer.push_back(start + 1);
    answer.push_back(end + 1);

    while (start < end) {
        if (end - start + 1 < answer[1] - answer[0] + 1) {
            answer[0] = start + 1;
            answer[1] = end + 1;
        }
        if (end - start + 1 < curr_gems.size()) {
            if (end + 1 == gems_size) {
                break;
            }
            else if (gems[start - 1] == gems[end + 1]) {
                end++;
                curr_gems[gems[end]]++;
            }
            else {
                break;
            }
        }
        else {
            if (curr_gems[gems[start]] <= 1) {
                if (end + 1 == gems_size) {
                    break;
                }
                else if (!gems[start].compare(gems[end + 1])) {
                    end++;
                    curr_gems[gems[end]]++;
                }
                else {
                    break;
                }
            }
        }
        curr_gems[gems[start]]--;
        start++;
    }

    return answer;
}

int main() {
    // {3, 7}
    //vector<string> gems = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
    // {1, 3}
    //vector<string> gems = { "AA", "AB", "AC", "AA", "AC" };
    // {4, 6}
    //vector<string> gems = { "AA", "AB", "AB", "AA", "AB", "AC", "AA", "AC" };
    // {1, 1}
    //vector<string> gems = { "XYZ", "XYZ", "XYZ" };
    // {1, 5}
    //vector<string> gems = { "ZZZ", "YYY", "NNNN", "YYY", "BBB" };
    // {3, 5}
    vector<string> gems = { "A", "B", "B", "C", "A", "C", "B", "B", "A" };

    for (int elem : solution(gems)) {
        cout << elem << " ";
    }
}
