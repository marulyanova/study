#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void print(ll i, ll j, vector<vector<pair<ll, ll>>> par){

    if (i == 0 || j == 0){
        return;
    }
    if (par[i][j].first == i - 1 && par[i][j].second == j - 1){
        print(i - 1, j - 1, par);
        cout << i << " ";
    }
    else{
        if (par[i][j].first == i - 1 && par[i][j].second == j){
            print(i - 1, j, par);
        }
        else{
            print(i, j - 1, par);
        }
    }
}

void print2(ll i, ll j, vector<vector<pair<ll, ll>>> par){

    if (i == 0 || j == 0){
        return;
    }
    if (par[i][j].first == i - 1 && par[i][j].second == j - 1){
        print2(i - 1, j - 1, par);
        cout << j << " ";
    }
    else{
        if (par[i][j].first == i - 1 && par[i][j].second == j){
            print2(i - 1, j, par);
        }
        else{
            print2(i, j - 1, par);
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    cin >> a >> b;

    ll len = 0;
    vector<vector<ll>> dp(a.size() + 1, vector<ll> (b.size() + 1, 0));
    vector<vector<pair<ll, ll>>> par(a.size() + 1, vector<pair<ll, ll>> (b.size() + 1, {0, 0}));

    for (int i = 1; i <= a.size(); i++){
        for (int j = 1; j <= b.size(); j++){

            if (dp[i - 1][j] > dp[i][j - 1]){
                dp[i][j] = dp[i - 1][j];
                par[i][j] = {i - 1, j};
            }
            else{
                dp[i][j] = dp[i][j - 1];
                par[i][j] = {i, j - 1};
            }
            len = max(len, dp[i][j]);

            if (a[i - 1] == b[j - 1]) {

                dp[i][j] = dp[i - 1][j - 1] + 1;
                par[i][j] = {i - 1, j - 1};
                len = max(len, dp[i][j]);
            }
        }
    }

    cout << len << endl;
    print(a.size(), b.size(), par);
    cout << endl;
    print2(a.size(), b.size(), par);
}