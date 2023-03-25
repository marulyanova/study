#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k, q;
    cin >> n >> m >> k;

    long long A[n + 1][m + 1][k + 1];
    long long b;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int z = 1; z <= k; z++){
                cin >> b;
                A[i][j][z] = A[i - 1][j][z] +A[i][j - 1][z] + A[i][j][z - 1]
                - A[i][j - 1][z - 1] - A[i - 1][j][z - 1] - A[i - 1][j - 1][z] + A[i - 1][j - 1][z - 1] + b;
            }
        }
    }

    cin >> q;
    for (int i = 0; i < q; i++){
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        cout << A[x2][y2][z2] - A[x1 - 1][y2][z2] - A[x2][y1 - 1][z2] - A[x2][y2][z1 - 1]
        + A[x2][y1 - 1][z1 - 1] + A[x1 - 1][y2][z1 - 1] + A[x1 - 1][y1 - 1][z2] - A[x1 - 1][y1 - 1][z1 - 1] << endl;
    }
}
