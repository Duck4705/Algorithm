#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int count_9_uoc(int n) {
    int count = 0;
    vector<int> prime_array;
    int n_tmp = sqrt(n);

    // Khởi tạo mảng đánh dấu nguyên tố
    vector<bool> is_prime(n_tmp + 1, true);

    // Sàng lọc số nguyên tố (Sàng Eratosthenes)
    for (int p = 2; p <= n_tmp; ++p) {
        if (is_prime[p]) {
            prime_array.push_back(p);
            for (int i = p * p; i <= n_tmp; i += p) {
                is_prime[i] = false;
            }
        }
    }

    // Đếm các số có dạng p^2 * q^2
    for (int i = 0; i < prime_array.size(); ++i) {
        for (int j = i + 1; j < prime_array.size(); ++j) {
            if (pow(prime_array[i], 2) * pow(prime_array[j], 2) <= n) {
                count++;
            } else {
                break;
            }
        }
    }

    // Đếm các số có dạng p^8
    for (int i = 0; i < prime_array.size(); ++i) {
        if (pow(prime_array[i], 8) <= n) {
            count++;
        } else {
            break;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    cout << count_9_uoc(n);
    return 0;
}
