#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int len = 0;

    for (int i = 0; i < n; i++){

        int ind = 0, maxx = 0;

        for (int j = 0; j < m; j++){

            dp[i + 1][j] = dp[i][j];

            if (a[i] == b[j]){
                len = max(len, 1);
                dp[i + 1][j] = max(dp[i][j], maxx + 1);
                len = max(len, dp[i + 1][j]);
            }

            if (a[i] > b[j] && dp[i][j] > maxx){
                maxx = dp[i][j];
                len = max(len, maxx);
                ind = j;
            }
        }
    }
    cout << len;
}