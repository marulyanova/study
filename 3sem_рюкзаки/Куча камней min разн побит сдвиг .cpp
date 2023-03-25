#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> ves(n);
    for (int i = 0; i < n; i++){
        cin >> ves[i];
    }

    int res = 100000 * 3;
    for (int i = 0; i < (1 << n); i++){
        bitset<21> b = i;
        cout << b << endl;
        int s0 = 0, s1 = 0;

        for(int j = 0; j < n; j++){
            if (b[j] == 0){
                s0 += ves[j];
            }
            else{
                s1 += ves[j];
            }
        }
        res = min(res, abs(s1 - s0));
    }
    cout << res;
}