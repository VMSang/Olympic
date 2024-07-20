#include <bits/stdc++.h>
using namespace std;

void nhap(int a[], int i) {
    if (i < 0)
        return;
    nhap(a, i - 1);
    cin >> a[i];
}

void xuat(int a[], int i) {
    if (i < 0)
        return;
    xuat(a, i - 1);
    cout << a[i] << " ";
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int a[n];
    nhap(a, n - 1);
    xuat(a, n - 1);

    

    return 0;
}