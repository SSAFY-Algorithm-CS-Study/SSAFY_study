/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         :                                         SS      WW   WW  */
/* Time Complexity   : O(Q * A * N^2)                          SSSSS   WW W WW  */
/* Space Complexity  : O(N^2)                                     SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <iostream>
using namespace std;

int main(void) {
    int n, arr[100][100], temp[100][100], q, y, x, turnsize, turnangle;
    cin >> n;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> arr[i][j];
        }
    }
    cin >> q;
    for (int i = 0;i < q;i++) {
        cin >> y >> x >> turnsize >> turnangle;
        for (int j = 0;j < turnangle;j++) {
            for (int l = 0;l < n;l++) {
                for (int m = 0;m < n;m++) {
                    temp[l][m] = arr[l][m];
                }
            }
            for (int k = y;k < y + turnsize;k++) {
                for (int l = x;l < x + turnsize;l++) {
                    arr[k][l] = temp[y+l-x][x + turnsize - 1-k+y];
                }
            }
        }
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cout << arr[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
};

