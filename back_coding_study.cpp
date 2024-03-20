#include <iostream>
#include <vector>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;

    int max_a = 0;
    int max_b = 0;
    for (int i = 0; i < problems.size(); i++) {
        int request_x = problems[i][0];
        int request_y = problems[i][1];
        if (max_a < request_x) max_a = request_x;
        if (max_b < request_y) max_b = request_y;
    }

    vector<vector<int>> dp(155 + 1, vector<int>(154 + 1, 999999));

    for (int i = 0; i <= alp; i++) {
        for (int j = 0; j <= cop; j++) {
            dp[i][j] = 0;
        }
    }

    for (int k = 0; k < problems.size(); k++) {
        for (int i = 0; i <= 153; i++) {
            for (int j = 0; j <= 153; j++) {
                if (i - 1 >= 0 && j - 1 >= 0) {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]) + 1, dp[i][j]);
                }
                else if (i - 1 >= 0) dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
                else if (j - 1 >= 0) dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);

                if (i >= problems[k][0] && j >= problems[k][1]) {
                    int a = i - problems[k][2];
                    int b = j - problems[k][3];
                    if (a < 0) a = 0;
                    if (b < 0) b = 0;
                    dp[i][j] = min(dp[a][b] + problems[k][4], dp[i][j]);
                }
            }
        }
    }

    return dp[max_a][max_b];
}

int main() {
    cout << solution(0, 0, { {0, 0, 1, 1, 1}, {150, 150, 1, 1, 100} }) << endl;  // 예상 결과: 1
    cout << solution(0, 0, { {4, 3, 1, 1, 100}, {0, 0, 2, 2, 1} }) << endl;  // 예상 결과: 1
    cout << solution(1, 1, { {0, 2, 1, 1, 100} }) << endl;  // 예상 결과: 0
    cout << solution(1, 1, { {2, 0, 1, 1, 100} }) << endl;  // 예상 결과: 0
    cout << solution(2, 2, { {1, 1, 1, 1, 100} }) << endl;  // 예상 결과: 100
    cout << solution(10, 10, { {0, 0, 5, 5, 1}, {30, 10, 1, 1, 100} }) << endl;  // 예상 결과: 1
    cout << solution(0, 0, { {0, 0, 30, 2, 1}, {150, 150, 30, 30, 100} }) << endl;  // 예상 결과: 1

    return 0;
}