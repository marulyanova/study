#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

double power(double a, int n){

    if (n == 0){
        return 1;
    }
    if (n % 2 == 0){
        return power(a * a, n / 2);
    }
    else{
        return a * power(a, n - 1);
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    double a;
    int n;
    cin >> a >> n;

    cout << power(a, n);
}