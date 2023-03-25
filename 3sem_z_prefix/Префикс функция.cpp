#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<int> v(s.size(), 0);
    for (int i = 1; i < s.size(); i++){

        int cur = v[i - 1];
        while (s[i] != s[cur] && cur > 0){
            cur = v[cur - 1];
        }

        if (s[i] == s[cur])
            v[i] = cur + 1;
    }
    for (auto i : v){
        cout << i << " ";
    }
}
