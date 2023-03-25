#include <bits/stdc++.h>

using namespace std;

vector<long long> lcp;

vector<long long> LCP(vector<int>& v, vector<int>& c, vector<int>& p){\

    int n = v.size();
    int cur_lcp = 0;
    vector<long long> lcp(n);
    for (int i = 0; i < n; ++i){

        if (c[i] == n - 1)
            continue;

        int x = p[c[i] + 1];
        while (max(i, x) + cur_lcp < n && v[i + cur_lcp] == v[x + cur_lcp])
            cur_lcp++;

        lcp[c[i]] = cur_lcp;
        cur_lcp = max(0, cur_lcp - 1);
    }
    return lcp;
}

vector<int> sufmas(string s){

    s += '$';
    int n = s.length(), cnt = 0, cls = 0;
    vector<int> v(s.begin(), s.end());
    vector<int> c(n), p(n);
    map<int, vector<int>> t;

    for (int i = 0; i < n; ++i)
        t[s[i]].push_back(i);

    for (auto x : t) {
        for (int u : x.second) {
            c[u] = cls;
            p[cnt++] = u;
        }
        cls++;
    }

    for (int l = 1; cls < n; ++l) {
        vector<vector<int>> a(cls);
        vector<int> _c(n);
        int d = (1 << l) / 2;
        int _cls = 0;
        cnt = 0;

        for (int i = 0; i < n; ++i) {
            int k = (p[i] - d + n) % n;
            a[c[k]].push_back(k);
        }
        for (int i = 0; i < cls; ++i) {
            for (int j = 0; j < a[i].size(); ++j) {

                if (j == 0 || c[(a[i][j] + d) % n] != c[(a[i][j - 1] + d) % n])
                    _cls++;
                    _c[a[i][j]] = _cls - 1;
                    p[cnt++] = a[i][j];
                }
            }
            c = _c;
            cls = _cls;
        }
    lcp = LCP(v, c, p);
    return vector<int>(p.begin() + 1, p.end());
}

int main(){

    string s;
    cin >> s;
    int n = s.length();

    vector<int> ss = sufmas(s);
    long long res = 0;
    for (int i = 0; i < n; i++){
        res += n - ss[i];
    }
    for (int i = 0; i < n; i++){
        res -= lcp[i];
    }
    cout << res;
}
