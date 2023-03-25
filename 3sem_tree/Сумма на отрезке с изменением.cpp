#include <iostream>
#include <vector>

using namespace std;

//template <typename T>
struct Node{

    long long value = 0;
    Node *l_child = nullptr, *r_child = nullptr;
    long long l = 0, r = 0;

    Node(const int& l_, const int& r_)
        : l(l_)
        , r(r_) {}
};

//template<typename T>
struct Tree{

    Node* root = nullptr;
    std::vector<long long> v;
    Tree(std::vector<long long>& v) {
        this->v = v;
        root = new Node(0, v.size());
        build(root);
    }

    void build(Node* cur_v) {
        if (cur_v->l + 1 == cur_v->r) {
            cur_v->value = v[cur_v->l];
            return;
        }
        long long m = (cur_v->l + cur_v->r) / 2;
        cur_v->l_child = new Node(cur_v->l, m);
        cur_v->r_child = new Node(m, cur_v->r);
        build(cur_v->l_child);
        build(cur_v->r_child);

        cur_v->value = cur_v->l_child->value + cur_v->r_child->value;
    }


    long long get(Node* cur_v, long long q_l, long long q_r) {
        long long l = cur_v->l;
        long long r = cur_v->r;
        if (q_l <= l && r <= q_r) {
            return cur_v->value;
        }
        else if (r <= q_l || q_r <= l) {
            return 0;
        }
        else {
            return (get(cur_v->l_child, q_l, q_r) + get(cur_v->r_child, q_l, q_r));
        }
    }

    long long get(long long q_l, long long q_r) {
        return get(root, q_l, q_r);
    }

    void update(Node* cur_v, const long long& q_l, const long long& q_r, const long long& val){

        if (cur_v == nullptr){
            return;
        }

        long long l = cur_v->l;
        long long r = cur_v->r;
        if (q_l == l && r == q_r){
            cur_v->value = val;
            return;
        }
        else if (r <= q_l || q_r <= l){
            return;
        }
        else{
            update(cur_v->l_child, q_l, q_r, val);
            update(cur_v->r_child, q_l, q_r, val);

            cur_v->value = cur_v->l_child->value + cur_v->r_child->value;
        }
    }

    void update(const long long& q_l, const long long& q_r, const long long& val) {
        update(root, q_l, q_r, val);
    }
};

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    long long n, k;
    cin >> n;
    vector<long long> v(n, 0);
    for (long long i = 0; i < n; i++){
        cin >> v[i];
    }

    Tree tree(v);

    cin >> k;
    for (long long i = 0; i < k; i++) {

        char a;
        cin >> a;
        if (a == 's'){
            long long x, y;
            cin >> x >> y;
            cout << tree.get(x - 1, y) << " ";
        }
        else{
            long long p, v;
            cin >> p >> v;
            tree.update(p - 1, p, v);
        }
    }
}
