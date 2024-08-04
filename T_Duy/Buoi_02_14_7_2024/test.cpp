#include <bits/stdc++.h>
using namespace std;

const int maxN = 300001;
int parent[maxN], sz[maxN], pw[maxN];
map<long long, long long> mp;

void make_set(){
    for(int i=1; i<=maxN; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int find_set(int u){
    if(u == parent[u])
        return u;
    return parent[u] = find_set(parent[u]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);

    if(a != b){
        if(sz[a] > sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    return 0;
}