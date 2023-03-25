#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

struct query{

    int id = 0;
    int left = 0, right = 0;
    int ans = 0;
};

struct Mo{

    std::vector<int> v;
    std::vector<int> cnt;

    Mo(const std::vector<int>& v){
        this->v = v;
        cnt.resize(v.size());
    }

    int a = 0, b = -1, ans = 0;

    int get(query qu){

        int left = qu.left;
        int right = qu.right;
        while(a < left){

            cnt[v[a]]--;
            if (cnt[v[a]] == 0) ans--;
            a++;
        }

        while(a > left){
            a--;
            if (cnt[v[a]] == 0) ans++;
            cnt[v[a]]++;

        }
        while(b < right){
            b++;
            if (cnt[v[b]] == 0) ans++;
            cnt[v[b]]++;
        }
        while(b > right){
            cnt[v[b]]--;
            if (cnt[v[b]] == 0) ans--;
            b--;
        }
        return ans;
    }

};


int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n = 0, m = 0;
    std::cin >> n;
    std::vector<int> v(n);
    for(size_t i = 0; i < v.size(); ++i){
        std::cin >> v[i];
    }

    std::vector<int> sort_v = v;
    std::sort(sort_v.begin(), sort_v.end());
    for (size_t i = 0; i < v.size(); ++i){
        v[i] = int(lower_bound(sort_v.begin(), sort_v.end(), v[i]) - sort_v.begin());
    }

    std::cin >> m;
    std::vector<query> q(m);
    for(size_t i = 0; i < q.size(); ++i){

        q[i].id = i;
        std::cin >> q[i].left >> q[i].right;
        q[i].left--;
        q[i].right--;
    }

    Mo mo(v);
    std::sort(q.begin(), q.end(), [](const query &a, const query &b){
            if (a.left / 500 == b.left / 500){
                return a.right < b.right;
            }
            else{
                return a.left < b.left;
            }
        });

    for(size_t i = 0; i < q.size(); ++i){
        q[i].ans = mo.get(q[i]);
    }

    std::sort(q.begin(), q.end(), [](const query &a, const query &b){
            return a.id < b.id;
        });

    for(size_t i = 0; i < q.size(); ++i){
        std::cout << q[i].ans << '\n';
    }
}
