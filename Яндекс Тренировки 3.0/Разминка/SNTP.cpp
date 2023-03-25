#include<bits/stdc++.h>

using namespace std;

int main(){

    string s, k;
	vector<vector<int>> t(3, vector<int> ());
	for (int i = 0; i < 3; i++){
        cin >> s;
        k = "";
        int j = 0;
        while (j < s.size()){

            while (isdigit(s[j]) && j < s.size()){
                k += s[j];
                j++;
            }
            int c = stoi(k);
            t[i].push_back(c);
            k = "";
            j++;
        }
	}

	/*for (int i = 0; i < t.size(); i++){
        for (int j = 0; j < t[i].size(); j++){
            cout << t[i][j] << " ";
        }
        cout << endl;
	}*/

    int a, b, c;
	a = t[0][0] * 3600 + t[0][1] * 60 + t[0][2];
	b = t[1][0] * 3600 + t[1][1] * 60 + t[1][2];
	c = t[2][0] * 3600 + t[2][1] * 60 + t[2][2];

	if (c < a){
        c += 86400;
	}
	b += (c - a) / 2 + (c - a) % 2;

	if (b > 86400) {
		b -= 86400;
	}

    int p, q;
	p = b / 3600;
	b -= p * 3600;
	q = b / 60;
	b -= q * 60;

	if (p < 10){
        cout << 0;
	}
	cout << p << ':';
	if (q < 10){
        cout << 0;
	}
	cout << q << ':';
	if (b < 10){
        cout << 0;
	}
	cout << b;
}
