#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++){
        cin >> a[i];
    }

    if (n == 1){
        cout << 1;
        exit(0);
    }

    vector<ll> dp(n);
    ll len = 0;
    for (ll i = 0; i < n; i++){
        dp[i] = 1;

        for (ll j = 0; j < i; j++){
            if (a[i] % a[j] == 0){
                dp[i] = max(dp[i], 1 + dp[j]);
                len = max(len, dp[i]);
            }
        }
    }

    if (len == 0){
        cout << 1;
        exit(0);
    }
    cout << len;
}