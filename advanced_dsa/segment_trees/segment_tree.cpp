#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int n;
    vector<long long> tree; // long long for larger sums

    // Build tree recursively
    void build(vector<int>& arr, int node, int l, int r) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, node * 2, l, mid);
        build(arr, node * 2 + 1, mid + 1, r);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    // Update a single index
    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    // Query range sum [ql, qr]
    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;           // outside range
        if (ql <= l && r <= qr) return tree[node]; // completely inside
        int mid = (l + r) / 2;
        return query(node * 2, l, mid, ql, qr) +
               query(node * 2 + 1, mid + 1, r, ql, qr);
    }

public:
    // Constructor
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }

    // Public wrappers
    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    long long query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);

    cout << "Sum [1,3] = " << st.query(1, 3) << "\n"; // 3 + 5 + 7 = 15
    st.update(1, 10); // arr[1] = 10
    cout << "Sum [1,3] after update = " << st.query(1, 3) << "\n"; // 10 + 5 + 7 = 22
}
