#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++){
        cin >> v[i];
    }

    map<int, pair<long long, int>> a;
    long long sum = 0;
    long long res = -(pow(10, 18));
    int l, r;
    for (int i = 0; i < n; i++){

        if (a.find(v[i]) != a.end()){
            if (a[v[i]].first > sum){
                a[v[i]] = {sum, i};
            }
        }
        else{
            a[v[i]] = {sum, i};
        }

        sum += v[i];
        if (res < sum - a[v[i]].first){
            l = a[v[i]].second;
            r = i;
        }
        res = max(res, sum - a[v[i]].first);
    }
    cout << res << endl << l + 1 << " " << r + 1;
}
