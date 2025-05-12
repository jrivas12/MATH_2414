#include <iostream>
#include <string>
#include <cmath>
using namespace std;

std::string convertToPassword(int num, int k, int n) {
    std::string result(n, '0');
    for (int i = n - 1; i >= 0; --i) {
        result[i] = '0' + (num % k);
        num /= k;
    }
    return result;
}

int main() {
    int k = 4; 
    int n = 3;
    std::string password = "203"; 

    int limit = std::pow(k, n);
    for (int i = 0; i < limit; ++i) {
        std::string guess = convertToPassword(i, k, n);
        if (guess == password) {
            std::cout << "Password found: " << guess << " at i = " << i << std::endl;
            break;
        }
    }
    return 0;
}
