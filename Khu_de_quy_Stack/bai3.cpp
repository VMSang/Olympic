#include <iostream>
using namespace std;

void printCombination(int arr[], int n, int r, int index, int data[], int i, int combinations[], int& count) {
    // Base case: Nếu số phần tử còn lại bằng 0, nghĩa là đã chọn đủ r phần tử
    if (r == 0) {
        // Lưu tổ hợp vào mảng combinations
        for (int j = 0; j < i; j++)
            combinations[count * n + j] = data[j];
        count++;
        return;
    }

    // Nếu số phần tử còn lại nhỏ hơn r, nghĩa là không đủ để chọn nữa
    if (n-index+1 < r)
        return;

    // Gọi đệ quy với hai trường hợp:
    // 1. Chọn phần tử hiện tại
    data[i] = arr[index];
    printCombination(arr, n, r-1, index+1, data, i+1, combinations, count);

    // 2. Không chọn phần tử hiện tại
    printCombination(arr, n, r, index+1, data, i, combinations, count);
}

int main() {
    int n, m;
    cout << "Nhap n va m: ";
    cin >> n >> m;

    int arr[n]; //so luong vdv
    for (int i = 0; i < n; i++) //đánh số cho vận động viên
        arr[i] = i+1;

    int data[m]; //mảng lưu các phần tử đã chọn
    int combinations[n * (n-m+1)]; //Mảng lưu trữ tất cả các tổ hợp 
    int count = 0; //đếm tổ hợp đã tìm được

    printCombination(arr, n, m, 0, data, 0, combinations, count);

    // In ra các phương án
    for (int i = 0; i < count; i++) {
        cout << i+1 << ". ";
        for (int j = 0; j < m; j++)
            cout << combinations[i * n + j] << " ";
        cout << endl;
    }

    return 0;
}