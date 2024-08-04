#include <iostream>
#include <vector>
using namespace std;

// Hàm tính chiều dài của dãy S(k)
long long length(int k) {
    if (k == 0) return 3;
    return 2 * length(k - 1) + (k + 3);
}

// Tính mảng độ dài dãy S(k) cho đến khi độ dài đủ lớn
void calculateLengths(vector<long long>& lengths, long long maxN) {
    int k = 0;
    while (true) {
        long long len = length(k);
        if (len >= maxN) {
            lengths.push_back(len);
            break;
        }
        lengths.push_back(len);
        ++k;
    }
}

// Hàm tìm ký tự tại vị trí N trong dãy S(k)
char findCharacter(long long N, int k) {
    if (k == 0) {
        if (N == 1) return 'b';
        else return 'o';
    }
    long long lenPrev = length(k - 1);
    if (N <= lenPrev) {
        return findCharacter(N, k - 1);
    } else if (N <= lenPrev + k + 3) {
        if (N == lenPrev + 1) return 'b';
        else return 'o';
    } else {
        return findCharacter(N - lenPrev - (k + 3), k - 1);
    }
}

// Hàm tìm chỉ số k trong mảng lengths bằng tìm kiếm nhị phân
int findK(const vector<long long>& lengths, long long N) {
    int left = 0, right = lengths.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (lengths[mid] < N) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    int T;
    cin >> T;
    vector<long long> queries(T);
    long long maxN = 0;
    for (int i = 0; i < T; ++i) {
        cin >> queries[i];
        maxN = max(maxN, queries[i]);
    }

    vector<long long> lengths;
    calculateLengths(lengths, maxN);

    for (int i = 0; i < T; ++i) {
        long long N = queries[i];
        int k = findK(lengths, N);
        cout << findCharacter(N, k) << endl;
    }

    return 0;
}
