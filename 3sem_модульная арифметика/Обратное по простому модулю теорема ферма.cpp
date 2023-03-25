#include <bits/stdc++.h>

using namespace std;

long long e = 1e9 + 9;

long long power(long long a, long long n){

    if (n == 0){
        return 1;
    }
    if (n % 2 == 0){
        return power(a * a % e, n / 2);
    }
    else{
        return a * power(a, n - 1) % e;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        long long a;
        cin >> a;
        cout << power(a, 1e9 + 7) << endl;
    }
}