#include <bits/stdc++.h>

using namespace std;

long long e = 1e6 + 7;

long long sum(long long a, long long b){

    return ((a % e) - (b % e)) % e;
}

long long multiply(long long a, long long b){

    return ((a % e) * (b % e)) % e;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long a, b;
    cin >> a >> b;

    long long x = (multiply(a, a) % e + e) % e;

    long long y = (multiply(b, b) % e + e) % e;

    long long k = (x % e - y % e) % e;
    k = (k % e + e) % e;

    cout << k;
}