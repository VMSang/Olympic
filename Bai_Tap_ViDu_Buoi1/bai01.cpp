// #include <bits/stdc++.h>
// using namespace std;

// vector<int> soHoanChinh;

// int sinh(int n) {
//     int Max = 0;
//     for (int i = 2; i <= n; i++) {
//         int dem = 2; // 1 va chinh no
//         int sum = 1; //mot luon la uoc cua cac so
//         //chi can duyet den can2 cua i, sau do cong doi uoc cua j
//         int sqrt_i = sqrt(i);
//         for (int j = 2; j <= sqrt_i; j++) {
//             if (i % j == 0) {
//                 sum += j;
//                 dem++;
//                 if (i != i / j) {
//                     sum += i / j;
//                     dem++;
//                 }
//             }
//         }
//         Max = max(Max, dem);
//         if (sum == i) soHoanChinh.push_back(i);
//     }
//     return Max;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n;
//     cin >> n;
//     cout<<sinh(n)<<endl;
//     for (int x : soHoanChinh) {
//         cout << x << " ";
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n < 2) return false;
    if(n == 2 || n ==3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i=5; i*i<=n; i+=6){
        if(n%i == 0 || n%(i+2) == 0) return false;
    } 
    return true;
}

vector<long long> v;
//neu p la snt va 2^p - 1 la snt thi 2^(p-1) * 2^p - 1 la so hoan hao
void soHoanHao(int n){
    for(int p=2; p<=32; p++){
        if(isPrime(p)){
            long long tmp = (1LL << p) - 1;
            if(tmp > n) break;
            if(isPrime(tmp)){
                long long res = (1LL << p - 1) * tmp;
                if(res > n) break;
                v.push_back(res);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    soHoanHao(n);
    for(long long x : v){
        cout<<x<<" ";
    }


    return 0;
}

