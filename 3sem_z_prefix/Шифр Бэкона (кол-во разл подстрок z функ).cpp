#include <bits/stdc++.h>

using namespace std;

int Zfunc(string s){

    vector<int> v(s.size(), 0);
    int l = 0, r = 0, maxx = 0;

    for (int i = 1; i < s.size(); i++){
        if (i <= r){
            v[i] = min(v[i - l], r - i + 1);
        }
        while (s[v[i] + i] == s[v[i]] && v[i] + i < s.size()){
            v[i]++;
            maxx = max(maxx, v[i]);
        }
        if (i + v[i] - 1 > r){
            l = i;
            r = v[i] + i - 1;
        }
    }
    return maxx;
}

int main(){

    string s, k = "";
    cin >> s;
    int countt = 0;

    for (int i = 0; i < s.size(); i++){
        k = s[i] + k;
        countt += k.size() - Zfunc(k);
    }
    cout << countt;
}
