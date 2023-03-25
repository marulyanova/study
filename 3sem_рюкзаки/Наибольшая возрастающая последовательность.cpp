#include<bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> dp(n);
    int len = 0;
    for (int i = 0; i < n; i++){
        dp[i] = 1;

        for (int j = 0; j < i; j++){
            if (a[j] < a[i]){
                dp[i] = max(dp[i], 1 + dp[j]);
                len = max(len, dp[i]);
            }
        }
    }
    cout << len;
}

