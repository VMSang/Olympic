#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 300001;

vector<long long> parent(MAX_N);
vector<long long> power(MAX_N);
map<long long, long long> mp;
vector<long long> sz(MAX_N, 1);

void make_set(int q) {
    for (int i = 1; i <= q; i++) {
        parent[i] = i;
    }
}

long long find_set(long long v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

long long union_set(long long a, long long b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
    }

    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;
    int cntMonster = 1;
    make_set(q);

    while (q--) {
        int event; cin >> event;
        if (event == 1) {
            long long pw; cin >> pw;
            power[cntMonster] = pw;

            auto iter = mp.find(pw);

            // nếu đã có: gốc sẽ là chỉ số của con quái đầu tiên có sức mạnh là pw
            if (iter != mp.end()){
                // cout<<"co "<<endl;
                parent[cntMonster] = iter->second;
            }
            else{
                 // cout<<"khong "<<endl;
                mp[pw] = cntMonster;
            }
            cntMonster++;
        } else if (event == 2) {
            long long u, v; cin >> u >> v;

            // kiểm tra đã tồn tại pw u chưa, nếu rồi:
            auto iter = mp.find(u);
            if (iter != mp.end()) {
                // lấy gốc của sức mạnh u
                long long rootU = iter->second;
                mp.erase(iter);
                // kiểm tra sức mạnh sau khi cập nhật đã tồn tại chưa
                // nếu rồi thì Union_set u và (u+v)
                auto haved = mp.find(u + v);
                if (haved != mp.end()) {
                    long long rootHaved = haved->second;
                    mp.erase(haved);
                    mp[u + v] = union_set(rootU, rootHaved);
                    power[mp[u + v]] = u + v;
                } else {
                    mp[u + v] = rootU;
                    power[rootU] = u + v;
                }
            }
        } else {
            long long u; cin >> u;
            // cout<<find_set(u)<<endl;
            cout << power[find_set(u)] << "\n";
        }
    }
    // for(int i=1; i<=10; i++){
    //     cout<<parent[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=1; i<=10; i++){
    //     cout<<power[i]<<" ";
    // }
    return 0;
}
