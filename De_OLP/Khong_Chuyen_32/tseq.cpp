#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

using namespace std;

struct itnode {
    int cnt;
    long long totalx, totaly;
    itnode *left, *right;
    
    itnode() : cnt(0), totalx(0), totaly(0), left(nullptr), right(nullptr) {}
};

struct element {
    int cnt;
    long long totalx, totaly;
};

int n, m;
int b[100005];
vector<pair<int, int>> list1, list2;
vector<itnode*> version1, version2;
vector<long long> prefixSum1, prefixSum2;

void build(itnode*& root, int L, int R) {
    root = new itnode();
    if (L == R) return;
    int mid = (L + R) / 2;
    build(root->left, L, mid);
    build(root->right, mid + 1, R);
}

void update(itnode*& root, int L, int R, int position, const int& value) {
    if (L > position || position > R) return;
    itnode* tmp = new itnode(*root);
    if (L == R) {
        tmp->cnt++;
        tmp->totalx += value;
        tmp->totaly += position;
        root = tmp;
        return;
    }
    int mid = (L + R) / 2;
    if (position <= mid)
        update(tmp->left, L, mid, position, value);
    else
        update(tmp->right, mid + 1, R, position, value);
    tmp->cnt = tmp->left->cnt + tmp->right->cnt;
    tmp->totalx = tmp->left->totalx + tmp->right->totalx;
    tmp->totaly = tmp->left->totaly + tmp->right->totaly;
    root = tmp;
}

element get(itnode* root, int L, int R, int l, int r) {
    if (L > r || l > R) return {0, 0, 0};
    if (l <= L && R <= r) return {root->cnt, root->totalx, root->totaly};
    int mid = (L + R) / 2;
    element eLeft = get(root->left, L, mid, l, r);
    element eRight = get(root->right, mid + 1, R, l, r);
    return {eLeft.cnt + eRight.cnt, eLeft.totalx + eRight.totalx, eLeft.totaly + eRight.totaly};
}

void process(vector<pair<int, int>>& a1, vector<pair<int, int>>& a2) {
    int n1 = a1.size();
    sort(a1.begin(), a1.end());
    prefixSum1.resize(n1 + 1);
    for (int i = 1; i <= n1; i++)
        prefixSum1[i] = prefixSum1[i - 1] + a1[i - 1].second - a1[i - 1].first;

    itnode* root;
    version1.push_back(root);
    build(version1.back(), 0, m - 1);
    for (int i = 1; i <= n1; i++) {
        itnode* node = version1.back();
        update(node, 0, m - 1, a1[i - 1].second, a1[i - 1].first);
        version1.push_back(node);
    }

    int n2 = a2.size();
    sort(a2.begin(), a2.end());
    prefixSum2.resize(n2 + 1);
    for (int i = 1; i <= n2; i++)
        prefixSum2[i] = prefixSum2[i - 1] + a2[i - 1].second;

    version2.push_back(root);
    build(version2.back(), 0, m - 1);
    for (int i = n2; i >= 1; i--) {
        itnode* node = version2.back();
        update(node, 0, m - 1, a2[i - 1].second, a2[i - 1].first);
        version2.push_back(node);
    }
}

long long solve1(const int& X, const vector<pair<int, int>>& a) {
    long long ret = 0;
    int n = a.size();
    int p = upper_bound(a.begin(), a.end(), make_pair(X, numeric_limits<int>::max())) - a.begin();
    ret += prefixSum1[n] - prefixSum1[p];
    if (p > 0) {
        element value = get(version1[p], 0, m - 1, X, m - 1);
        ret += value.totaly - (long long)value.cnt * (X - 1);
        value = get(version1[p], 0, m - 1, 0, X - 1);
        ret += value.totaly - value.totalx;
    }
    return ret;
}

long long solve2(const int& X, const vector<pair<int, int>>& a) {
    long long ret = 0;
    int n = a.size();
    int p = upper_bound(a.begin(), a.end(), make_pair(X, numeric_limits<int>::max())) - a.begin();
    ret += (long long)p * (m - X + 1) + prefixSum2[p];
    element value = get(version2[n - p], 0, m - 1, X, m - 1);
    ret += value.totaly + (long long)value.cnt * (-X + 1);
    value = get(version2[n - p], 0, m - 1, 0, X - 1);
    ret += (long long)value.cnt * m - value.totalx + value.totaly;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    for (int i = 1; i < n; i++) {
        if (b[i] < b[i + 1])
            list1.emplace_back(b[i], b[i + 1]);
        else if (b[i] > b[i + 1])
            list2.emplace_back(b[i], b[i + 1]);
    }

    process(list1, list2);

    long long ans = numeric_limits<long long>::max();
    for (int i = 1; i <= n; i++) {
        int X = b[i];
        long long ret = solve1(X, list1) + solve2(X, list2);
        ans = min(ans, ret);
    }

    cout << ans;
    return 0;
}