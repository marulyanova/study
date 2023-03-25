#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int e, f, n;
    cin >> e >> f >> n;
    vector<int> p(n), w(n);
    for (int i = 0; i < n; i++){
        cin >> p[i] >> w[i];
    }

    if (e == f){
        cout << 0 << " " << 0;
        exit(0);
    }

    vector<int> d(f - e + 1, -1);
    vector<int> h(f - e + 1, 1e9);
    d[0] = 0;
    h[0] = 0;

    for (int i = 1; i < f - e + 1; i++){

        for (int j = 0; j < n; j++){

            if (i - w[j] >= 0 && h[i - w[j]] != 1e9){
                d[i] = max(d[i], d[i - w[j]] + p[j]);
                h[i] = min(h[i], h[i - w[j]] + p[j]);
            }
        }
    }

    if (h[f - e] == 1e9){
        cout << "This is impossible.";
        exit(0);
    }
    else{
        cout << h[f - e] << " " << d[f - e];
    }
}

