#include<bits/stdc++.h>

using namespace std;

int main(){

    int s, n;
    cin >> s >> n;
    bitset<10001> b = 1;

    for(int i = 0; i < n; i++){
        int ves;
        cin >> ves;
        b = (b << ves) | b;
    }

    for (int i = s; i >= 0; i--){
        if (b[i] == 1){
            cout << i;
            break;
        }
    }
}