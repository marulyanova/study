#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, k, x, y;
    cin >> n >> k >> x >> y;

    long long p = x * 2;
    if (y == 1){
        p--;
    }

    long long p2 = p + k;
    long long p1 = p - k;

    if (p2 > n && p1 <= 0){
        cout << -1;
        exit(0);
    }

    long long x1, y1, x2, y2;
    if (k % 2 > 0){
        if (y == 2){
            y1 = 1;
            y2 = 1;
        }
        else{
            y1 = 2;
            y2 = 2;
        }
    }
    else{
        y1 = y;
        y2 = y;
    }

    x2 = p2 / 2;
    if (y2 == 1){
        x2++;
    }
    x1 = p1 / 2;
    if (y1 == 1){
        x1++;
    }

    if (p1 <= 0){
        cout << x2 << " " << y2;
        exit(0);
    }
    if (p2 > n){
        cout << x1 << " " << y1;
        exit(0);
    }

    if (abs(x - x1) < abs(x - x2)){
        cout << x1 << " " << y1;
    }
    else{
        cout << x2 << " " << y2;
    }
}
