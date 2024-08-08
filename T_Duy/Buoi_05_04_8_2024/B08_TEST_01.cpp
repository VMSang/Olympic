#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // Sắp xếp các số
    std::sort(a.begin(), a.end());

    // Giá trị nhỏ nhất không thể đạt được ban đầu là 1
    long long smallest_non_representable = 1;

    for (int i = 0; i < n; ++i) {
        //khi một số đã vượt quá thì không bao giờ đạt được
        if (a[i] > smallest_non_representable) {
            break;  // Nếu số hiện tại lớn hơn giá trị nhỏ nhất không thể đạt được, dừng lại
        }
        smallest_non_representable += a[i];  // Cập nhật giá trị nhỏ nhất không thể đạt được
    }

    std::cout << smallest_non_representable << "\n";

    return 0;
}
