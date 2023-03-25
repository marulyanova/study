#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    vector<long long> p(200, 0);
    long long maxx = 0;
    while(getline(cin, s)){
        for (long long i = 0; i < s.size(); i++){
            if (!(isblank(s[i]))){
                p[s[i] - 0]++;
                maxx = max(maxx, p[s[i] - 0]);
            }
        }
    }
    long long countt = 0;
    for (auto i : p){
        if (i){
           countt++;
        }
    }

    vector<vector<long long>> m(maxx, vector<long long> (countt, 0));
    long long y = 0;
    for (long long i = 0; i < p.size(); i++){
        if (p[i] > 0){
            long long j = 0;
            while (j < p[i]){
                m[j][y] = 1;
                j++;
            }
            y++;
        }
    }

    for(long long i = m.size() - 1; i >= 0; i--){
        for(long long j = 0; j < m[i].size(); j++){
            if (m[i][j] == 0){
                cout << " ";
            }
            else{
                cout << "#";
            }
        }
        cout << endl;
    }

    for (long long i = 0; i < p.size(); i++){
        if (p[i] > 0){
            cout << char(i);
        }
    }
}
