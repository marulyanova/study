#include<bits/stdc++.h>

using namespace std;

int n, k, m;

struct Node{
    int value = 0, add = 0;
    Node *l_child = nullptr, *r_child = nullptr;
    int l = 0, r = 0;

    Node(const int& l_, const int& r_)
            : l(l_)
            , r(r_) {}
};

struct Tree{
    Node *root = nullptr;
    vector<int> v;
    Tree(vector<int>& v){
        this->v = v;
        root = new Node(0, v.size());
        build(root);
    }

    void build(Node* cur_v){
        if(cur_v->l + 1 == cur_v->r){
            cur_v->value = v[cur_v->l];
            return;
        }
        int m = (cur_v->l + cur_v->r) / 2;
        cur_v->l_child = new Node(cur_v->l, m);
        cur_v->r_child = new Node(m, cur_v->r);
        build(cur_v->l_child);
        build(cur_v->r_child);

        cur_v->value = max(cur_v->l_child->value, cur_v->r_child->value);
    }

    void push(Node* cur_v) {
        if (cur_v->l_child != nullptr) {
            cur_v->l_child->add += cur_v->add;
            cur_v->r_child->add += cur_v->add;
        }
        cur_v->value += cur_v->add;
        cur_v->add = 0;
    }

    void add(Node* cur_v, int q_l, int q_r, int val) {
        push(cur_v);
        int l = cur_v->l;
        int r = cur_v->r;
        if (q_l <= l && r <= q_r) {
            cur_v->add += val;
            push(cur_v);
        }
        else if (r <= q_l || q_r <= l){
            return;
        }
        else {
            add(cur_v->l_child, q_l, q_r, val);
            add(cur_v->r_child, q_l, q_r, val);

            if (cur_v->l_child != nullptr && cur_v->r_child != nullptr) {
                cur_v->value = max(cur_v->l_child->value, cur_v->r_child->value);
            }
            else if (cur_v->l_child != nullptr) {
                cur_v->value = cur_v->l_child->value;
            }
            else if (cur_v->r_child != nullptr) {
                cur_v->value = cur_v->r_child->value;
            }
        }
    }

    void add(int q_l, int q_r, int val) {
        add(root, q_l, q_r, val);
    }

    int get(Node* cur_v, int q_l, int q_r){
        push(cur_v);
        int l = cur_v->l;
        int r = cur_v->r;
        if(q_l <= l && r <= q_r){
            return cur_v->value + cur_v->add;
        }
        else if(r <= q_l || q_r <= l){
            return 0;
        }
        else{
            return max(get(cur_v->l_child, q_l, q_r), get(cur_v->r_child, q_l, q_r));
        }
    }
    int get(int q_l, int q_r){
        return get(root, q_l, q_r);
    }
};

int main(){

    cin >> n >> k >> m;
    vector<int> v(n, 0);

    Tree tree(v);

    for (int i = 0; i < m; i++){

        int x, y;
        cin >> x >> y;
        if (tree.get(x, y) < k){
            cout << 1 << endl;
            tree.add(x, y, 1);
        }
        else {
            cout << 0 << endl;
        }
    }
}
