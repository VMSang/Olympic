#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int a[maxn], n;
int t[4*maxn];

//t[v] = tong tat ca cac phan tu tu l den r
void build(int v, int l, int r){
	if(l == r){
		t[v] = a[l];
	} else {
		int mid = (l+r)/2;
		build(2*v, l, mid);
		build(2*v + 1, mid + 1, r);
		t[v] = t[2*v] + t[2*v + 1];
	}
}

//query O(logN) , mang cong don (O(1))
int sum(int v, int tl, int tr, int l, int r){
	if(l>r) return 0; //doan rong
	if(l == tl && r == tr) return t[v];
	else {
		int tm = (tl + tr)/2;
		return sum(2*v, tl, tm, l, min(tm, r)) + 
				sum(2*v+1, tm+1, tr, max(tm + 1, l), r);
	}
}

//lay min trong doan l, r
int get(int v, int tl, int tr, int l, int r) {
    // Đoạn [l, r] không giao với đoạn [tl, tr], ta bỏ qua đoạn này
    if (tl > r || tr < l) {
        return INT_MAX; // Trả về giá trị "vô cùng" để không ảnh hưởng đến min
    }
    // Đoạn [tl, tr] nằm hoàn toàn trong đoạn [l, r] mà ta đang truy vấn
    if (tl >= l && tr <= r) {
        return t[v]; 
    }
    // Gọi đệ quy với các nút con của nút v
    int tm = (tl + tr) / 2;
    int get1 = get(2 * v, tl, tm, l, r);
    int get2 = get(2 * v + 1, tm + 1, tr, l, r);
    // Trả ra giá trị nhỏ nhất theo 2 nút con
    return min(get1, get2); //đổi thành max nếu muốn tìm max
}


//update (O(logN)) : a[pos] = value
void update(int v, int l, int r, int pos, int value){
	if(l == r){
		t[v] = value;
	} else {
		int mid = (l+r)/2;
		if(pos <= mid){
			update(2*v, l, mid, pos, value);
		} else {
			update(2*v+1, mid+1, r, pos, value);
		}
	}
}

int main() {    
 	cin>>n;
 	vector<int> v(n);
 	for(int i=0; i<n; i++){
 		cin>>a[i];
 	}
 	build(1, 0, n-1);
 	for(int i=1; i<2*n; i++){
 		cout<<t[i]<<" ";
 	}
 	cout << endl << "sum = " << sum(1, 0, n-1, 2, 3) <<endl;

 	update(1, 0, n-1, 5, 10);
 	for(int i=1; i<2*n; i++){
 		cout<<t[i]<<" ";
 	}

 	cout << endl << "min = " << get(1, 0, n-1, 1, 3);
    return 0;
}
