#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> v(s.size(), 0), length(s.size());

    for (int i = 0; i < s.size(); i++){
        length[i] = s.size() - i;
    }

    int l = 0, r = 0;
    for (int i = 1; i < s.size(); i++){
        if (i <= r){
            v[i] = std::min(v[i - l], r - i + 1);
        }
        while (s[v[i] + i] == s[v[i]] && v[i] + i < s.size()){
            v[i]++;
        }
        if (i + v[i] - 1 > r){
            l = i;
            r = v[i] + i - 1;
        }
    }

    for (int i = 0; i < s.size(); i++){

        if (v[i] == length[i]){
            cout << i;
            exit(0);
        }
    }
    cout << s.size();

}

