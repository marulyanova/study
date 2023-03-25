#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;
    vector<long long> z(n);
    vector<long long> pref(n);
    for (long long i = 0; i< n; i++){
        cin >> z[i];
    }

    for (long long i = 0; i < n; i++){
        if (z[i] > 0){
            for (long long j = z[i]; j > 0; j--){

                pref[i + j - 1] = max(pref[i + j - 1], j);
                if (j < pref[i + j - 1]){
                    break;
                }
            }
        }
    }

    for (auto i : pref){
        cout << i << " ";
    }
}
