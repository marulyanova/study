#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;
    vector<int> z(n, 0);
    vector<int> pref(n);
    for (int i = 0; i < n; i++){
        cin >> pref[i];
    }

    for(int i = 1; i < n; i++){
        if(pref[i] > 0){
            z[i - pref[i] + 1] = pref[i];
        }
    }

    if(z[1]){
        for(int i = 1; i < z[1]; i++){
            z[i + 1] = z[1] - i;
        }
    }

    for(int i = z[1] + 1; i < n - 1; i++) {
        int x = i;
        if(z[i] && z[i + 1] == 0){

            for(int j = 1; j < z[i] && z[i + j] <= z[j]; j++){
                z[i + j] = min(z[j], z[i] - j);
                x = i + j;
            }
        }
        i = x;
    }
    for (auto i : z){
        cout << i << " ";
    }
}
