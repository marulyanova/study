#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long m, n, a, b;
    cin >> m >> n;
    if (n == 0){
        cout << 0;
        exit(0);
    }
    vector<long long> x(m, 0);
    for(long long i = 0; i < n; i++){
        cin >> a >> b;
        a--;
        b--;
        for (long long j = a; j <= b; j++){
            if (x[j] != 0){
                long long k = j + 1;
                while (x[k] == x[j]){
                    x[k] = 0;
                    k++;
                }
                long long t = j - 1;
                while(x[t] == x[j]){
                    x[t] = 0;
                    t--;
                }
                x[j] = 0;
            }
            x[j] = i + 1;
        }
    }

    vector<long long> p(n, 0);
    for (long long i = 0; i < m; i++){
        if (x[i] > 0){
            p[x[i] - 1]++;
        }
    }
    long long countt = 0;
    for (auto i : p){
        if (i){
            countt++;
        }
    }
    cout << countt;
}
