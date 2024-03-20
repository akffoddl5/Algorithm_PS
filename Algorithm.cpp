#include <iostream>
#include <math.h>

using namespace std;
int** dp;
int* mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;

    cin >> n;
    dp = new int* [n+1];

    mp = new int[n+1];
    dp[0] = new int[2];
    for (int i = 0; i < n; i++) {
        dp[i+1] = new int[2];
        cin >> mp[i+1];
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = mp[1];
    dp[1][1] = mp[1];
    dp[2][0] = mp[2];
    dp[2][1] = mp[1] + mp[2];

    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 2][0] + dp[i - 2][1] + mp[i];
        dp[i][1] = dp[i - 1][0] + mp[i];
    }

    cout << max(dp[n][0], dp[n][1]) << endl;;

    for (int i = 1; i <= n; i++) {

        cout << dp[i][0] + " ";

    }

    cout << endl;

    for (int i = 1; i <= n; i++) {

        cout << dp[i][1] + " ";

    }


    return 0;
    
}
