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

    vector<pair<long long, long long>> x;
    for (long long i = 0; i < n; i++){
        cin >> a >> b;
        x.push_back(make_pair(a, b));

        long long s = x.size();
        long long j = 0;
        while (j < s - 1){
            if ((x[j].first <= a & x[j].second >= b) | (x[j].first >= a & x[j].second <= b) | (x[j].first <= a & x[j].second >= a) | (x[j].first <= b & x[j].second >= b)){
                x.erase(x.begin() + j);
                s--;
                j--;
            }
            j++;
        }
    }
    cout << x.size();
}
