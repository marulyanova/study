#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int> a(n);
    int maxx = 0;

    for (int i = 0; i < n; i++){
        a[i] = 1;
        maxx = max(maxx, a[i]);

        for (int j = 0; j < i; j++){
            if (v[j] < v[i]){
                a[i] = max(a[i], a[j] + 1);
                maxx = max(maxx, a[i]);
            }
        }
    }
    cout << n - maxx;
}