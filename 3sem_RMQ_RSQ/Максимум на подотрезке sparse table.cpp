#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, x, y;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int p = 0;
    while(pow(2, p) < n){
        p++;
    }

    vector<vector<int>> st(p, vector<int> (n, 1000000000));
    st[0] = v;
    for (int i = 1; i < p; i++){
        for (int j = 0; j + pow(2, i) <= n; j++){

            st[i][j] = max(st[i - 1][j], st[i - 1][j + pow(2, i - 1)]);
        }
    }

    vector<int> pows(n + 1);
    pows[1] = 0;
    for(int i = 2; i < n + 1; i++){
        pows[i] = pows[i / 2] + 1;
    }

    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> x >> y;

        int len = y - x + 1;
        int curpow = pows[len];
        int curlen = (1 << curpow);
        cout << max(st[curpow][x - 1], st[curpow][y - curlen]) << " ";
    }
}

