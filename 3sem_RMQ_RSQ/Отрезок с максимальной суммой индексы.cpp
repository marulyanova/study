#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int> m(n + 1);
    vector<int> c(n + 1);
    c[0] = 0;
    m[0] = 0;
    int maxsum = -10000000, ind;
    for (int i = 1; i < n + 1; i++){

        if (m[i - 1] + v[i - 1] > v[i - 1]){

            m[i] = m[i - 1] + v[i - 1];
            c[i] = 1;
        }
        else{
            m[i] = v[i - 1];
            c[i] = 0;
        }
        if (m[i] > maxsum){
                maxsum = m[i];
                ind = i;
            }
    }

    int l = ind;
    while (c[l] != 0){
        l--;
    }
    cout << l << " " << ind << " " << maxsum;
}

