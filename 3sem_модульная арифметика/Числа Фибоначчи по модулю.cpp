#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;
    long long e = 1e6 + 3;

    vector<long long> fib(n + 1);
    fib[0] = 1;
    fib[1] = 1;
    for (long long i = 2; i <= n; i++){
        fib[i] = (fib[i - 2] + fib[i - 1]) % e;
    }
    cout << fib[n] % e;
}