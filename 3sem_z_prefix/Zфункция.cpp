#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string s;
    std::cin >> s;

    std::vector<int> v(s.size(), 0);
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

    v[0] = s.size();
    for (auto i : v){
        std::cout << i << " ";
    }
}
