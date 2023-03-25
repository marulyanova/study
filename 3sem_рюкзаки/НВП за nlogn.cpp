#include<bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, a, k, b, m;
    cin >> n >> a >> k >> b >> m;

    if (n == 1){
        cout << 1;
        exit(0);
    }

    vector<long long> v(n);
    v[0] = a;
    for (long long i = 1; i < n; i++){
        v[i] = (((k * v[i - 1]) % m) + (b % m)) % m;
    }

    vector<long long> dp(n + 1, 1e18);
    dp[0] = -1e18;

    for (int i = 0; i < n; i++){

        int j = int (upper_bound (dp.begin(), dp.end(), v[i]) - dp.begin());
        if (dp[j - 1] < v[i] && v[i] < dp[j]){
            dp[j] = v[i];
        }
    }

    long long len = 0;
    for (long long i = 1; i < dp.size(); i++){
        if (dp[i] != 1e18){
            len = i;
        }
    }

    if (len == 0){
        cout << 1;
        exit(0);
    }

    cout << len;
}