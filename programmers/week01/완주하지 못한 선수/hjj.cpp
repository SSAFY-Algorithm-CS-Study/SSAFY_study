#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> persons;
    for (string p1 : participant) {
        persons[p1]++;
    }
    cout << endl;
    for (string p2 : completion) {
        persons[p2]--;
        if (persons[p2] == 0) {
            persons.erase(p2);
        }
    }
    for (pair<string, int> p : persons) {
        answer = p.first;
    }
    return answer;
}