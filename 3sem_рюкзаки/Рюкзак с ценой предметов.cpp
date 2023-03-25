#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> ma(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> ma[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> c[i];
    }

    vector<vector<int>> d(n + 1, vector<int> (m + 1, -1));
    d[0][0] = 0;
    int res = 0;

    for (int i = 1; i <= n; i++){

        int mas = ma[i];
        int cost = c[i];
        
        for (int j = 0; j <= m; j++){
            d[i][j] = d[i - 1][j];
            if (j - mas >= 0 && d[i - 1][j - mas] != -1){
                d[i][j] = max(d[i][j], d[i - 1][j - mas] + cost);
            }
            res = max(res, d[i][j]);
        }
    }
    cout << res;
}