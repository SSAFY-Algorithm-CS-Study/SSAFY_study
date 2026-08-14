/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 재귀                                    SS      WW   WW  */
/* Time Complexity   : O(2^N) ~ O(4^N / \sqrt{N})              SSSSS   WW W WW  */
/* Space Complexity  : O(2^N * N)                                 SS   WWW WWW  */
/* Note              : leet : 241 Different Ways to Add Par…   SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> answer;
        for (int i = 0; i < expression.length(); i++)
        {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
            {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));

                for (int l : left) 
                {
                    for (int r : right) 
                    {
                        if (expression[i] == '+')
                        {
                            answer.push_back(l + r);
                        }
                        else if (expression[i] == '-')
                        {
                            answer.push_back(l - r);
                        }
                        else if (expression[i] == '*')
                        {
                            answer.push_back(l * r);
                        }
                    }
                }
            }           
        }

        if (answer.empty()) 
        {
            answer.push_back(stoi(expression));
        }

        return answer;
    }
};