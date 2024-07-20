#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000;
int n, m, MinL;
vector<int> Dau(MAXN), Cuoi(MAXN), W(MAXN);
vector<int> DauT(MAXN), CuoiT(MAXN), Father(MAXN);
bool Connect;

void Nhapdl() {
    string fname;
    cout << "Cho Tên file dữ liệu: ";
    cin >> fname;
    ifstream f(fname);
    f >> n >> m;
    for (int i = 0; i < m; i++) {
        f >> Dau[i] >> Cuoi[i] >> W[i];
    }
    f.close();
}

void Indulieu() {
    cout << "Số đỉnh: " << n << ", Số cạnh: " << m << endl;
    cout << " Đỉnh đầu  Đỉnh cuối  Độ dài" << endl;
    for (int i = 0; i < m; i++) {
        cout << setw(4) << Dau[i] << setw(10) << Cuoi[i] << setw(12) << W[i] << endl;
    }
}

void Heap(int First, int Last) {
    int j = First;
    while (j <= Last / 2) {
        int k = 2 * j;
        if (k < Last && W[k + 1] < W[k]) k++;
        if (W[k] < W[j]) {
            swap(Dau[j], Dau[k]);
            swap(Cuoi[j], Cuoi[k]);
            swap(W[j], W[k]);
            j = k;
        } else {
            break;
        }
    }
}

int Find(int i) {
    int Tro = i;
    while (Father[Tro] > 0) {
        Tro = Father[Tro];
    }
    return Tro;
}

void Union(int i, int j) {
    int X = Father[i] + Father[j];
    if (Father[i] > Father[j]) {
        Father[i] = j;
        Father[j] = X;
    } else {
        Father[j] = i;
        Father[i] = X;
    }
}

void Kruskal() {
    for (int i = 1; i <= n; i++) {
        Father[i] = -1;
    }
    for (int i = m / 2; i >= 1; i--) {
        Heap(i, m);
    }

    int Last = m;
    int Ncanh = 0;
    int Ndinh = 0;
    MinL = 0;
    Connect = true;

    while (Ndinh < n - 1 && Ncanh < m) {
        Ncanh++;
        int u = Dau[1], v = Cuoi[1];
        int rl = Find(u), r2 = Find(v);

        if (rl != r2) {
            Ndinh++;
            Union(rl, r2);
            DauT[Ndinh] = u;
            CuoiT[Ndinh] = v;
            MinL += W[1];
        }

        Dau[1] = Dau[Last];
        Cuoi[1] = Cuoi[Last];
        W[1] = W[Last];
        Last--;
        Heap(1, Last);
    }

    if (Ndinh < n - 1) {
        Connect = false;
    }
}

void Inketqua() {
    cout << "Kết quả tính toán" << endl;
    cout << "Độ dài của cây khung nhỏ nhất: " << MinL << endl;
    cout << "Các cạnh của cây khung nhỏ nhất:" << endl;
    for (int i = 1; i < n; i++) {
        cout << setw(2) << DauT[i] << " - " << setw(2) << CuoiT[i] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Nhapdl();
    Indulieu();
    Kruskal();
    if (Connect) {
        Inketqua();
    } else {
        cout << "Đồ thị không liên thông" << endl;
    }

    return 0;
}
