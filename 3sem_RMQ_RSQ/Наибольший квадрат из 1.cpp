#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

	vector<vector<int>> v(n, vector<int> (m));
	for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
        }
	}

	if (n == 1 && m == 1){
        cout << 1 << endl << 1 << " " << 1;
        exit(0);
    }

	int res = 0, x, y;
	for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){

            if (v[i][j] > 0){
                v[i][j] = min(v[i - 1][j - 1], min(v[i][j - 1], v[i - 1][j])) + 1;

                if (v[i][j] > res){
                    res = v[i][j];
                    x = i - res + 2;
                    y = j - res + 2;
                }
            }
        }
	}

	cout << res << endl << x << " " << y;

	/*for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << a[i][j];
        }
        cout << endl;
	}*/
}
