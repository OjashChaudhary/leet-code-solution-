class Solution {
public:
    struct Node {
        int prod = 1;
        int cnt[5] = {};
    };

    int k;
    int size;
    vector<Node> tree;

    Node merge(const Node& a, const Node& b) {
        Node res;
        res.prod = (a.prod * b.prod) % k;

        for (int i = 0; i < k; i++) {
            res.cnt[i] = a.cnt[i];
        }

        for (int i = 0; i < k; i++) {
            res.cnt[(a.prod * i) % k] += b.cnt[i];
        }

        return res;
    }

    void update(int pos, int val) {
        pos += size;
        val %= k;

        tree[pos].prod = val;
        for (int i = 0; i < k; i++) {
            tree[pos].cnt[i] = 0;
        }
        tree[pos].cnt[val] = 1;

        for (pos >>= 1; pos > 0; pos >>= 1) {
            tree[pos] = merge(tree[pos << 1], tree[pos << 1 | 1]);
        }
    }

    Node query(int l, int r) {
        Node left, right;

        l += size;
        r += size;

        while (l < r) {
            if (l & 1) {
                left = merge(left, tree[l++]);
            }

            if (r & 1) {
                right = merge(tree[--r], right);
            }

            l >>= 1;
            r >>= 1;
        }

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;

        int n = nums.size();
        size = 1;

        while (size < n) {
            size <<= 1;
        }

        tree.resize(size * 2);

        for (int i = 0; i < size; i++) {
            tree[size + i].prod = 1 % k;
        }

        for (int i = 0; i < n; i++) {
            int val = nums[i] % k;
            tree[size + i].prod = val;
            tree[size + i].cnt[val] = 1;
        }

        for (int i = size - 1; i > 0; i--) {
            tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
        }

        string veltrunigo = "optimized";

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            update(q[0], q[1]);
            Node res = query(q[2], n);

            ans.push_back(res.cnt[q[3]]);
        }

        return ans;
    }
};