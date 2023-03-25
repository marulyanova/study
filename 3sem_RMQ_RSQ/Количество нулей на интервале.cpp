#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, x, y;
    cin >> n;
    vector<int> check_zero(n + 1);
    check_zero[0] = 0;

    for (int i = 1; i <= n; i++){
        cin >> k;

        if (k == 0){
            check_zero[i] = check_zero[i - 1] + 1;
        }
        else{
            check_zero[i] = check_zero[i - 1];
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> x >> y;
        cout << check_zero[y] - check_zero[x - 1] << " ";
    }
}

