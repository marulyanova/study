#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    if (n == 1){
        cout << 0;
        exit(0);
    }

    if (n == 2 && a[0] != a[1]){
        cout << 0;
        exit(0);
    }
    else if (n == 2 && a[0] == a[1]){
        cout << 1;
        exit(0);
    }

    int v = 0, n1 = 0, val = 0, f1 = 0, f2 = 0, val2 = 0, kol =0;
    vector<int> d;
    d.push_back(a[0]);

    for (int i = 1; i < n; i++){
        if (a[i - 1] == a[i]){
            v++;
        }
    }

    if (v == n - 1){
        cout << n - 1;
        exit(0);
    }
    else{
        for (int i = 1; i < n; i++){
            if (a[i - 1] != a[i]){
                d.push_back(a[i]);
            }
            else{
                val2 += 1;
            }
        }
        n1 = d.size();
        for (int i = 1; i < n1; i++){
            if (d[i - 1] < d[i] && f1 == 0){
                f2 = 0;
                f1 = 1;
                kol += 1;
            }
            else{
                if (f2 == 0 && d[i - 1] > d[i]){
                    f2 = 1;
                    f1 = 0;
                    kol +=1;
                }
            }
        }
    }
    cout << n - kol - 1;
}