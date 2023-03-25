#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){

    ll n;
    cin >> n;
    vector<ll> v(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
    }

    if (sum % 2 != 0){
        cout << "NO";
        exit(0);
    }

    vector<vector<ll>> dp(sum / 2 + 1, vector<ll> (n + 1, 0));
    for (ll i = 0; i < n + 1; i++){
        dp[0][i] = 1;
    }

    for (ll i = 1; i < sum / 2 + 1; i++){
        for (ll j = 1; j < n + 1; j++){

            if (i - v[j - 1] >= 0){
                dp[i][j] = max(dp[i - v[j - 1]][j - 1], dp[i][j - 1]);
            }
            else{
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    if (dp[sum / 2][n] == 1){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}
