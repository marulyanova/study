#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct Node {

    T value = 0;
    Node<T> *l_child = nullptr, *r_child = nullptr;
    int l = 0, r = 0;

    Node<T>(const int& l_, const int& r_)
        : l(l_)
        , r(r_) {}
};

template<typename T>
struct Tree{

    Node<T>* root = nullptr;
    std::vector<T> v;
    Tree(std::vector<T>& v) {
        this->v = v;
        root = new Node<T>(0, v.size());
        build(root);
    }

    void build(Node<T>* cur_v) {
        if (cur_v->l + 1 == cur_v->r) {
            cur_v->value = v[cur_v->l];
            return;
        }
        int m = (cur_v->l + cur_v->r) / 2;
        cur_v->l_child = new Node<T>(cur_v->l, m);
        cur_v->r_child = new Node<T>(m, cur_v->r);
        build(cur_v->l_child);
        build(cur_v->r_child);

        cur_v->value = max(cur_v->l_child->value, cur_v->r_child->value);
    }


    T get(Node<T>* cur_v, int q_l, int q_r) {
        int l = cur_v->l;
        int r = cur_v->r;
        if (q_l <= l && r <= q_r) {
            return cur_v->value;
        }
        else if (r <= q_l || q_r <= l) {
            return 0;
        }
        else {
            return max(get(cur_v->l_child, q_l, q_r), get(cur_v->r_child, q_l, q_r));
        }
    }

    T get(int q_l, int q_r) {
        return get(root, q_l, q_r);
    }

    void update(Node<T>* cur_v, const int& q_l, const int& q_r, const int& val){

        if (cur_v == nullptr){
            return;
        }

        int l = cur_v->l;
        int r = cur_v->r;
        if (q_l == l && r == q_r){
            cur_v->value = val;
            return;
        }
        else if (r <= q_l || q_r <= l){
            return;
        }
        else{
            update
            (cur_v->l_child, q_l, q_r, val);
            update(cur_v->r_child, q_l, q_r, val);

            if (cur_v->l_child == nullptr) {
                cur_v->value = cur_v->r_child->value;
            }
            else if (cur_v->r_child == nullptr) {
                cur_v->value = cur_v->l_child->value;
            }
            else {
                cur_v->value = max(cur_v->l_child->value, cur_v->r_child->value);
            }
        }
    }

    void update(const int& q_l, const int& q_r, const int& val) {
        update(root, q_l, q_r, val);
    }
};

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, k;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    Tree<int> tree(v);

    cin >> k;
    for (int i = 0; i < k; i++) {

        char a;
        cin >> a;
        if (a == 's'){
            int x, y;
            cin >> x >> y;
            cout << tree.get(x - 1, y) << " ";
        }
        else{
            int p, v;
            cin >> p >> v;
            tree.update(p - 1, p, v);
        }
    }
}
